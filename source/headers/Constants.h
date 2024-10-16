#pragma once
#include <iostream>
constexpr float PI = 3.14159265;

constexpr float WINDOW_HEIGHT = 1080;
constexpr float WINDOW_WIDTH = 1920;

constexpr float SPRITE_SIZE = 64.0;

constexpr float PLAYER_SPEED              = 0.12;

constexpr float PLAYER_START_X            = WINDOW_HEIGHT / 2.0 - SPRITE_SIZE;
constexpr float PLAYER_START_Y            = WINDOW_WIDTH / 2.0 - SPRITE_SIZE;

constexpr float FIREBALL_DEFAULT_SIZE = 24.0;
constexpr float FIREBALL_DEFAULT_DAMAGE = 20.0;
constexpr float FIREBALL_DEFAULT_SPEED = 0.24;