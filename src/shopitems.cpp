#include "Shop.hpp"
#include "Cookie.hpp"
#include "ECS/ECS.hpp"

void add_Multiplier(int num)
{
    Cookie::set_multiplier(Cookie::get_multiplier());
} 