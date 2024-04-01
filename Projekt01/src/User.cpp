//
// Created by andrzej on 01.04.24.
//
#include "User.h"


User::User(std::string& name) : name(name){};

std::string User::getName() const
{
    return name;
}

void User::displayBorrowedBooks() const
{
    std::cout << "Lista wypożyczonych książek przez użytkownika:\n";
    for (IKsiazka *ksiazka : borrowedBooks)
    {
        std::cout << "Tytuł: " << ksiazka->getTitle() << "\n\n";
    }
}