#pragma once
#include "ECS/ECS.hpp"
#include "ECS/Components.hpp"
#include "vector"
class MenuComponent : public Component
{
    private:
    //contains menu items
        int lastw;
        int lasth;
        int lastx;
        int lasty;
        std::vector<Entity*> shop_items;
    public:
        MenuComponent(std::vector<Entity*> items, int space = 30, int x = 0, int y = 0);
        ~MenuComponent();
        //spacing between each button
        unsigned int spacing;
        void draw() override;
        void init() override;
};