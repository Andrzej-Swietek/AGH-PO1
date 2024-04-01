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


bool Ksiazka::operator==(const Ksiazka &rhs) const {
    const IKsiazka *thisIKsiazka = dynamic_cast<const IKsiazka *>(this);
    const IKsiazka *rhsIKsiazka = dynamic_cast<const IKsiazka *>(&rhs);

    if (!thisIKsiazka || !rhsIKsiazka)  return false;

    return id == rhs.id &&
           title == rhs.title &&
           author == rhs.author &&
           genre == rhs.genre &&
           shelf_id == rhs.shelf_id;
}


bool Ksiazka::operator!=(const Ksiazka &rhs) const {
    return !(rhs == *this);
}

bool Ksiazka::operator<(const Ksiazka &rhs) const {
    return this->shelf_id < rhs.shelf_id;
}

bool Ksiazka::operator>(const Ksiazka &rhs) const {
    return rhs.shelf_id < this->shelf_id;
}

bool Ksiazka::operator<=(const Ksiazka &rhs) const {
    return !(rhs < *this);
}

bool Ksiazka::operator>=(const Ksiazka &rhs) const {
    return !(*this < rhs);
}

std::string Ksiazka::getTitle() {
    return this->title;
}
