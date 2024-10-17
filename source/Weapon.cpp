#include "headers/Weapon.h"
#include "headers/Character.h"
#include "headers/Constants.h"
#include "headers/FireBall.h"
#include "AllLibs.h"
#include <cmath>
Weapon::Weapon(const sf::Texture& fireball_texture, sf::Vector2f pos, float damage_scale, float reload_time)
{
    d_fireball_texture = fireball_texture;
    d_pos = pos;
    d_damage_scale = damage_scale;
    d_reload_time = reload_time;
    d_reload_timer = std::make_unique<Timer>(d_reload_time);    
}

void Weapon::Update(float time, sf::Vector2f pos)
{
    d_pos = pos;

    if (!d_fireballs.empty())
    {
        for (auto iter = d_fireballs.begin(); iter != d_fireballs.end(); iter++)
        {
            auto fireball = *iter;
            if (fireball)
            {
                fireball->Update(time);
            }
        }
    }
}
void Weapon::Attack()
{
    if (!d_reload_timer->isRunning())
    {
        d_direction = Aim();
        auto new_fireball = std::make_shared<FireBall>(d_fireball_texture, d_pos, d_direction);
        d_fireballs.push_back(new_fireball);
        d_reload_timer->Start();
    }
}

sf::Vector2f Weapon::Aim()
{
    sf::Vector2f playerCenter;
    sf::Vector2f mousePosWindow;
    sf::Vector2f aimDir;
    sf::Vector2f aimDirNorm;
    playerCenter = sf::Vector2f(d_pos.x, d_pos.y);
    mousePosWindow = sf::Vector2f(sf::Mouse::getPosition());
    aimDir = mousePosWindow - playerCenter;
    aimDirNorm = aimDir / (float)sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));

    return aimDirNorm;
}

std::vector<std::shared_ptr<FireBall>> Weapon::getFireBalls() const
{
    return d_fireballs;
}

