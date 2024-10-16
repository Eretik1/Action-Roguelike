#pragma once
#include "AllLibs.h"
#include "Character.h"
#include <memory>
class PlayerController;

class Weapon;
enum class WeaponType;

enum class State {
    Idle, 
    Run
};

class Player : public Character 
{
    private:
        State d_state;
        std::unique_ptr<PlayerController> d_controller;
        std::shared_ptr<Weapon> d_weapon;
    public:
        Player() = delete;
        Player(const sf::Texture& texture, sf::Vector2f start_pos, float health);
        ~Player() = default;
        void Update(float time) override;
        void initWeapon(WeaponType weapon_type, float damage, const sf::Texture& texture);
        void AttackEnemies(float time);
        void setState(State state);
};