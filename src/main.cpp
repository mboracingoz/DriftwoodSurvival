#include "raylib.h"

int main()
{
    InitWindow(1280, 720, "Driftwood: Survival Prototype");
    SetTargetFPS(60);

    Vector2 playerPos = {640.0f, 360.0f};
    float playerSpeed = 250.0f;

    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();

        if (IsKeyDown(KEY_W))
        {
            playerPos.y -= playerSpeed * deltaTime;
        }

        if (IsKeyDown(KEY_S))
        {
            playerPos.y += playerSpeed * deltaTime;
        }

        if (IsKeyDown(KEY_A))
        {
            playerPos.x -= playerSpeed * deltaTime;
        }

        if (IsKeyDown(KEY_D))
        {
            playerPos.x += playerSpeed * deltaTime;
        }
        


        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Driftwood: Survival Prototype", 40, 40, 30, DARKGREEN);
        DrawText("Move with WASD keys", 40, 80, 20, DARKGRAY);

        DrawRectangleV(playerPos, {40.0f, 40.0f}, RED);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
