#include "ECS/Components.hpp"
#include "ECS/ECS.hpp"
#include "ECS/IdleComponent.hpp"
#include "ShopFunctions.hpp"

IdleComponent::IdleComponent(int idle_type,unsigned int points)
{
    Idle_type = idle_type;
    //looks dumb, but its the easiest way to do it without having to provide a seperate argument which is annoying lol
    if (idle_type == ShopFunctions::Idle::idle_5_sec)
    {
        Time = 5;
    } 
    else if (idle_type == ShopFunctions::Idle::idle_10_sec)
    {
        Time = 10;
    } 
    else if (idle_type == ShopFunctions::Idle::idle_15_sec)
    {
        Time = 15;
    } 
    Points = points;
}
IdleComponent::IdleComponent(int idle_type, unsigned int points, void (*func)(int), int arg)
{
    Idle_type = idle_type;
    Points = points;
    Arg = arg;
    void (*function)(int) = func;
}
void IdleComponent::check_time()
{
    //std::cout << "points: " << Points << ", Idle_type: " << Idle_type << std::endl;
    //checks if ShopFunction::Timer::timer is a multiple of time
    if (! (ShopFunctions::Timer::get_timer() % Time) )
    {
        std::cout << "time" << std::endl;
        on_time();
    }
}

void IdleComponent::on_time()
{
    //basically does everything * the ammount of this type of idles
    for (unsigned int i = 0; i < ShopFunctions::Idle::get_idle(this->Idle_type); ++i)
    {
        std::cout << "loop" << std::endl;
        std::cout << "Adding " << Points << " points to Cookie::score" << std::endl;
        // add specified number of points
        Cookie::add_points(Points, false);
        //if defined and has a proper arg, call the custom function
    }
}
void IdleComponent::update() 
{
    
}