// Enemy.h
#ifndef ENEMY_H
#define ENEMY_H

#include<iostream>

#include "GameObject.h"
#include "Renderable.h"
#include "Collidable.h"
#include "Updatable.h"



class Enemy : public GameObject, public Renderable, public Collidable, public Updatable {
public:


    /**
     * Enemy defualt Constructor
    */
    Enemy();

    /**
     * Enemy with name Constructor
    */
    Enemy(std::string name);

    /**
     * Enemy defualt Destructor
    */
    ~Enemy() = default;

   /**
     * Method allwoing to render object
    */
    virtual void render() const override;

    /**
     * Method Allowing object to collide
    */
    virtual void collide() const override;

    /**
     * Method Allowing object to be updated
    */
    virtual void update() const override;

    /**
     * Method Allowing object to take action
    */
    virtual void action() const override;


    /**
     * Method returning name of the enemy if is set
     * @return name - string
    */
    virtual std::string Name() const override;

private:
    std::string _name = "";
};

#endif // ENEMY_H
