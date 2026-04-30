#pragma once 
#include "raylib.h"

struct Player
{
    /* data */
    Vector2 position;

    float walkSpeed;
    float runSpeed;

    float stamina;
    bool isRunning;
};

void UpdatePlayer(Player& player, Vector2 direction, float deltaTime, bool runPressed );