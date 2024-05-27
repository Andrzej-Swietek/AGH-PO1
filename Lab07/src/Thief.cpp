#include "Thief.h"

Thief::Thief(const std::string& name) : Character(name) {}

void Thief::perform_action() const {
    if (state == State::Idle)
        std::cout << name << " the Thief is idling around." << std::endl;
    else if (state == State::Attacking)
        std::cout << name << " the Thief is using lockpick." << std::endl;
}

