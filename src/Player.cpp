#include "Player.h"
#include "raymath.h"

void UpdatePlayer(Player& player, Vector2 direction, float deltaTime, bool runPressed)
{
    const bool isMoving = Vector2Length(direction) > 0.0f;
    const bool canRun = player.stamina > 0.0f;

    player.isRunning = runPressed && isMoving && canRun;

    float currentSpeed = player.walkSpeed;

    if (player.isRunning)
    {
        currentSpeed = player.runSpeed;
        player.stamina -= 20.0f * deltaTime;
    }
    else
    {
        player.stamina += 15.0f * deltaTime;
    }

    if (player.stamina < 0.0f)
    {
        player.stamina = 0.0f;
    }

    if (player.stamina > 100.0f)
    {
        player.stamina = 100.0f;
    }

    player.position.x += direction.x * currentSpeed * deltaTime;
    player.position.y += direction.y * currentSpeed * deltaTime;
}