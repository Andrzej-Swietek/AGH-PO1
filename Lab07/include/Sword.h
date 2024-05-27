#ifndef SWORD_H
#define SWORD_H

#include "Character.h"

class Sword : public Equipment {
public:
    Sword();
    void use() const override;
};

#endif // SWORD_H

