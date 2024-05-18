// GameObject.cpp
#include "GameObject.h"

std::vector<GameObject*> GameObject::activeGameObjects;

GameObject* GameObject::addGameObject(GameObject* object) {
    activeGameObjects.push_back(object);
    return object;
}

void GameObject::destroyGameObject(GameObject* object) {
    auto it = std::find(activeGameObjects.begin(), activeGameObjects.end(), object);
    if (it != activeGameObjects.end()) {
        delete *it;
        activeGameObjects.erase(it);
    }
}

void GameObject::destroyGameObjects() {
    for (GameObject* object : activeGameObjects) {
        delete object;
    }
    activeGameObjects.clear();
}

const std::vector<GameObject*>& GameObject::ActiveGameObjects() {
    return activeGameObjects;
}
