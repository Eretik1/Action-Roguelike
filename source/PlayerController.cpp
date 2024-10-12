#include "headers/PlayerController.h"
#include "headers/Player.h"
#include "headers/Constants.h"

bool PlayerController::controller_created = false;

PlayerController::PlayerController() {
    if (controller_created) {
        throw std::logic_error("Only one instance of PlayerController is allowed.");
    }
    controller_created = true;
}

void PlayerController::controllPlayer(Player* player, float time) {
    sf::Vector2f updated_pos = player->getPos();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        updated_pos.x -= 0.25f * time;
        player->setState(State::Run);
        player->setDirection(Direction::LEFT);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        updated_pos.x += 0.25f * time;
        player->setState(State::Run);
        player->setDirection(Direction::RIGHT);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        updated_pos.y -= 0.25f * time;
        player->setState(State::Run);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        updated_pos.y += 0.25f * time;
        player->setState(State::Run);
    }

    player->setPosition(updated_pos);
}
