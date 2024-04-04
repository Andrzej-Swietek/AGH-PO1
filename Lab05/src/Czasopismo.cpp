#include "Czasopismo.h"

Czasopismo::Czasopismo(const std::string& title, const std::string& author, int ID, const std::string& genre)
    : title(title), author(author), ID(ID), genre(genre) {}

std::string Czasopismo::getTitle() const {
    return title;
}

std::string Czasopismo::getAuthor() const {
    return author;
}

int Czasopismo::getID() const {
    return ID;
}

std::string Czasopismo::getGenre() const {
    return genre;
}

void Czasopismo::addRating(int rating) {
    ratings.push_back(rating);
}

double Czasopismo::getAverageRating() const {
    if (ratings.empty())
        return -1; // Brak ocen
    double sum = 0;
    for (int rating : ratings)
        sum += rating;
    return sum / ratings.size();
}

