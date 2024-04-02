//
// Created by andrzej on 01.04.24.
//
#include "Komiks.h"


Komiks::Komiks(std::string title, std::string author, int id, std::string publisher, std::string genre, int shelf_id)
        : IKsiazka(title, author, id, genre, shelf_id), publisher(publisher)
{
}

Komiks::Komiks(std::string title, std::string author, int id, std::string publisher, std::string genre, int shelf_id, bool available)
        : IKsiazka(title, author, id, genre, shelf_id, available), publisher(publisher)
{
}


// Copy Constructor
Komiks::Komiks(const Komiks& other)
        : IKsiazka(other), publisher(other.publisher)
{
    std::cout << "Copy Constructor called" << std::endl;
}


// Move Constructor
Komiks::Komiks(Komiks&& other) noexcept
        : IKsiazka(std::move(other)), publisher(std::move(other.publisher))
{
    std::cout << "Move Constructor called" << std::endl;
}


///


// Copy Assignment Operator
Komiks& Komiks::operator=(const Komiks& other) {
    std::cout << "Copy Assignment Operator called" << std::endl;
    if (this != &other) {
        IKsiazka::operator=(other); // Invoke base class copy assignment operator
        this->publisher = other.publisher;
    }
    return *this;
}


// Move Assignment Operator
Komiks& Komiks::operator=(Komiks&& other) noexcept {
    std::cout << "Move Assignment Operator called" << std::endl;
    if (this != &other) {
        std::string tmp_publisher = other.publisher;
        IKsiazka::operator=(std::move(other)); // Invoke base class move assignment operator
        this->publisher = std::move(tmp_publisher);
    }
    return *this;
}