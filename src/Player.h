#pragma once 
#include "raylib.h"

struct Player
{
    /* data */
    Vector2 position;
    float speed;
};

void UpdatePlayer(Player& player, Vector2 direction, float deltaTime);