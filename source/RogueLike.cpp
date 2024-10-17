#include "headers/Constants.h"
#include "headers/Player.h"
#include "headers/PlayerController.h"
#include "headers/Textures.h"
int main()
{
    sf::RenderWindow window(
        sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
        "Game");
    sf::Texture file_back;
    file_back.loadFromFile("../img/floor.png");
    sf::Texture FB;
    FB.loadFromFile("../img/FB.png");
    sf::Sprite background(file_back);
    Textures::setTextures();
    sf::Vector2u windowSize = window.getSize();
    unsigned int tileSizeX = file_back.getSize().x;
    unsigned int tileSizeY = file_back.getSize().y;
    Player* player = new Player(Textures::player_texture, sf::Vector2f((float)960, (float)540), (float)100);
    player->initWeapon(1.0, FB);
    sf::Clock clock;
    while (window.isOpen()) 
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time /= 300;
        sf::Event WindowEvent;

        while (window.pollEvent(WindowEvent))
         {
            if (WindowEvent.type == sf::Event::Closed)
                window.close();
        }
        player->Update(time);
        player->AttackEnemies(time);
        player->getWeapon()->Aim(); 
        window.clear(sf::Color::White);
        for (unsigned int x = 0; x < windowSize.x; x += tileSizeX-5) {
            for (unsigned int y = 0; y < windowSize.y; y += tileSizeY-5) {
                background.setPosition(x, y);
                window.draw(background);
            }
        }
        auto weapon = player->getWeapon();
        auto bullets = weapon->getFireBalls();
        for (auto b : bullets)
        {
            window.draw(b->getSprite());
        }
        window.draw(player->getSprite());
        window.display();

    }
    return 0;
}