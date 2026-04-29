#include "raylib.h"

int main()
{
    InitWindow(1280, 720, "Driftwood: Survival Prototype");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Driftwood: Survival Prototype", 40, 40, 30, DARKGREEN);
        DrawText("Raylib + C++ setup is working.", 40, 90, 20, DARKGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
