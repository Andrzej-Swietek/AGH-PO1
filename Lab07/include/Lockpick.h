#ifndef LOCKPICK_H
#define LOCKPICK_H

#include "Character.h"

class Lockpick : public Equipment {
public:
    Lockpick();
    void use() const override;
};

#endif // LOCKPICK_H

