#ifndef STAFF_H
#define STAFF_H

#include "Character.h"

class Staff : public Equipment {
public:
    Staff();
    void use() const override;
};

#endif // STAFF_H

