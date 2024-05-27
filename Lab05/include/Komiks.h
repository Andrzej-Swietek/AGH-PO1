#ifndef Komiks_h
#define Komiks_h

#include "IKsiazka.h"

class Komiks : public IKsiazka {
private:
    std::string title;
    std::string author;
    int ID;
    std::string genre;
    std::vector<int> ratings;
public:
    /**
     * Main constructor
    */
    Komiks(const std::string& title, const std::string& author, int ID, const std::string& genre);

    /**
    * method returning Iksiazka title - text
    */
    std::string getTitle() const override;

    /**
     * method returning Iksiazka title - text
    */
    std::string getAuthor() const override;

    /**
     * method returning Iksiazka title - text
    */
    int getID() const override;

    /**
     * method returning Iksiazka title - text
    */
    std::string getGenre() const override;

    /**
     * method adding new rating value - no return
    */
    void addRating(int rating) override;

    /**
     * method returning avarage reting for book - double
    */
    double getAverageRating() const override;
};

#endif /* Komiks_h */


