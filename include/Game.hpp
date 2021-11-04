#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

class ColliderComponent;

class Game {
public:
  enum ClickState : int
  {
    leftClick = 1,
    rightClick = 2,
    noClick = 0
  };



  Game();
  ~Game();

  void init(const char *title, int xpos, int ypos, int width, int height,
            bool fullscreen);



  void handleEvents();
  void update();
  void render();
  void clean();

  bool isRunning() { return is_running; }


  //static void AddTile(int id, int x, int y);
  static SDL_Renderer *renderer;
  static SDL_Event event;
  static std::vector<ColliderComponent *> colliders;
  static void setCursor(const char* file_path);


    ClickState getClickState() {return click;}
    void setClickState(ClickState clickstate) {click = clickstate;}
private:
  ClickState click = ClickState::noClick; 
  bool is_running = false;
  SDL_Window *window;
};