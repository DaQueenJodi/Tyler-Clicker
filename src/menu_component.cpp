#include "ECS/Components.hpp"
#include "ECS/ECS.hpp"
#include "ECS/MenuComponent.hpp"

MenuComponent::MenuComponent(std::vector<Entity*> items, int space, int x, int y)
{
    shop_items = items;
    spacing = space;
    lastx = x;
    lasty = y;
    lastw = items[0]->getComponent<TransformComponent>().width;
    lasth = items[0]->getComponent<TransformComponent>().height;
}
MenuComponent::~MenuComponent()
{}

void MenuComponent::draw()
{
    //draw everery item
    for (auto& item : shop_items)
    {
        item->draw();
    }
}

void MenuComponent::init()
{
    for (unsigned int i = 0; i < shop_items.size(); ++i)
    {
        int space = spacing;
       // bool absolute = false;
        if (i > 0)
        {
            lastx = shop_items[i - 1]->getComponent<TransformComponent>().position.x;
            lasty = shop_items[i - 1]->getComponent<TransformComponent>().position.y;
            lastw = shop_items[i - 1]->getComponent<TransformComponent>().width;
        }
          shop_items[i]->getComponent<ButtonComponent>().change_location(10, 100, true);
    }
}