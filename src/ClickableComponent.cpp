#include "ECS/ClickableComponent.hpp"
#include "ECS/ECS.hpp"



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
                  else if (tag == "shop")
                  {
                      // open shop menu
                  }
                }
                else
                {
                //    std::cout << "the location of the mouse: " << mousex << ", " << mousey;
                }
            }



             void ClickableComponent::init () 
            {
                entity->addComponent<ColliderComponent>(tag);
            }   


	void ClickableComponent::update() 
	{
      //  std::cout << "welp" << std::endl;
        if (game->getClickState() == Game::ClickState::leftClick)
        {
            onClick();
           // std::cout << "click" << std::endl;
        }
       // std::cout << game->getClickState();
        if (game->getClickState() != Game::ClickState::noClick)
        {
        }
    }