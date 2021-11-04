#include "Shop.hpp"
#include "Cookie.hpp"
#include "ECS/ECS.hpp"


void add_Multiplier(int num)
{
    Cookie::set_multiplier(Cookie::get_multiplier());
} 
Shop::ShopItem* multiplier10 = new Shop::ShopItem(1000, add_Multiplier, 10);

std::vector<Shop::ShopItem*> Shop::ShopMenu::shop_items = {multiplier10};