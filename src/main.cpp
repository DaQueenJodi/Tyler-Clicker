#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_video.h>
#include <iostream>
#include "Game.hpp"
#include "Cookie.hpp"
int main(int argc, char *argv[])
{
    if (argv[1])
    {
        Cookie::set_multiplier(atoi(argv[1]));
    }

    Game* game = new Game();

    game->init("welp", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, false);

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