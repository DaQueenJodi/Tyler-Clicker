#include "ShopFunctions.hpp"
#include <iostream>
#include "ECS/ECS.hpp"
// set private static members
int ShopFunctions::Timer::timer = 0;
std::vector<unsigned int> ShopFunctions::Idle::idles_vector = {0, 0, 0};

void ShopFunctions::add_idle(int idle_type)
{
    ShopFunctions::Idle::idles_vector[idle_type] += 1;
    std::cout << ShopFunctions::Idle::get_idle(idle_type);
}

void ShopFunctions::add_multiplier(int num)
{
    Cookie::set_multiplier(Cookie::get_multiplier() + num);
    std::cout << "added " << num << "to multiplier!" << std::endl;
}

 SDL_TimerID ShopFunctions::Timer::sec_timer = SDL_AddTimer(1000, sdl_sucks_so_I_have_to_do_this, NULL);


Uint32 ShopFunctions::Timer::sdl_sucks_so_I_have_to_do_this(Uint32 interval, void *param)
{
    {

    //make the timer restart with 'interval' (make the timer loop forever basically)
    //also increments ShopFunction::Timer::time
    //this pushes an event timer to the queue. this helps makes sure its only counted for once, since its really annoying to impliment otherwise 
    add_timer(1);
      SDL_Event event;
    SDL_UserEvent userevent;
    userevent.type = SDL_USEREVENT;
    userevent.code = 0;
    userevent.data1 = NULL;
    userevent.data2 = NULL;
    event.type = SDL_USEREVENT;
    event.user = userevent;

    SDL_PushEvent(&event);
    return(interval);
    }
}

int ShopFunctions::Timer::get_timer()
{
    return ShopFunctions::Timer::timer;
}
void ShopFunctions::Timer::add_timer(int num)
{
    ShopFunctions::Timer::timer += num;
}

 unsigned int ShopFunctions::Idle::get_idle(int idle_type)
 {
    return ShopFunctions::Idle::idles_vector[idle_type];
 }

 std::vector<unsigned int> ShopFunctions::Idle::get_idle()
 {
    return ShopFunctions::Idle::idles_vector;
 }
 


 SDL_TimerID ShopFunctions::Timer::get_timer_ID()
 {
     return ShopFunctions::Timer::sec_timer;
 }
