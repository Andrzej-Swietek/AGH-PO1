//
// Created by andrzej on 02.04.24.
//
#include "IKsiazka.h"


/// ================== Constructors & Destructors ==================


IKsiazka::IKsiazka(std::string &title, std::string &author, int id, std::string &genre, int shelf_id)
        : title(title), author(author), id(id), genre(genre) ,shelf_id(shelf_id), available(true)
{
}

IKsiazka::IKsiazka(std::string &title, std::string &author, int id, std::string &genre, int shelf_id, bool available)
        : title(title), author(author), id(id), genre(genre) ,shelf_id(shelf_id), available(available)
{
}

// Copy Constructor
IKsiazka::IKsiazka(const IKsiazka& other)
        : id(other.id), title(other.title), author(other.author), genre(other.genre), shelf_id(other.shelf_id), available(other.available)
{
    std::cout << "Copy Constructor called" << std::endl;
}

// Move Constructor
IKsiazka::IKsiazka(IKsiazka&& other) noexcept
        : id(std::move(other.id)), title(std::move(other.title)), author(std::move(other.author)),
          genre(std::move(other.genre)), shelf_id(std::move(other.shelf_id)), available(std::move(other.available))
{
    std::cout << "Move Constructor called" << std::endl;
}



///



void IKsiazka::wyswietlInformacje() {
    std::cout << "Mój tytuł: " << this->title << ", author: " << this->author << ", id: " << this->id << ", leżę na półce: " << this->shelf_id << std::endl;
}


/// ======================= Getters & Setter =======================


std::string IKsiazka::getTitle() {
    return this->title;
}


int IKsiazka::getShelfId() const {
    return this->shelf_id;
}


void IKsiazka::setShelfId(int newId) {
    this->shelf_id = newId;
}


void IKsiazka::setAvailability(bool newValue) {
    this->available = newValue;
}


void IKsiazka::toggleAvailability() {
    this->available = !this->available;
}


bool IKsiazka::getAvailability() const {
    return this->available;
}


/// ====================== Operator Overloads ======================

std::ostream &operator<<(std::ostream &os, const IKsiazka &ksiazka) {
    os << "[ BOOK ]: " " id: " << ksiazka.id << " title: " << ksiazka.title << " author: "
       << ksiazka.author << " genre: " << ksiazka.genre << " shelf_id: " << ksiazka.shelf_id;
    return os;
}


bool IKsiazka::operator==(const IKsiazka &rhs) const {
    const IKsiazka *thisIKsiazka = dynamic_cast<const IKsiazka *>(this);
    const IKsiazka *rhsIKsiazka = dynamic_cast<const IKsiazka *>(&rhs);

    if (!thisIKsiazka || !rhsIKsiazka)  return false;

    return id == rhs.id &&
           title == rhs.title &&
           author == rhs.author &&
           genre == rhs.genre &&
           shelf_id == rhs.shelf_id;
}


bool IKsiazka::operator!=(const IKsiazka &rhs) const {
    return !(rhs == *this);
}


bool IKsiazka::operator<(const IKsiazka &rhs) const {
    return this->shelf_id < rhs.shelf_id;
}


bool IKsiazka::operator>(const IKsiazka &rhs) const {
    return rhs.shelf_id < this->shelf_id;
}


bool IKsiazka::operator<=(const IKsiazka &rhs) const {
    return !(rhs < *this);
}


bool IKsiazka::operator>=(const IKsiazka &rhs) const {
    return !(*this < rhs);
}


// Copy Assignment Operator
IKsiazka& IKsiazka::operator=(const IKsiazka& other) {
    std::cout << "Copy Assignment Operator called" << std::endl;
    if (this != &other) {
        id = other.id;
        title = other.title;
        author = other.author;
        genre = other.genre;
        shelf_id = other.shelf_id;
        available = other.available;
    }
    return *this;
}


// Move Assignment Operator
IKsiazka& IKsiazka::operator=(IKsiazka&& other) noexcept {
    std::cout << "Move Assignment Operator called" << std::endl;
    if (this != &other) {
        id = std::move(other.id);
        title = std::move(other.title);
        author = std::move(other.author);
        genre = std::move(other.genre);
        shelf_id = std::move(other.shelf_id);
        available = std::move(other.available);
    }
    return *this;
}

