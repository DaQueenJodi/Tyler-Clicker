#pragma once
#include <vector>
#include "Cookie.hpp"
class Shop
{
    public:
    class ShopItem
    {
        public:
        int price;
        int purchases;
        ShopItem(int p,  void (*func)(int), int args);
        int arg; 
        void (*function)(int);
        private:
        //int purchases;
        //int args;
        void on_buy();
        void draw();
        friend Shop;
    };
    class ShopMenu
    {
        static std::vector<ShopItem*> shop_items;
        static void buy(ShopItem&);
        static void show_menu();
        friend Shop;
    };
};