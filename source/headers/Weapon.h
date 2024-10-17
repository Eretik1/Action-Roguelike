#pragma once
#include "FireBall.h"
#include <memory>
#include "Character.h"
#include "Timer.h"
class Weapon 
{
    private:
        std::vector<std::shared_ptr<FireBall>> d_fireballs;
        sf::Texture d_fireball_texture;
        
        sf::Vector2f d_pos;
        sf::Vector2f d_direction;
        float d_damage_scale = 1.f;
        float d_angle = 1.f;

        float                  d_reload_time = 1.f;
        std::unique_ptr<Timer> d_reload_timer;
    public:
        Weapon(const sf::Texture& fireball_texture, sf::Vector2f pos, float damage_scale, float reload_timer);
        ~Weapon() = default;

        void Update(float time, sf::Vector2f pos);
        void Attack();
        void updateAttackSpeed(float scale);
        sf::Vector2f Aim();

        std::vector<std::shared_ptr<FireBall>> getFireBalls() const;
};