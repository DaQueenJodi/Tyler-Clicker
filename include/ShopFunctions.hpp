#pragma once
#include "Cookie.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <vector>
class ShopFunctions
{
    public:
        class Timer
        {
            public:
            static SDL_TimerID get_timer_ID();
            static int get_timer();
            static void add_timer(int num);
            private:
            static int timer;
            static Uint32 sdl_sucks_so_I_have_to_do_this(Uint32 interval, void *param);
            static SDL_TimerID sec_timer;        
        };
        class Idle
        {
            friend ShopFunctions;
        public:
            // im too lazy to remember this shit
            enum IDLE_SEC{
                idle_5 = 0,
                idle_10 = 1,
                idle_15 = 2,
            };
            static std::vector<unsigned int> get_idle();
            static  unsigned int get_idle(int idle_type);
        private:
            static std::vector<unsigned int> idles_vector;
        };
        static void add_multiplier(int num);
        static void add_idle(int idle_type);
};