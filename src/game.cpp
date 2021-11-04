#include "Collision.hpp"
#include "ECS/Components.hpp"
#include "ECS/ECS.hpp"
#include "Game.hpp"
#include "TextureManager.hpp"
#include "Vector2D.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

SDL_Event Game::event;

SDL_Renderer *Game::renderer = nullptr;


std::vector<ColliderComponent*> Game::colliders;

Manager manager;

auto &cookie(manager.addEntity());


Game::Game()
{}
Game::~Game()
{}

//define groups
enum groupLabels : std::size_t
{
    groupClickables,
    groupBackgrounds,
    groupColliders
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

    if (TTF_Init() == 0)
    {
      std::cout << "TTF Initialized" << std::endl;
    }

    Cookie::set_multiplier(1);

    cookie.addComponent<TransformComponent>(100, 300, 2);
    cookie.addComponent<SpriteComponent>("res/gfx/player.png");
    cookie.addComponent<ColliderComponent>("cookie");
    cookie.addComponent<ClickableComponent>("cookie", this);
    cookie.addGroup(groupClickables);
    
  } else {
    std::cout << "failed to run submodules, frick" << std::endl;
   is_running = false;
  }
}



auto& clickables(manager.getGroup(groupClickables));


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
              setClickState(ClickState::leftClick); break;
            case SDL_BUTTON_RIGHT:
              setClickState(ClickState::rightClick); break;
            default:
              break;
          }
        
        }
          if (getClickState() == ClickState::leftClick)
          {
         // std::cout << getClickState();
          }
			}
}

void Game::update() {
  manager.refresh();
  manager.update();
  //std::cout << getClickState();
  setClickState(ClickState::noClick);
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