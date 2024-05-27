#ifndef Czasopismo_h
#define Czasopismo_h

#include "IKsiazka.h"

class Czasopismo : public IKsiazka {
private:
    std::string title;
    std::string author;
    int ID;
    std::string genre;
    std::vector<int> ratings;
public:
    /**
     * main constructor
    */
    Czasopismo(const std::string& title, const std::string& author, int ID, const std::string& genre);

    /**
     * method returning Iksiazka title - text
    */
    std::string getTitle() const override;

    /**
     * Mtehod returning name of author - text
    */
    std::string getAuthor() const override;

    /**
     * method returning id of book - number 
    */
    int getID() const override;


    /**
     * Method returning genre of book -text 
    */
    std::string getGenre() const override;

    /**
     * Mtehod taking param new rating and  no returing anything
     * modifing ratings for given book
    */
    void addRating(int rating) override;

    /*
        Method returning average rating of users for this book
    */
    double getAverageRating() const override;
};

#endif /* Czasopismo_h */


