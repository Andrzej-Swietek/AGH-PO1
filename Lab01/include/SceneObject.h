#ifndef _SceneObject_H
#define _SceneObject_H

#include <iostream>

class SceneObject {
    virtual ~SceneObject() = default;

    virtual AddToScene() const = 0;
};