#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
class Cookie
{
    public:
        static void set_idles(int num);
        static void set_multiplier(int num);
        static unsigned int get_multiplier();
        static void print_score();
        static unsigned int get_points();
        static void add_points(int num);
        static void add_points(int num, bool useMultiplier);
        static void remove_points(int num);
    private:
        static unsigned long int multiplier;
        static unsigned long int score;
};
