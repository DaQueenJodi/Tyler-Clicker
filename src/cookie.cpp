#include "Cookie.hpp"
#include <iostream>
#include "Game.hpp"
/*static*/ int Cookie::multiplier = 1;
/*static*/ int Cookie::score = 0;
void Cookie::remove_points(int num)
{
    Cookie::score -= num;    
}

int Cookie::get_points()
{
    return Cookie::score;
}

void Cookie::add_points(int num)
{
    Cookie::score += (num * multiplier);
}

int Cookie::get_multiplier()
{
    return Cookie::multiplier;
}

void Cookie::set_multiplier(int num)
{
    Cookie::multiplier = num;
}

void Cookie::print_score()
{
    std::string score_string = "score: " + std::to_string(Cookie::score);
   //this opens a font style and sets a size
TTF_Font* Font = TTF_OpenFont("res/fonts/LemonMilk.ttf", 30);

// this is the color in rgb format,
// maxing out all would give you the color white,
// and it will be your text's color
SDL_Color Black = {0, 0, 0, 255};

// as TTF_RenderText_Solid could only be used on
// SDL_Surface then you have to create the surface first
SDL_Surface* surfaceMessage =
    TTF_RenderText_Solid(Font, score_string.c_str(), Black); 

// now you can convert it into a texture
SDL_Texture* Message = SDL_CreateTextureFromSurface(Game::renderer, surfaceMessage);

int w;
int h;
//get the size
TTF_SizeText(Font, score_string.c_str(), &w, &h);

SDL_Rect Message_rect; //create a rect
Message_rect.x = 0;  //controls the rect's x coordinate 
Message_rect.y = 0; // controls the rect's y coordinte
Message_rect.w = w; // controls the width of the rect
Message_rect.h = h; // controls the height of the rect

// (0,0) is on the top left of the window/screen,
// think a rect as the text's box,
// that way it would be very simple to understand

// Now since it's a texture, you have to put RenderCopy
// in your game loop area, the area where the whole code executes

// you put the renderer's name first, the Message,
// the crop size (you can ignore this if you don't want
// to dabble with cropping), and the rect which is the size
// and coordinate of your texture
SDL_RenderCopy(Game::renderer, Message, NULL, &Message_rect);

// Don't forget to free your surface and texture
SDL_FreeSurface(surfaceMessage);
SDL_DestroyTexture(Message);
TTF_CloseFont(Font);
Font = NULL;
}