#include "Ksiazka.h"

Ksiazka::Ksiazka(const std::string& title, const std::string& author, int ID, const std::string& genre)
    : title(title), author(author), ID(ID), genre(genre) {}

std::string Ksiazka::getTitle() const {
    return title;
}

std::string Ksiazka::getAuthor() const {
    return author;
}

int Ksiazka::getID() const {
    return ID;
}

std::string Ksiazka::getGenre() const {
    return genre;
}

void Ksiazka::addRating(int rating) {
    ratings.push_back(rating);
}

double Ksiazka::getAverageRating() const {
    if (ratings.empty())
        return -1; // Brak ocen
    double sum = 0;
    for (int rating : ratings)
        sum += rating;
    return sum / ratings.size();
}

