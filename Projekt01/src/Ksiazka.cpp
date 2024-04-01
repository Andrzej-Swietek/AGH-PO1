//
// Created by andrzej on 01.04.24.
//
#include "Ksiazka.h"

Ksiazka::Ksiazka(std::string &title, std::string &author, int id, std::string &genre, int shelf_id)
    : title(title), author(author), id(id), genre(genre) ,shelf_id(shelf_id)
{
}

std::ostream &operator<<(std::ostream &os, const Ksiazka &ksiazka) {
    os << "[ BOOK ]: " " id: " << ksiazka.id << " title: " << ksiazka.title << " author: "
       << ksiazka.author << " genre: " << ksiazka.genre << " shelf_id: " << ksiazka.shelf_id;
    return os;
}

void Ksiazka::wyswietlInformacje() {
    std::cout << "Mój tytuł: " << this->title << ", author: " << this->author << ", id: " << this->id << "leżę na półce: " << this->shelf_id << std::endl;
}

int Ksiazka::getShelfId() const {
    return this->shelf_id;
}

void Ksiazka::setShelfId(int newId) {
    this->shelf_id = newId;
}
