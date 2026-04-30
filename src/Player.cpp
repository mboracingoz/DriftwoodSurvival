#include "Player.h"

void UpdatePlayer(Player& player, Vector2 direction, float deltatime, bool runPressed){
    float currentSpeed = player.walkSpeed;

    if (runPressed && player.stamina > 0.0f)
    {
        /* code */
        player.isRunning = true;
        currentSpeed = player.runSpeed;

        player.stamina -= 20.0f * deltatime; // decrease stamina while running
    }
    else
    {
        player.stamina += 15.0f * deltatime;
    }
    

    //clamp
    player.position.x += direction.x * currentSpeed * deltatime;
    player.position.y += direction.y * currentSpeed * deltatime;

    player.position.x += direction.x * currentSpeed * deltatime;
    player.position.y += direction.y * currentSpeed * deltatime;   
}