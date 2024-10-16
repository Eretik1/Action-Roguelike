#include "headers/GameObject.h"

sf::Sprite GameObject::getSprite() const
{
    return d_sprite;
}

sf::Vector2f GameObject::getPos() const
{
    return d_pos;
}

sf::Vector2f GameObject::getSize() const
{
    return d_size;
}
