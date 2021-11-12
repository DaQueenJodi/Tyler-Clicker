#pragma once
#include "ECS/ECS.hpp"
#include "ECS/Components.hpp"
#include "Colors.hpp"

class ButtonComponent : public Component
{
    private:
        int posx;
        int posy;
        SDL_Color Color;
       // std::string Tag;
        unsigned int Price;
        SDL_Rect* Rect;
        std::string Text;
        void (*on_click)(int);
        int arg_for_func;

    public:
        void draw() override;
        void init() override;
        void click();
        void change_location(int x, int y, bool absolute = true);
        ButtonComponent(int price, std::string text, void (*func)(int), int arg, int x, int y, SDL_Color color = Colors::White);
        ButtonComponent(std::string text, void (*func)(int), int arg, int x, int y, SDL_Color color = Colors::White);
        ButtonComponent(int price, std::string text, void (*func)(int), int arg, SDL_Color color = Colors::White);
        ButtonComponent(std::string text, void (*func)(int), int arg, SDL_Color color = Colors::White);
        ~ButtonComponent();
};