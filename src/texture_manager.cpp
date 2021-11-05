#include "TextureManager.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <filesystem>
#include <iostream>
SDL_Texture* TextureManager::LoadTexture(const char* p_fileName)
{
	if (!std::filesystem::exists(p_fileName))
	{
		std::cout << "image file doesnt exist! \n";
	}
	else
	{
		std::cout << "image file exists! \n";
	}
	SDL_Surface* tmpSurface = IMG_Load(p_fileName);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);

	return tex;
}

void TextureManager::Draw(SDL_Texture* tex, SDL_Rect srcR, SDL_Rect destR)
{
	SDL_RenderCopy(Game::renderer, tex, &srcR, &destR);
}