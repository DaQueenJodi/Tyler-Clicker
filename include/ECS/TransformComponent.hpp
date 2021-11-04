#pragma once
#include "../Vector2D.hpp"
#include "Components.hpp"
#include "ECS.hpp"
#include <SDL2/SDL.h>

struct TransformComponent : public Component {

  Vector2D position;
  Vector2D velocity;

  int height = 32;
  int width = 32;
  int scale = 1;

  int speed = 3;

  TransformComponent() {
    position.x = 0.0f;
    position.y = 0.0f;
  }

  TransformComponent(float x, float y) {
    position.x = x;
    position.y = y;
  }

    TransformComponent(float x, float y, int sc) {
    position.x = x;
    position.y = y;
    scale = sc;
  }

  TransformComponent(float x, float y, int h, int w, int sc) {
    position.x = x;
    position.y = y;
    height = h;
    width = w;
    scale = sc;
  }

  TransformComponent(int sc) {
    position.x = 0.0f;
    position.y = 0.0f;
    scale = sc;
  }
  void init() override {
    velocity.x = 0;
    velocity.y = 0;
  }

  void update() override {
    position.x += velocity.x * speed;
    position.y += velocity.y * speed;
  }
};