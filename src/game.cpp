#include "Collision.hpp"
#include "ECS/Components.hpp"
#include "ECS/ECS.hpp"
#include "Game.hpp"
#include "TextureManager.hpp"
#include "Vector2D.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "Shop.hpp"
#include "Mouse.hpp"
#include "ShopFunctions.hpp"
#include "Colors.hpp"
SDL_Event Game::event;

SDL_Renderer *Game::renderer = nullptr;


std::vector<ColliderComponent*> Game::colliders;

Manager manager;

auto &cookie(manager.addEntity());
auto &multiply10(manager.addEntity());
auto &multiply5(manager.addEntity());
auto &multiply1(manager.addEntity());
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
};

void Game::init(const char *title, int xpos, int ypos, int width, int height,
                bool fullscreen) {
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

    Cookie::set_multiplier(50);


    if (TTF_Init() == 0)
    {
      std::cout << "TTF Initialized" << std::endl;
    }
    multiply1.addComponent<TransformComponent>(400, 400, 3);
    multiply1.addComponent<ButtonComponent>(100, "Multiplier +1!", ShopFunctions::add_multiplier, 1, Colors::Pink);
    multiply1.addGroup(groupShopItems);

   multiply5.addComponent<TransformComponent>(600, 400, 3);
    multiply5.addComponent<ButtonComponent>(700, "Multiplier +5!", ShopFunctions::add_multiplier, 5, Colors::Blue);
    multiply5.addGroup(groupShopItems);

    multiply10.addComponent<TransformComponent>(100, 400, 3);
    multiply10.addComponent<ButtonComponent>(1000, "Multiplier +10!",  ShopFunctions::add_multiplier, 10, Colors::Orange);
    multiply10.addGroup(groupShopItems);

    cookie.addComponent<TransformComponent>(100, 300, 2);
    cookie.addComponent<SpriteComponent>("res/gfx/player.png");
    cookie.addComponent<ColliderComponent>("cookie");
    cookie.addComponent<ClickableComponent>("cookie");
    cookie.addGroup(groupClickables);
  } else {
    std::cout << "failed to run submodules, frick" << std::endl;
   is_running = false;
  }
}



auto& clickables(manager.getGroup(groupClickables));
auto& shopItems(manager.getGroup(groupShopItems));


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
          if (Mouse::getClickState() == Mouse::ClickState::leftClick)
          {
         // std::cout << getClickState();
          }
			}
}

void Game::update() {
  manager.refresh();
  manager.update();
  //std::cout << getClickState();
  Mouse::setClickState(Mouse::ClickState::noClick);
}



void Game::render()
{
    SDL_RenderClear(renderer);
    Cookie::print_score();
  // update stuffs
  for (auto& c : clickables)
  {
    c->draw();
  }

  for (auto& b : shopItems)
  {
    b->draw();
  }

  SDL_RenderPresent(renderer);
  for (auto& cc : colliders)
  {
    cc->draw();
  } 

}

void Game::clean() {
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