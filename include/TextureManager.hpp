#pragma once
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include "Game.hpp"

class TextureManager
{

public:
	static SDL_Texture* LoadTexture(const char* p_fileName);
	static void Draw(SDL_Texture* tex, SDL_Rect srcR, SDL_Rect destR);


private:
};