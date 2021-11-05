#include "ShopFunctions.hpp"
#include <iostream>

void ShopFunctions::add_multiplier(int num)
{
    Cookie::set_multiplier(Cookie::get_multiplier() + num);
    std::cout << "added " << num << "to multiplier!" << std::endl;
}