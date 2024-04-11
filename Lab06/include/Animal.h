#pragma once

#include <iostream>
#include <string>

/**
 * @class Abstract Class Representing Animal - base for others
 * @abstract
*/

class Animal
{
public:
    

    /**
     * Virtual Method Allowing animal to make its special sound 
     * @return no return
    */
    virtual void makeSound() const = 0;


    /**
     * Method allowing animal to eat
     * @return no return
    */
    virtual void eat() const = 0;

    
    /**
     * Method Allowing to interact with other animals
     * @return no return
    */
    virtual void interact(Animal* other) const = 0;

    /**
     * Virtual Method Allowing animal use its super skill
     * @return no return
    */
    virtual void useSkill() const = 0;

    
    /**
     * Virtual Method allowing to identify animal type
     * I use it because dynamic cast and demangle is really bad practice and makes project much slower
     * @return no return
    */
    virtual std::string identify() const = 0;

    /**
     * Virtual Destructor - default destructor
     * @return no return
    */
    virtual ~Animal() = default;
};
