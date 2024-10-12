#include "headers/AllLibs.h"
#include "Character.h"

Character::~Character() {}

void Character::takeDamage(float damage)
{
    d_health -= damage;
}
void Character::setDirection(Direction direction)
{
    d_direction = direction;
}
void Character::setPosition(sf::Vector2f &pos)
{
    d_pos = pos;
}

float Character::getHealth() const
{
    return d_health;
}
float Character::getSpeed() const
{
    return d_speed;
}
sf::Vector2f Character::getSize() const
{
    return d_size;
}
sf::Vector2f Character::getPos() const
{
    return d_pos;
}   
sf::Sprite Character::getSprite() const
{
    return d_sprite;
}  
Direction Character::getDirection() const
{
    return d_direction;
}