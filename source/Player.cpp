#include "headers/Player.h"
#include "headers/PlayerController.h"
#include "headers/Weapon.h"
#include "headers/Constants.h"
#include <memory>
Player::Player(const sf::Texture &texture, sf::Vector2f start_pos, float health)
{
    d_pos = start_pos;
    d_health = health;

    d_controller = std::make_unique<PlayerController>();
    
    d_sprite.setTexture(texture);
    d_size = sf::Vector2f(d_sprite.getTextureRect().width, d_sprite.getTextureRect().height);

}
void Player::initWeapon(float damage_scale, const sf::Texture& texture)
{
    d_weapon = std::make_shared<Weapon>(texture, d_pos, damage_scale, PLAYER_START_ATTACK_SPEED);
}

void Player::Update(float time) 
{
    d_state = State::Idle;
    d_controller->controllPlayer(this, time);
    if (d_state == State::Run)
    {

    }
    else{
        
    }
    d_sprite.setPosition(d_pos); 
}
void Player::AttackEnemies(float time)
{   
    if (d_weapon)
    {
        d_weapon->Update(time, d_pos);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            d_weapon->Attack();
        }
    }
}

void Player::setState(State state)
{
    d_state = state;
}
std::shared_ptr<Weapon> Player::getWeapon() const
{
    return d_weapon;
}