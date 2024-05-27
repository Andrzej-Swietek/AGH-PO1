#include "User.h"
#include <iostream>

User::User(const std::string& name) : name(name) {}

std::string User::getName() const {
    return name;
}

void User::addToBookshelf(IKsiazka* book, const std::string& status) {
    personalBookshelf.push_back(std::make_pair(book, status));
}

void User::rateBook(const std::string& title, int rating) {
    for (auto& book : personalBookshelf) {
        if (book.first->getTitle() == title) {
            book.first->addRating(rating);
            return;
        }
    }
    std::cout << "Przepraszamy - nie można ocenić książki, której się nie przeczytało.\n";
}

void User::displayPersonalBookshelf() const {
    std::cout << "Konto użytkownika " << name << ":\n";
    for (const auto& item : personalBookshelf) {
        std::cout << item.second << ":\n- " << item.first->getTitle() << '\n';
    }
}

