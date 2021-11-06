#include "ECS/Components.hpp"
#include "ECS/ECS.hpp"
#include "Colors.hpp"
TextBoxComponent::~TextBoxComponent()
{

}

TextBoxComponent::TextBoxComponent(int x, int y)
{
    xpos = x;
    ypos = y;
    will_change = true;
}
TextBoxComponent::TextBoxComponent(int x, int y,std::string text)
{
    xpos = x;
    ypos = y;
    will_change = false;
    Text = text;
}

void TextBoxComponent::update_text(std::string text)
{
    Text = text;
}

void TextBoxComponent::draw()
{
    //borrow some stuff from button component but make it more simple:

TTF_Font* Font = TTF_OpenFont("res/fonts/LemonMilk.ttf", 20);

SDL_Surface* surfaceMessage =
    TTF_RenderText_Solid(Font, Text.c_str(), Colors::Black); 

SDL_Texture* Message = SDL_CreateTextureFromSurface(Game::renderer, surfaceMessage);
int w;
int h;
int x = xpos;
int y = ypos;
TTF_SizeText(Font, Text.c_str(), &w, &h);
SDL_Rect Message_rect; //create a rect
Message_rect.x = x;  //controls the rect's x coordinate 
Message_rect.y = y;
Message_rect.w = w; // controls the width of the rect
Message_rect.h = h; // controls the height of the rect

SDL_RenderCopy(Game::renderer, Message, NULL, &Message_rect);
SDL_FreeSurface(surfaceMessage);
SDL_DestroyTexture(Message);
TTF_CloseFont(Font);
Font = NULL;
}