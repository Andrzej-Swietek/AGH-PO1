#include "Warrior.h"
#include <iostream>

Warrior::Warrior(const std::string& name) : Character(name) {}

void Warrior::perform_action() const {
    if (this->get_state() == State::Idle)
        std::cout << this->get_name() << " the Warrior is idling around." << std::endl;
    else if (this->get_state() == State::Attacking)
        std::cout << this->get_name() << " the Warrior swings a sword!" << std::endl;
}

