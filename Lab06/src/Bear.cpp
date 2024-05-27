#include "Bear.h"


void Bear::makeSound() const
{
    std::cout << "Bear grunts\n";
}

void Bear::eat() const
{
    std::cout << "Bear eats fish\n\n";
}

void Bear::interact(Animal*other) const
{   
    std::cout << "Bear grunts at " << (other->identify()) << "\n";
}

void Bear::useSkill() const
{
    this->bellyDrum();
}

void Bear::bellyDrum() const
{
    std::cout << "Bear uses Belly Drum skill\n";
}

std::string Bear::identify() const 
{
    return "Bear";
}

Bear::~Bear(){};