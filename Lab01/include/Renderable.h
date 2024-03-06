#ifndef _Renderable_H
#define _Renderable_H

#include "SceneObject.h"

class Renderable : public SceneObject
{
public:
    Renderable();
    
    virtual ~Renderable() = default;

    virtual void AddToScene() const override {
        std::cout << "Drawing Renderable" << std::endl;
    }

private:
   

};




#endif