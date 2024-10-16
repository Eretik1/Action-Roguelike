#include "headers/FireBall.h"
#include "headers/Character.h"
#include "headers/Constants.h"

FireBall::FireBall(const sf::Texture& texture, sf::Vector2f pos, sf::Vector2f direction)
{
    d_sprite.setTexture(texture);
    d_pos = pos;
    d_size = sf::Vector2f(FIREBALL_DEFAULT_SIZE, FIREBALL_DEFAULT_SIZE);
    d_direction = direction;
    d_damage = FIREBALL_DEFAULT_DAMAGE;
}

void FireBall::Update(float time)
{
    d_pos.x += d_direction.x*FIREBALL_DEFAULT_SPEED*time;
    d_pos.y += d_direction.y*FIREBALL_DEFAULT_SPEED*time;

    d_sprite.setPosition(d_pos);
    d_sprite.setScale(0.5, 0.5);

}

void FireBall::updateDamage(float scale) {
    d_damage *= scale;
}