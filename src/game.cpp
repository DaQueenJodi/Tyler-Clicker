#include "Collision.hpp"
#include "ECS/Components.hpp"
#include "ECS/ECS.hpp"
#include "Game.hpp"
#include "TextureManager.hpp"
#include "Vector2D.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "Mouse.hpp"
#include "ShopFunctions.hpp"
#include "Colors.hpp"
SDL_Event Game::event;

SDL_Renderer *Game::renderer = nullptr;

int Game::screen_height = 0;
int Game::screen_width = 0;


std::vector<ColliderComponent*> Game::colliders;

Manager manager;
//cookie
auto &cookie(manager.addEntity());
//shop items
auto &add_multiply10(manager.addEntity());
auto &add_multiply5(manager.addEntity());
auto &add_multiply1(manager.addEntity());

auto &add_idle_15(manager.addEntity());
auto &add_idle_10(manager.addEntity());
auto &add_idle_5(manager.addEntity());
//idles
auto &idle_15(manager.addEntity());
auto &idle_10(manager.addEntity());
auto &idle_5(manager.addEntity());

//text boxes
auto &score_textbox(manager.addEntity());
auto &idles_textbox(manager.addEntity());

//menus
auto &shop_menu(manager.addEntity());

Game::Game()
{}
Game::~Game()
{}

//define groups
enum groupLabels : std::size_t
{
    groupClickables,
    groupBackgrounds,
    groupColliders,
    groupShopItems,
    groupIdles,
    groupText,
    groupMenus,
};

void Game::init(const char *title, int xpos, int ypos, int width, int height,
                bool fullscreen) {
                  //set screen width and height variables for later reference:
   screen_height = height;
   screen_width = width;
  
  int flags = 0;
  if (fullscreen) {
    flags = SDL_WINDOW_FULLSCREEN;
  }
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0) { 
    std::cout << "Subsystems initiated" << std::endl;

    window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

    if (window) {
      std::cout << "Window succesfully created!" << std::endl;
    }

    renderer = SDL_CreateRenderer(
        window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer) {
      SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
      std::cout << "Renderer succesfully created!" << std::endl;

      is_running = true;
    }




    if (TTF_Init() == 0)
    {
      std::cout << "TTF Initialized" << std::endl;
    }
    //shop items
    add_multiply1.addComponent<TransformComponent>(400, 400, 3);
    add_multiply1.addComponent<ButtonComponent>(100, "Multiplier +1!", ShopFunctions::add_multiplier, 1, Colors::Pink);
    add_multiply1.addGroup(groupShopItems);

    add_multiply5.addComponent<TransformComponent>(600, 400, 3);
    add_multiply5.addComponent<ButtonComponent>(700, "Multiplier +5!", ShopFunctions::add_multiplier, 5, Colors::Blue);
    add_multiply5.addGroup(groupShopItems);

    add_multiply10.addComponent<TransformComponent>(100, 400, 3);
    add_multiply10.addComponent<ButtonComponent>(1000, "Multiplier +10!",  ShopFunctions::add_multiplier, 10, Colors::Orange);
    add_multiply10.addGroup(groupShopItems);

    add_idle_5.addComponent<TransformComponent>(200, 800, 3);
    add_idle_5.addComponent<ButtonComponent>(3000, "earn 10 points every 5 seconds!", ShopFunctions::add_idle, ShopFunctions::Idle::IDLE_SEC::idle_5, Colors::Red);
    add_idle_5.addGroup(groupShopItems);

    add_idle_10.addComponent<TransformComponent>(300, 800, 3);
    add_idle_10.addComponent<ButtonComponent>(5000, "earn 40 points every 10 second!", ShopFunctions::add_idle, ShopFunctions::Idle::IDLE_SEC::idle_10, Colors::Green);
    add_idle_10.addGroup(groupShopItems);

    add_idle_15.addComponent<TransformComponent>(400, 800, 3);
    add_idle_15.addComponent<ButtonComponent>(7000, "earn 150 points every 15 seconds!", ShopFunctions::add_idle, ShopFunctions::Idle::IDLE_SEC::idle_15, Colors::Purple);
    add_idle_10.addGroup(groupShopItems);
    //cookie
    cookie.addComponent<TransformComponent>(100, 300, 2);
    cookie.addComponent<SpriteComponent>("res/gfx/player.png");
    cookie.addComponent<ColliderComponent>("cookie");
    cookie.addComponent<ClickableComponent>("cookie");
    cookie.addGroup(groupClickables);
    
    // idles
    idle_5.addComponent<IdleComponent>(ShopFunctions::Idle::IDLE_SEC::idle_5, 10);
    idle_5.addGroup(groupIdles);

    idle_10.addComponent<IdleComponent>(ShopFunctions::Idle::IDLE_SEC::idle_10, 30);
    idle_10.addGroup(groupIdles);

    idle_15.addComponent<IdleComponent>(ShopFunctions::Idle::IDLE_SEC::idle_15, 100);
    idle_15.addGroup(groupIdles);

    //text boxes

    score_textbox.addComponent<TextBoxComponent>(0, 0);
    score_textbox.addGroup(groupText);
 
    idles_textbox.addComponent<TextBoxComponent>(100, 0);
    idles_textbox.addGroup(groupText);

    //menus
    shop_menu.addComponent<MenuComponent>(manager.getGroup(groupShopItems), 0, 100);
    shop_menu.addGroup(groupMenus);
  } else {
    std::cout << "failed to run submodules, frick" << std::endl;
   is_running = false;
  }
}



