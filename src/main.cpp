#include "raylib.h"
#include "Player.h"
#include "InputManager.h"


int main()
{
    InitWindow(1280, 720, "Driftwood: Survival Prototype");
    SetTargetFPS(60);

    Player player{
        {640.0f, 360.0f},
        250.0f
    };
    InputManager input;

    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();

        UpdateInput(input);
        UpdatePlayer(player, input.moveDirection, deltaTime);


        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Driftwood: Survival Prototype", 40, 40, 30, DARKGREEN);
        DrawText("Move with WASD keys", 40, 80, 20, DARKGRAY);

        DrawRectangleV(player.position, { 40.0f, 40.0f }, BROWN);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
