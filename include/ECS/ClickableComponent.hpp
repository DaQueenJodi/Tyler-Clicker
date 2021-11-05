#pragma once
#include "ECS/Components.hpp"
#include "../Collision.hpp"
#include "ECS.hpp"
#include "SDL2/SDL.h"
#include "ECS.hpp"



class ClickableComponent : public Component
{
private:
    //Game* game;
    //SDL_Event Game::event;
    Manager manager;
    bool hasReleased = true;
    
    bool checkClick(SDL_Rect* rect, int mousex, int mousey);
public:
    std::string tag;
	ClickableComponent(std::string t);

    void onClick();

    void init () override;

	void update() override;
};