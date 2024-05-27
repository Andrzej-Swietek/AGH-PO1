#ifndef _GAMEOBJ_H
#define _GAMEOBJ_H

#include <iostream>
#include "Renderable.h"
#include "SceneObject.h"

class GameObject : public SceneObject
{

public:
    GameObject();

    virtual ~GameObject() = default;

    virtual void AddToScene() const override {
        std::cout << "Rendering GameObject" << std::endl;
    }

private:

};


#endif