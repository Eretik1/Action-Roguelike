#pragma once
enum class Direction : bool{
    LEFT = 0,
    RIGHT = 1,
};

class Character
{
    protected:                          // используем protected чтобы наследуемые классы тоже могли использовать члены класса и методы
        float d_health; 
        float d_speed;
        float d_attackspeed;
        float d_damage;
        sf::Vector2f d_size;
        sf::Vector2f d_pos;
        sf::Sprite d_sprite;
        Direction d_direction = Direction::RIGHT;

    public:
        virtual ~Character();
        virtual void Update(float time) = 0; // абстрактная функция для полиморфизма, будем ее переопределять в подклассах, меняя ее поведение под соотвествующий класс.

        void takeDamage(float damage);
        void setPosition(sf::Vector2f &pos);
        void setDirection(Direction direction);

        float getHealth() const;
        float getSpeed() const;
        sf::Vector2f getSize() const;
        sf::Vector2f getPos() const;
        sf::Sprite getSprite() const;
        Direction getDirection() const;
};