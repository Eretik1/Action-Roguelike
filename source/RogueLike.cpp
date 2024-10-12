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
    file_back.loadFromFile("Y:/Programming/Action-Roguelike/img/background.jpg");
    sf::Sprite background(file_back);
    Textures::setTextures();

    Player* player = new Player(Textures::player_texture, sf::Vector2f((float)0, (float)0), (float)100);

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
        window.clear(sf::Color::White);
        window.draw(background);
        window.draw(player->getSprite());
        window.display();

    }
    // delete player;
    return 0;
}