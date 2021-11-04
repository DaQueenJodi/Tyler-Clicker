#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_video.h>
#include <iostream>
#include "Game.hpp"

Game* game = nullptr;

int main(int argc, char *argv[])
{
    game = new Game();

    game->init("welp", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

    Game::setCursor("res/gfx/cursor.bmp");

    while (game->isRunning())
    {
        game->handleEvents();
        game->update();
        game->render();
    }

    game->clean();

    return 0;
}