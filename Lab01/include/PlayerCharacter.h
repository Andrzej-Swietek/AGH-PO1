#ifndef _PLAYERCHARACTER_H
#define _PLAYERCHARACTER_H

#include <iostream>
#include "gutils.h"

#include "GameObject.h"
#include "Renderable.h"

class PlayerCharacter : public Renderable, public GameObject
{

public:
    PlayerCharacter();

    ~PlayerCharacter();

    void attack() const;


private:

};



#endif