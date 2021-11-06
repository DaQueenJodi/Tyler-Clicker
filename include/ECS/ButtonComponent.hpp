#pragma once
#include "ECS/ECS.hpp"
#include "ECS/Components.hpp"


class ButtonComponent : public Component
{
    private:
        int posx;
        int posy;
       // std::string Tag;
        unsigned int Price;
        SDL_Rect* Rect;
        std::string Text;
        void (*on_click)(int);
        int arg_for_func;
        SDL_Color Back_Color;
    public:
        void draw() override;
        void init() override;
        void click();
        ButtonComponent(int price, std::string text, void (*func)(int), int arg, int x, int y);
        ButtonComponent(std::string text, void (*func)(int), int arg, int x, int y);
        ButtonComponent(int price, std::string text, void (*func)(int), int arg);
        ButtonComponent(std::string text, void (*func)(int), int arg);
        ButtonComponent(int price, std::string text, void (*func)(int), int arg, int x, int y, SDL_Color color);
        ButtonComponent(std::string text, void (*func)(int), int arg, int x, int y, SDL_Color color);
        ButtonComponent(int price, std::string text, void (*func)(int), int arg, SDL_Color color);
        ButtonComponent(std::string text, void (*func)(int), int arg, SDL_Color color);
        ~ButtonComponent();
};