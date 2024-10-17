#pragma once
#include "GameObject.h"

class FireBall : public GameObject 
{
    private:
        sf::Vector2f d_direction;
        float d_damage;
    public:
        FireBall(const sf::Texture& texture, sf::Vector2f pos, sf::Vector2f direction);
        void Update(float time);
        bool checkCollisionWithCharacters();
        bool checkCollisionWithMapBorders();
        void updateDamage(float scale);
        //lol
};