//
// Created by andrzej on 01.04.24.
//
#include "Library.h"


Library::~Library()
{
    for (IKsiazka *ksiazka : books)
    {
        delete ksiazka;
    }
}


void Library::addMaterial(IKsiazka *material)
{
    books.push_back(material);
}



void Library::borrowBook(std::string title, User &user)
{
    for (IKsiazka* ksiazka : books) {
        if (ksiazka->getTitle() == title) {
            if ( !ksiazka->getAvailability() ) {
                std::cout << "Przepraszamy, książka \"" << title << "\" jest już wypożyczona.\n"; return;
            }

            ksiazka->setAvailability(false);
            user.borrowBook(ksiazka);
            std::cout << "Użytkownik " << user.getName() << " wypożyczył książkę: " << title << "\n";
            return;
        }
    }

    std::cout << "Przepraszamy, książka \"" << title << "\" nie istnieje w bibliotece.\n";
}


void Library::returnBook(std::string title, User &user)
{
    for (IKsiazka *ksiazka : books) {
        if( ksiazka->getTitle() == title && !ksiazka->getAvailability() ) {
            ReturnBookResult result = user.returnBook(title);
            std::cout << result.message << std::endl;
            return;
        }
    }

    std::cout << "Przepraszamy, książka " << title << " nie została wypożyczona przez tego użytkownika lub nie istnieje.\n";
}


void Library::displayAllBooks() const
{
    std::cout << "\nLista książek w bibliotece:\n";
    for (IKsiazka *ksiazka : books)
    {
        std::cout << "Tytuł: " << ksiazka->title << std::endl;
        std::cout << "Autor: " << ksiazka->author << std::endl;
        std::cout << "Id ksiazki: " << ksiazka->id << std::endl;
        std::cout << "Gatunek: " << ksiazka->genre << std::endl;
        std::cout << "Na półce: " << ksiazka->getShelfId() << std::endl;
        std::cout << "Status: " << (ksiazka->getAvailability() ? "Dostępny" : "Niedostępny") << std::endl;
        std::cout << std::endl;
    }
}