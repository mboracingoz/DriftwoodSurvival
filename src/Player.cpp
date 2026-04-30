#include "Player.h"

void UpdatePlayer(Player& player, Vector2 direction, float deltatime){
    player.position.x += direction.x * player.speed * deltatime;
    player.position.y += direction.y * player.speed * deltatime;   
}