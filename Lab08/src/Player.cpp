// Player.cpp
#include "Player.h"
#include <iostream>

Player::Player() {
    this->_name = "Unnamed Player";
}

Player::Player(std::string name): _name(name) {
}


void Player::render() const {
    std::cout << "Rendering object\n";
}

void Player::collide() const {
    std::cout << "Handling collision\n";
}

void Player::update() const {
    std::cout << "Updating Object\n";
}

void Player::action() const {
    std::string displayed_name = _name  == "" ? "Unnamed Player" : _name;
    std::cout << "Performing player-specific action for " << displayed_name;
    std::cout << ": \n";
    this->render();
    this->update();
}

std::string Player::Name() const {
    if(_name != "")
        return _name;
    else 
        return "Unnamed Player";
}