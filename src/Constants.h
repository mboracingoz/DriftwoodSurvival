#pragma once

namespace GameConstants
{
    constexpr float PLAYER_WALK_SPEED = 140.0f;
    constexpr float PLAYER_RUN_SPEED = 220.0f;

    constexpr float PLAYER_MAX_STAMINA = 100.0f;
    constexpr float PLAYER_START_STAMINA = 100.0f;

    constexpr float STAMINA_DRAIN_PER_SECOND = 20.0f;
    constexpr float STAMINA_RECOVER_PER_SECOND = 15.0f;

    constexpr float PLAYER_MAX_HUNGER = 100.0f;
    constexpr float PLAYER_START_HUNGER = 80.0f;

    constexpr float HUNGER_DRAIN_IDLE_PER_SECOND = 0.4f;
    constexpr float HUNGER_DRAIN_WALK_PER_SECOND = 0.8f;
    constexpr float HUNGER_DRAIN_RUN_PER_SECOND = 1.4f;
}