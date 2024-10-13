#pragma once
#include "AllLibs.h"
namespace Textures 
{
    sf::Texture player_texture;

    static void setTextures()
    {
        player_texture.loadFromFile("../img/player_t.png");
    }
}