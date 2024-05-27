#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <vector>


enum class State {
    Idle,
    Attacking,
    Defending,
    Resting,
};

class Equipment {
public:
    /** Equipment default constructor*/
    virtual ~Equipment() {}

    /** Virtual method allowing to use Equipment*/
    virtual void use() const = 0;
};

class Character {
protected:
    std::string name;
    std::vector<Equipment*> equipments;
    State state;

public:
    /** Character constructor taking name as param*/
    Character(const std::string& name);

    /** Character destructor */
    virtual ~Character();

    /**
     * Method allowing user to equip eq
    */
    virtual void equip(Equipment* equip);

    /** Method allowing to set characters state */
    virtual void set_state(State new_state);

    State get_state() const;

    /**
     * Method that makes Character perform specipif action
    */
    virtual void perform_action() const = 0;

    /**
     * Method that gets users name
    */
    virtual std::string get_name() const;
};

#endif // CHARACTER_H

