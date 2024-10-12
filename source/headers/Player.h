#pragma once
#include "AllLibs.h"
#include "Character.h"
#include <memory>
class PlayerController;

enum class State {
    Idle, 
    Run
};

class Player : public Character 
{
    private:
        State d_state;
        std::unique_ptr<PlayerController> d_controller;
    public:
        Player() = delete;
        Player(const sf::Texture& texture, sf::Vector2f start_pos, float health);
        ~Player() = default;
        void Update(float time) override;
        void setState(State state);
};