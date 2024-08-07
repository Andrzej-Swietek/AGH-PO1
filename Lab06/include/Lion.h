#pragma once

#include <iostream>
#include <string>
#include "Animal.h"


/**
 * @class Class representing Lion
 * @implements Animal
*/

class Lion : public Animal
{
public:
   
    /**
     * Method Allowing animal to make its special sound 
     * @return no return
    */
    void makeSound() const override;


    /**
     * Method allowing animal to eat
     * @return no return
    */
    void eat() const override;


    /**
     * Allowing to interact with other animals
     * @return no return
    */
    void interact(Animal *other) const override;


    /**
     * Method Allowing animal use its super skill
     * @return no return
    */
    void useSkill() const override;


    /**
     * Special skill
     * @return no return
    */
    void hyperVoice() const;


    /**
     * Method allowing to identify animal type
     * @return no return
    */
    std::string identify() const override;


    /**
     * Destructor - default destructor
     * @return no return
    */
    ~Lion();
};
