#include "Player.h"
#include "raymath.h"
#include "Constants.h"

void UpdatePlayer(Player& player, Vector2 direction, float deltaTime, bool runPressed)
{
    const bool isMoving = Vector2Length(direction) > 0.0f;
    const bool canRun = player.stamina > 0.0f;

    player.isRunning = runPressed && isMoving && canRun;

    float currentSpeed = player.walkSpeed;

    if (player.isRunning)
    {
        currentSpeed = player.runSpeed;
        player.stamina -= GameConstants::STAMINA_DRAIN_PER_SECOND * deltaTime;
    }
    else
    {
        player.stamina += GameConstants::STAMINA_RECOVER_PER_SECOND * deltaTime;
    }

    float hungerDrain = GameConstants::HUNGER_DRAIN_IDLE_PER_SECOND;

    if (player.isRunning)
    {
        hungerDrain = GameConstants::HUNGER_DRAIN_RUN_PER_SECOND;
    }
    else if (isMoving)
    {
        hungerDrain = GameConstants::HUNGER_DRAIN_WALK_PER_SECOND;
    }

    player.hunger -= hungerDrain * deltaTime;

    if (player.stamina < 0.0f)
    {
        player.stamina = 0.0f;
    }

    if (player.stamina > GameConstants::PLAYER_MAX_STAMINA)
    {
        player.stamina = GameConstants::PLAYER_MAX_STAMINA;
    }

    if (player.hunger < 0.0f)
    {
        player.hunger = 0.0f;
    }

    if (player.hunger > GameConstants::PLAYER_MAX_HUNGER)
    {
        player.hunger = GameConstants::PLAYER_MAX_HUNGER;
    }

    player.position.x += direction.x * currentSpeed * deltaTime;
    player.position.y += direction.y * currentSpeed * deltaTime;
}