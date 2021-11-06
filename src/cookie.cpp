#include "Cookie.hpp"
#include <iostream>
#include "Game.hpp"
/*static*/unsigned long int Cookie::multiplier = 1;
/*static*/unsigned long int Cookie::score = 0;
void Cookie::remove_points(int num)
{
    Cookie::score -= num;    
}

unsigned int Cookie::get_points()
{
    return Cookie::score;
}

void Cookie::add_points(int num)
{
    Cookie::score += (num * multiplier);
}

void Cookie::add_points(int num, bool useMultiplier)
{
    if (useMultiplier)
        Cookie::score += (num * multiplier);
    else 
        Cookie::score += num;
}

unsigned int Cookie::get_multiplier()
{
    return Cookie::multiplier;
}

void Cookie::set_multiplier(int num)
{
    Cookie::multiplier = num;
}
