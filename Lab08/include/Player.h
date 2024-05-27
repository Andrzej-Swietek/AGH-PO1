
#include "GameObject.h"
#include "Renderable.h"
#include "Collidable.h"
#include <iostream>
#include <string>

#pragma once

class Player : public GameObject, public Renderable, public Collidable {
public:
    /**
     * Player Constructor
    */
    Player();


    /**
     * Player Constructor
     * @param[in] name 
    */
    Player(std::string name);

    /**
     * Player Destructor
    */
    ~Player() = default;

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
     * Method returning name of the player if is set
     * @return name - string
    */
    virtual std::string Name() const override;


private:
    std::string _name;
};

