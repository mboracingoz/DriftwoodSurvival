#include "HUDSystem.h"
#include "raylib.h"
#include "Constants.h"

void DrawHUD(const GameState& game)
{
    const int barX = 40;
    const int barY = 130;
    const int barWidth = 180;
    const int barHeight = 18;

    DrawText("Stamina", barX, barY - 24, 18, DARKGRAY);

    DrawRectangle(barX, barY, barWidth, barHeight, GRAY);

    float staminaPercent = game.player.stamina / GameConstants::PLAYER_MAX_STAMINA;

    if (staminaPercent < 0.0f)
    {
        staminaPercent = 0.0f;
    }

    if (staminaPercent > 1.0f)
    {
        staminaPercent = 1.0f;
    }

    int fillWidth = static_cast<int>(barWidth * staminaPercent);

    DrawRectangle(barX, barY, fillWidth, barHeight, SKYBLUE);
    DrawRectangleLines(barX, barY, barWidth, barHeight, DARKGRAY);
}