#pragma once


#include "../Game.hpp"
#include "ECS.hpp"
#include "Components.hpp"


class KeyboardController : public Component
{
public:
	TransformComponent* transform;

	void init() override
	{
		transform = &entity->getComponent<TransformComponent>();
	}


	void update() override
	{
		if (Game::event.type == SDL_KEYDOWN)
		{
			switch (Game::event.key.keysym.sym)
			{
				//keydown
			}
		}
		if (Game::event.type == SDL_KEYUP)
		{
				switch (Game::event.key.keysym.sym)
			{
				//keyup
			}
		}
	}
};