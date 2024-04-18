#include "Wizard.h"
#include <iostream>


Wizard::Wizard(const std::string& name) : Character(name) {}

void Wizard::perform_action() const {
    if (this->get_state() == State::Idle)
        std::cout << this->get_name() << " the Wizard is idling around." << std::endl;
    else if (this->get_state() == State::Attacking)
        std::cout << this->get_name() << " the Wizard is casting a spell with staff!" << std::endl;
}

