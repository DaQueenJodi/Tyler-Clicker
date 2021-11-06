#pragma once
#include "ECS/ECS.hpp"
#include "ShopFunctions.hpp"
#include "ECS/Components.hpp"

class IdleComponent : public Component
{
    private:
        int Arg;
        int Points;
        unsigned int Time;
        void (*function)(int);
    public:
        int Idle_type;
        void check_time();
        void on_time();
        void update() override;
    IdleComponent(int idle_type, unsigned int points);
    IdleComponent(int idle_type,  unsigned int points, void (*func)(int), int arg);
};
