#include "Game.hpp"
#include "SDL2/SDL.h"
#include "Mouse.hpp"



Mouse::ClickState Mouse::click = Mouse::ClickState::noClick;
Mouse::ClickState Mouse::getClickState()
{
    return Mouse::click;
}
void Mouse::setClickState(ClickState clickstate)
{
    click = clickstate;
}