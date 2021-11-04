#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
class Cookie
{
    public:
        Cookie();
        ~Cookie();
        static void set_multiplier(int m);
        static int get_multiplier();
        static void print_score();
        static void add_points(int p);
        static void remove_points(int p);
    private:
        static int multiplier;
        static int score;
};
