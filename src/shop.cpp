#include "Shop.hpp"
#include "ECS/ECS.hpp"
#include "Cookie.hpp"

Shop::ShopItem::ShopItem(int p, void (*func)(int), int args)
{
    int price = p;
    int purchases = 0;
    int arg = args;
    void (*function)(int) = (*func);
    Shop::ShopMenu::shop_items.push_back(this);
}

 void on_buy(Shop::ShopItem* item)
    {
        Cookie::remove_points(item->price);
        ++item->purchases;
        item->function(item->arg);
    }

void Shop::ShopMenu::show_menu()
{
    for (auto i : Shop::ShopMenu::shop_items)
    {
        i->show();
    }
}
