#ifndef _GUTILS_H
#define _GUTILS_H

#include "GameObject.h"
#include "Renderable.h"
#include "PlayerCharacter.h"
#include <typeinfo>

namespace gutils
{
    void handleGameObject(GameObject* gameobject);

    void handleRenderable(Renderable* renderable);
}

#endif