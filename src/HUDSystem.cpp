#include "HUDSystem.h"
#include "raylib.h"
#include "Constants.h"

void DrawHUD(const GameState& game)
{
    const int barX = 40;
    const int staminaBarY = 180;
    const int barWidth = 180;
    const int barHeight = 18;

    const int hungerBarX = 40;
    const int hungerBarY = 130;
    const int hungerBarWidth = 180;
    const int hungerBarHeight = 18;

    DrawText("Stamina", barX, staminaBarY - 24, 18, DARKGRAY);
    DrawText("Hunger", hungerBarX, hungerBarY - 24, 18, DARKGRAY);

    DrawRectangle(barX, staminaBarY, barWidth, barHeight, GRAY);
    DrawRectangle(hungerBarX, hungerBarY, hungerBarWidth, hungerBarHeight, GRAY);

    float staminaPercent = game.player.stamina / GameConstants::PLAYER_MAX_STAMINA;
    float hungerPercent = game.player.hunger / GameConstants::PLAYER_MAX_HUNGER;

    if (staminaPercent < 0.0f)
    {
        staminaPercent = 0.0f;
    }

    if (staminaPercent > 1.0f)
    {
        staminaPercent = 1.0f;
    }

    if (hungerPercent < 0.0f)
    {
        hungerPercent = 0.0f;
    }

    if (hungerPercent > 1.0f)
    {
        hungerPercent = 1.0f;
    }

    int fillWidth = static_cast<int>(barWidth * staminaPercent);
    int hungerFillWidth = static_cast<int>(hungerBarWidth * hungerPercent);

    DrawRectangle(barX, staminaBarY, fillWidth, barHeight, SKYBLUE);
    DrawRectangleLines(barX, staminaBarY, barWidth, barHeight, DARKGRAY);

    DrawRectangle(hungerBarX, hungerBarY, hungerFillWidth, hungerBarHeight, ORANGE);
    DrawRectangleLines(hungerBarX, hungerBarY, hungerBarWidth, hungerBarHeight, DARKGRAY);  
}