#include "Lion.h"


void Lion::makeSound() const
{
    std::cout << "Lion roars\n";
}


void Lion::eat() const
{
    std::cout << "Lion eats meet\n\n";
}


void Lion::interact(Animal*other) const
{   
    std::cout << "Lion roars at " << (other->identify()) << "\n";
}


void Lion::useSkill() const
{
    this->hyperVoice();
}


void Lion::hyperVoice() const
{
    std::cout << "Lion uses Hyper Voice skill\n";
}


std::string Lion::identify() const 
{
    return "Lion";
}


Lion::~Lion(){};