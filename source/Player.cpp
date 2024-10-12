#include "Player.h"
#include "PlayerController.h"
#include <memory>
Player::Player(const sf::Texture &texture, sf::Vector2f start_pos, float health)
{
    d_pos = start_pos;
    d_health = health;

    d_controller = std::make_unique<PlayerController>();
    
    d_sprite.setTexture(texture);
    d_size = sf::Vector2f(d_sprite.getTextureRect().width, d_sprite.getTextureRect().height);

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

void Player::setState(State state)
{
    d_state = state;
}