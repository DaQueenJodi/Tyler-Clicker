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
ButtonComponent::ButtonComponent( int price, std::string text, void (*func)(int), int arg, SDL_Color color)
{
    //set variables to the given ones. I know this naming scheme is shit, but shut
 //   Tag = t;
    Price = price;
    //Rect = rect;
    Text = text;
    on_click = func;
    arg_for_func = arg;
    Color = color;
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
    Color = color;
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
    Color = color;
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
    SDL_Rect Message_rect;
    Message_rect.x = x;  //controls the rect's x coordinate 
    Message_rect.y = y;
    Message_rect.w = w; // controls the width of the rect
    Message_rect.h = h; // controls the height of the rect
    //ensure text is in the middle of the button
    //maybe add a "padding" variable to control later
    SDL_Rect Button_rect;
    Button_rect.x = x - 20;
    Button_rect.y = y - 20; 
    Button_rect.h = h + 40;
    Button_rect.w = w + 40;

// needs to use Button_rect's stuff so that the entire button allows you to buy, not just the text
entity->getComponent<ColliderComponent>().collider.x = Button_rect.x;
entity->getComponent<ColliderComponent>().collider.y = Button_rect.y;
entity->getComponent<ColliderComponent>().collider.w = Button_rect.w;
entity->getComponent<ColliderComponent>().collider.h = Button_rect.h;




SDL_SetRenderDrawColor(Game::renderer, Color.r, Color.g, Color.b, Color.a);
SDL_RenderFillRect(Game::renderer, &Button_rect);
SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
SDL_RenderCopy(Game::renderer, Message, NULL, &Message_rect);
SDL_FreeSurface(surfaceMessage);
SDL_DestroyTexture(Message);
TTF_CloseFont(Font);
Font = NULL;
}