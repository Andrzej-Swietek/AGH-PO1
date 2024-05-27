//
// Created by andrzej on 01.04.24.
//
#include "User.h"


User::User(std::string name) : name(name){};

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

void User::borrowBook(IKsiazka* new_book) {
    this->borrowedBooks.push_back(new_book);
}


ReturnBookResult User::returnBook(std::string title) {
    for (std::vector<IKsiazka*>::iterator it = borrowedBooks.begin(); it != borrowedBooks.end(); ++it) { // iter over borrowed books
        if ((*it)->getTitle() == title) {
            (*it)->setAvailability(true);
            borrowedBooks.erase(it);        // Remove the book from the vector
            return ReturnBookResult{
                    .success = true,
                    .message = "Użytkownik " + getName() + " zwrócił książkę: " + title + "\n"
            };
        }
    }
    return ReturnBookResult{
            .success = false,
            .message = "Przepraszamy, książka " + title + " nie została wypożyczona przez tego użytkownika lub nie istnieje.\n"
    };
}
