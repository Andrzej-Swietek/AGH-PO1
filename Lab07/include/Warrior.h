#ifndef WARRIOR_H
#define WARRIOR_H

#include "Character.h"
#include "Sword.h"

class Warrior : public Character {
public:
    /** Warrior Constructor take character name */
    Warrior(const std::string& name);

    /** default destructor*/
    ~Warrior() = default;

    /** Specific action function override*/
    void perform_action() const override;
};

#endif // WARRIOR_H

