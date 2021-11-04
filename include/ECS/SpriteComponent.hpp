#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Components.hpp"
#include "TransformComponent.hpp"
#include "../TextureManager.hpp"


class SpriteComponent : public Component
{
private:
	TransformComponent* transform;
	SDL_Texture* texture;
	SDL_Rect srcR, destR;

	bool animated = false;
	int frames = 0;
	int speed = 100;

public:
	SpriteComponent() = default;
	SpriteComponent(const char* path)
	{
		setTex(path);
	}


	~SpriteComponent()
	{
		SDL_DestroyTexture(texture);
	}

	void setTex(const char* path)
	{
		texture = TextureManager::LoadTexture(path);
	}

	void init() override
	{
		transform = &entity->getComponent<TransformComponent>();

		srcR.x = srcR.y = 0;
		srcR.w = transform->width;
		srcR.h = transform->height;
	}

	void update() override
	{
		destR.x = (int)transform->position.x;
		destR.y = (int)transform->position.y;
		destR.w = transform->width * transform->scale;
		destR.h = transform->height * transform->scale;
	}

	void draw() override 
	{
		TextureManager::Draw(texture, srcR, destR);

	}


};