#include "raylib.h"
#include "Player.h"
#include "InputManager.h"
#include "GameState.h"


void ProcessInput(GameState& game)
{
    UpdateInput(game.input);
}

void UpdateGame(GameState& game, float deltaTime)
{
    UpdatePlayer(game.player, game.input.moveDirection, deltaTime);
}


void DrawGame(const GameState& game){
    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawText("Driftwood: Survival Prototype", 40, 40, 30, DARKGREEN);
    DrawText("Move with WASD keys", 40, 80, 20, DARKGRAY);

    DrawRectangleV(game.player.position, { 40.0f, 40.0f }, BROWN);

    EndDrawing();
}

int main()
{
    InitWindow(1280, 720, "Driftwood: Survival Prototype");
    SetTargetFPS(60);


    GameState game;

    game.player = {
        { 640.0f, 360.0f },
        250.0f
    };
    InputManager input;

    while (!WindowShouldClose())
    {
       
        float deltaTime = GetFrameTime();
        ProcessInput(game);
        UpdateGame(game, deltaTime);
        DrawGame(game);
        
    }

    CloseWindow();
    return 0;
}
