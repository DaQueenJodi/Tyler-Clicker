#include "ECS/ClickableComponent.hpp"
#include "ECS/ECS.hpp"
#include "Mouse.hpp"

ClickableComponent::ClickableComponent(std::string t)
{
    tag = t;
}

bool ClickableComponent::checkClick(SDL_Rect* rect, int mousex, int mousey)
{
    bool isInside = false;
    if (mousex >= rect->x && mousex < (rect->x + rect->w))
    {
        if (mousey >= rect->y && mousey < (rect->y + rect->h))
        {
            isInside = true;
        }
    }
        return isInside;
    }

    void ClickableComponent::onClick()
    {
        int mousex, mousey;
        SDL_GetMouseState(&mousex, &mousey);
                if (ClickableComponent::checkClick(&entity->getComponent<ColliderComponent>().collider, mousex, mousey))
                {
                  //  std::cout << "the thing do be clicked" << std::endl;
                  if (tag == "cookie")
                  {
                      Cookie::add_points(1);
                  }
                  else if (tag == "button")
                  {
                      std::cout << "button clicked!" << std::endl;
                      entity->getComponent<ButtonComponent>().click();
                  }
                }
                else
                {
                //    std::cout << "the location of the mouse: " << mousex << ", " << mousey;
                }
            }



             void ClickableComponent::init () 
            {
                if (!entity->hasComponent<ColliderComponent>())
                    entity->addComponent<ColliderComponent>(tag);
            }   


	void ClickableComponent::update() 
	{
      //  std::cout << "welp" << std::endl;
        if (Mouse::getClickState() == Mouse::ClickState::leftClick)
        {
            onClick();
           // std::cout << "click" << std::endl;
        }
       // std::cout << game->getClickState();
    }