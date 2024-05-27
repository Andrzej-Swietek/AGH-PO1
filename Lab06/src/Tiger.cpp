#include "Tiger.h"


void Tiger::makeSound() const
{
    std::cout << "Tiger growls\n";
}

void Tiger::eat() const
{
    std::cout << "Tiger eats meet\n\n";
}

void Tiger::interact(Animal*other) const
{
    std::cout << "Tiger stares at " << (other->identify()) << "\n";
}

void Tiger::useSkill() const
{
    this->flareBlitz();
}

void Tiger::flareBlitz() const
{
    std::cout << "Tiger uses Flare Blitz skill\n";
}

std::string Tiger::identify() const 
{
    return "Tiger";
}

Tiger::~Tiger(){};