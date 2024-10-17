#pragma once

#include <SFML/Graphics.hpp>

class GameObject 
{
    protected:
        sf::Vector2f d_size;
        sf::Vector2f d_pos;
        sf::Sprite d_sprite;

        GameObject() = default;
        virtual ~GameObject() = default;

    public:
        sf::Sprite getSprite() const;
        sf::Vector2f getPos() const;
        sf::Vector2f getSize() const;
};