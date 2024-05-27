#ifndef WIZARD_H
#define WIZARD_H

#include "Character.h"
#include "Staff.h"

class Wizard : public Character {
public:
    /** Wizard Constructor take character name */
    Wizard(const std::string& name);

    /** default destructor*/
    ~Wizard() = default;

    /** Specific action function override*/
    void perform_action() const override;
};

#endif // WIZARD_H

