#include "Character.h"

Character::Character(const std::string& name) : name(name), state(State::Idle) {}

Character::~Character() {
    // for (auto* equipment : equipments)
    //     if(equipment)
    //         delete equipment;
    
    equipments.clear();
}


void Character::equip(Equipment* equip) {
    equipments.push_back(equip);
}

void Character::set_state(State new_state) {
    state = new_state;
}

State Character::get_state() const {
    return state;
}

std::string Character::get_name() const {
    return name;
}