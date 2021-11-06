#pragma once
#include "ECS/Components.hpp"
#include "ECS/ECS.hpp"
#include "string"
//100% neccasary component lol
//this is for buttons that dont want to be complicated

class TextBoxComponent : public Component
{
    private:
      bool will_change;
      int xpos;
      int ypos;
      std::string Text;
    public:
        //void update() override;
        void draw() override;
        void update_text(std::string text);
        ~TextBoxComponent();
        TextBoxComponent(int x, int y, std::string text);
        TextBoxComponent(int x, int y); 
};