#pragma once
#include<iostream>
#include<string>

class Equipment {
public: 
    /** Eq constructor*/
    Equipment(std::string name): name(name){}

    virtual void use();

    /** Destrutcuor virtual */
    virtual ~Equipment() = default;
protected:
    std::string name;
};