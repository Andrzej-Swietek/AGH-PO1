#include "BookArchiveApp.h"
#include <iostream>
#include <algorithm>

void BookArchiveApp::addMaterialToBase(IKsiazka* item) {
    materialBase.push_back(item);
}

void BookArchiveApp::putOnBookshelf(const std::string& title, User& user, const std::string& status) {
    bool found = false;
    for (auto& book : materialBase) {
        if (book->getTitle() == title) {
            user.addToBookshelf(book, status);
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Przepraszamy - w naszej bazie nie ma książki pod tytułem \"" << title << "\".\n";
    }
}

void BookArchiveApp::rateBook(const std::string& title, User& user, int rating) {
    user.rateBook(title, rating);
}

void BookArchiveApp::displayAllBooks() const {
    for (const auto& book : materialBase) {
        std::cout << "- " << book->getTitle() << ", " << book->getAuthor() << ", " << book->getGenre();
        if (book->getAverageRating() == -1) {
            std::cout << ", Brak ocen\n";
        } else {
            std::cout << ", Średnia ocena: " << book->getAverageRating() << "/10\n";
        }
    }
}

