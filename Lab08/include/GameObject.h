// GameObject.h
#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <iostream>
#include <vector>
#include <algorithm>

class GameObject {
public:
    /**
     * Game Object Virtual Destructor
    */
    virtual ~GameObject() {}

    /**
     * Method allwoing to render object
    */
    virtual void render() const = 0;

    /**
     * Method Allowing object to collide
    */
    virtual void collide() const = 0;

    /**
     * Method Allowing object to be updated
    */
    virtual void update() const = 0;

    /**
     * Method Allowing object to take action
    */
    virtual void action() const = 0;


    /**
     * Method returning name of the entity if is set
     * @return name - string
    */
    virtual std::string Name() const = 0;


    /**
     * Method Allowing to add new object to sceen ( active objects )
     * @param[in] object pointer to GameObject
    */
    static GameObject* addGameObject(GameObject* object);


    /**
     * Method Allowing to destroy gameobject
     * @param[in] object pointer to GameObject
    */
    static void destroyGameObject(GameObject* object);


    /**
     * Method Allowing to destroy all gameobjects
    */
    static void destroyGameObjects();

    /**
     * Method returning vector of active objects
    */
    static const std::vector<GameObject*>& ActiveGameObjects();

protected:
    static std::vector<GameObject*> activeGameObjects;
};

#endif // GAME_OBJECT_H
