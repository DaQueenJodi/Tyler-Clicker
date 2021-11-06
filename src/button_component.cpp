#include "ECS/Components.hpp"
#include "ECS/ECS.hpp"
#include "Colors.hpp"
void ButtonComponent::click()
{
    if (Cookie::get_points() >= Price)
    {
    Cookie::remove_points(Price);
    on_click(arg_for_func);
    }
    else
        std::cout << "cant afford it :pensive:" << std::endl; 
}


//set variables. This name scheme sucks but it works.
ButtonComponent::ButtonComponent(int price, std::string text, void (*func)(int), int arg, int x, int y)
{
    posx = x;
    posy = y;
  //  Tag = t;
    Price = price;
    //Rect = rect;
    Text = text;
    on_click = func;
    arg_for_func = arg;
}
ButtonComponent::ButtonComponent( int price, std::string text, void (*func)(int), int arg)
{
    //set variables to the given ones. I know this naming scheme is shit, but shut
 //   Tag = t;
    Price = price;
    //Rect = rect;
    Text = text;
    on_click = func;
    arg_for_func = arg;
}

ButtonComponent::ButtonComponent( std::string text, void (*func)(int), int arg, int x, int y)
{
    //set variables to the given ones. I know this naming scheme is shit, but shut
    posx = x;
    posy = y;
 //   Tag = t;
    Price = 0;
    //Rect = rect;
    Text = text;
    on_click = func;
    arg_for_func = arg;
}
ButtonComponent::ButtonComponent( std::string text, void (*func)(int), int arg)
{
    //set variables to the given ones. I know this naming scheme is shit, but shut
   // Tag = t;
    Price = 0;
    //Rect = rect;
    Text = text;
    on_click = func;
    arg_for_func = arg;
}

ButtonComponent::ButtonComponent( int price, std::string text, void (*func)(int), int arg, SDL_Color color)
{
    //set variables to the given ones. I know this naming scheme is shit, but shut
 //   Tag = t;
    Price = price;
    //Rect = rect;
    Text = text;
    on_click = func;
    arg_for_func = arg;
    Back_Color = color;
}

ButtonComponent::ButtonComponent( std::string text, void (*func)(int), int arg, int x, int y, SDL_Color color)
{
    //set variables to the given ones. I know this naming scheme is shit, but shut
    posx = x;
    posy = y;
 //   Tag = t;
    Price = 0;
    //Rect = rect;
    Text = text;
    on_click = func;
    arg_for_func = arg;
    Back_Color = color;
}
ButtonComponent::ButtonComponent( std::string text, void (*func)(int), int arg, SDL_Color color)
{
    //set variables to the given ones. I know this naming scheme is shit, but shut
   // Tag = t;
    Price = 0;
    //Rect = rect;
    Text = text;
    on_click = func;
    arg_for_func = arg;
    Back_Color = color;
}

ButtonComponent::~ButtonComponent()
{

}

void ButtonComponent::init()
{   
 // (not needed as ClickableComponent does this)  entity->addComponent<ColliderComponent>("button");
    entity->addComponent<ClickableComponent>("button");
    if (!entity->hasComponent<TransformComponent>())
    {
        if (posx && posy)
            entity->addComponent<TransformComponent>(posx, posy, 3); 
        else
           std::cout << "no transform component nor coordinates provided in constructor!" << std::endl;
    }
}

void ButtonComponent::draw()
{
TTF_Font* Font = TTF_OpenFont("res/fonts/LemonMilk.ttf", 15);

SDL_Surface* surfaceMessage =
    TTF_RenderText_Solid(Font, Text.c_str(), Colors::Black); 

SDL_Texture* Message = SDL_CreateTextureFromSurface(Game::renderer, surfaceMessage);
int w;
int h;
int x = entity->getComponent<ColliderComponent>().collider.x;   
int y = entity->getComponent<ColliderComponent>().collider.x;
TTF_SizeText(Font, Text.c_str(), &w, &h);
SDL_Rect Message_rect; //create a rect
Message_rect.x = x;  //controls the rect's x coordinate 
Message_rect.y = y;
Message_rect.w = w; // controls the width of the rect
Message_rect.h = h; // controls the height of the rect

entity->getComponent<TransformComponent>().position.y = Message_rect.y;
entity->getComponent<TransformComponent>().position.x = Message_rect.x;
entity->getComponent<TransformComponent>().width = Message_rect.w;
entity->getComponent<TransformComponent>().height = Message_rect.h;

SDL_SetRenderDrawColor(Game::renderer, Back_Color.r, Back_Color.g, Back_Color.b, 255);
SDL_RenderFillRect(Game::renderer, &Message_rect);
SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
SDL_RenderCopy(Game::renderer, Message, NULL, &Message_rect);
SDL_FreeSurface(surfaceMessage);
SDL_DestroyTexture(Message);
TTF_CloseFont(Font);
Font = NULL;
}