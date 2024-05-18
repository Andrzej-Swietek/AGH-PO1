// Enemy.cpp
#include "Enemy.h"
#include "GameObject.h"
#include <iostream>

Enemy::Enemy() {
    this->_name = "Unnamed Enemy";
}

Enemy::Enemy(std::string name): _name(name) {
}


void Enemy::render() const {
    std::cout << "Rendering object\n";
}

void Enemy::collide() const {
    std::cout << "Handling collision\n";
}

void Enemy::update() const {
    std::cout << "Updating object\n";
}

void Enemy::action() const {
    std::string displayed_name = _name  == "" ? "Unnamed Enemy" : _name;
    std::cout << "Performing enemy-specific action for " << displayed_name;
    std::cout << ": \n";
    this->render();
    this->collide();
    this->update();
}

std::string Enemy::Name() const {
    if(_name != "")
        return _name;
    else 
        return "Unnamed Enemy";
}