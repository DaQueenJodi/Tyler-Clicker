#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

class ColliderComponent;

class Game {
public:


  Game();
  ~Game();

  void init(const char *title, int xpos, int ypos, int width, int height,
            bool fullscreen);



  void handleEvents();
  void update();
  void render();
  void clean();

  bool isRunning() { return is_running; }


  static int screen_width;
  static int screen_height;

  
  static SDL_Renderer *renderer;
  static SDL_Event event;
  static std::vector<ColliderComponent *> colliders;
  static void setCursor(const char* file_path);
private:
  bool is_running = false;
  SDL_Window *window;
};