#ifndef THIEF_H
#define THIEF_H

#include "Character.h"
#include "Lockpick.h"

class Thief : public Character {
public:
    Thief(const std::string& name);

    ~Thief() = default;

    void perform_action() const override;
};

#endif // THIEF_H

