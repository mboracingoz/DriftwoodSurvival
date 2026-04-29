#pragma once 
#include "raylib.h"
#include "raymath.h"


struct InputManager
{
    /* data */
    Vector2 moveDirection;
};


inline void UpdateInput(InputManager& input){

    input.moveDirection = {0.0f, 0.f};

    if(IsKeyDown(KEY_W)) input.moveDirection.y -= 1.0f;
    if(IsKeyDown(KEY_S)) input.moveDirection.y += 1.0f;
    if(IsKeyDown(KEY_A)) input.moveDirection.x -= 1.0f;
    if(IsKeyDown(KEY_D)) input.moveDirection.x += 1.0f;

    if (Vector2Length(input.moveDirection) > 0.90)
    {
        input.moveDirection = Vector2Normalize(input.moveDirection);
        /* code */
    }
    
}