auto& clickables(manager.getGroup(groupClickables));

auto& shopItems(manager.getGroup(groupShopItems));

auto& idles(manager.getGroup(groupIdles));

auto& text_boxes(manager.getGroup(groupText));

auto& menus(manager.getGroup(groupMenus));


void Game::handleEvents() {

  while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
        {
					is_running = false;
        }
        
        if (event.type == SDL_MOUSEBUTTONDOWN)
        {
         // std::cout << ClickState::noClick;
          switch (event.button.button)
          {
            case SDL_BUTTON_LEFT:
              Mouse::setClickState(Mouse::ClickState::leftClick); break;
            case SDL_BUTTON_RIGHT:
              Mouse::setClickState(Mouse::ClickState::rightClick); break;
            default:
              break;
          }
        }
        if (event.type == SDL_USEREVENT)
        {
          //handle timer
          for (auto idle : idles)
          {
             std::cout << "welp" << std::endl;
            idle->getComponent<IdleComponent>().check_time();
          }
        }
			}
}

void Game::update() {
  manager.refresh();
  manager.update();
  //std::cout << getClickState();
  Mouse::setClickState(Mouse::ClickState::noClick);

  //update text boxes before rendering. I may automate it later but its small for now so doesnt matter
  score_textbox.getComponent<TextBoxComponent>().update_text("Score: " + std::to_string(Cookie::get_points()));

  //score_textbox.getComponent<TextBoxComponent>().update_text("points from idles: ");
}




void Game::render()
{
    SDL_RenderClear(renderer);
   // Cookie::print_score();
  // update stuffs
  for (auto& c : clickables)
  {
    c->draw();
  }

  // for (auto& b : shopItems)
  // {
  // //  b->draw();
  // }
  for (auto& menu : menus)
  {
    menu->draw();
  }

  for (auto& text : text_boxes)
  {
    text->draw();
  }

  SDL_RenderPresent(renderer);
  for (auto& cc : colliders)
  {
    cc->draw();
  } 
}

void Game::clean() {
  SDL_RemoveTimer(ShopFunctions::Timer::get_timer_ID());
  SDL_FreeCursor(SDL_GetCursor());    
  SDL_DestroyWindow(Game::window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  std::cout << "Game Cleaned!" << std::endl;
}


void Game::setCursor(const char* file_path)
{
    SDL_Surface* surface = IMG_Load(file_path);
    
    SDL_Cursor* cursor = SDL_CreateColorCursor(surface, 0, 0);

    SDL_SetCursor(cursor);
}