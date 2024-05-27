#include "Komiks.h"

Komiks::Komiks(const std::string& title, const std::string& author, int ID, const std::string& genre)
    : title(title), author(author), ID(ID), genre(genre) {}

std::string Komiks::getTitle() const {
    return title;
}

std::string Komiks::getAuthor() const {
    return author;
}

int Komiks::getID() const {
    return ID;
}

std::string Komiks::getGenre() const {
    return genre;
}

void Komiks::addRating(int rating) {
    ratings.push_back(rating);
}

double Komiks::getAverageRating() const {
    if (ratings.empty())
        return -1; // Brak ocen
    double sum = 0;
    for (int rating : ratings)
        sum += rating;
    return sum / ratings.size();
}

