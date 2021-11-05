#pragma once
#include "ECS/ECS.hpp"
#include "ECS/Components.hpp"


class ShopItemComponent : public Component
{
    private:
        void (*on_buy)(int);
        int price;
        std::string Text;
         