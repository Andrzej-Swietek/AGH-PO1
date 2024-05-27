//
// Created by andrzej on 01.04.24.
//
#include "Czasopismo.h"


Czasopismo::Czasopismo(std::string title, std::string author, int id, std::string genre, int shelf_id)
        : IKsiazka(title, author, id, genre, shelf_id)
{
}

Czasopismo::Czasopismo(std::string title, std::string author, int id, std::string genre, int shelf_id, bool available)
        : IKsiazka(title, author, id, genre, shelf_id, available)
{
}


// Copy Constructor
Czasopismo::Czasopismo(const Czasopismo& other)
        : IKsiazka(other)
{
    std::cout << "Copy Constructor called" << std::endl;
}


// Move Constructor
Czasopismo::Czasopismo(Czasopismo&& other) noexcept
        : IKsiazka(std::move(other))
{
    std::cout << "Move Constructor called" << std::endl;
}


///


// Copy Assignment Operator
Czasopismo& Czasopismo::operator=(const Czasopismo& other) {
    std::cout << "Copy Assignment Operator called" << std::endl;
    if (this != &other) {
        IKsiazka::operator=(other); // Invoke base class copy assignment operator
    }
    return *this;
}


// Move Assignment Operator
Czasopismo& Czasopismo::operator=(Czasopismo&& other) noexcept {
    std::cout << "Move Assignment Operator called" << std::endl;
    if (this != &other) {
        IKsiazka::operator=(std::move(other)); // Invoke base class move assignment operator
    }
    return *this;
}