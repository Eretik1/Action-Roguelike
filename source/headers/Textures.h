#pragma once
#include "AllLibs.h"
namespace Textures 
{
    sf::Texture player_texture;

    static void setTextures()
    {
        player_texture.loadFromFile("Y:/Programming/Action-Roguelike/img/player_t.png");
    }
}