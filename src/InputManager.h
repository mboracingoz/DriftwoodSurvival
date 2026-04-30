#pragma once
#include "raylib.h"
#include "raymath.h"

struct InputManager
{
    Vector2 moveDirection = { 0.0f, 0.0f };
    bool runPressed = false;
};

inline void UpdateInput(InputManager& input)
{
    // Her frame input state resetlenir.
    input.moveDirection = { 0.0f, 0.0f };
    input.runPressed = false;

    if (IsKeyDown(KEY_W)) input.moveDirection.y -= 1.0f;
    if (IsKeyDown(KEY_S)) input.moveDirection.y += 1.0f;
    if (IsKeyDown(KEY_A)) input.moveDirection.x -= 1.0f;
    if (IsKeyDown(KEY_D)) input.moveDirection.x += 1.0f;

    if (Vector2Length(input.moveDirection) > 0.0f)
    {
        input.moveDirection = Vector2Normalize(input.moveDirection);
    }

    input.runPressed = IsKeyDown(KEY_LEFT_SHIFT);
}