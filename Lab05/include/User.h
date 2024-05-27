#ifndef User_h
#define User_h

#include <string>
#include <vector>
#include "IKsiazka.h"

class User {
private:
    std::string name;
    std::vector<std::pair<IKsiazka*, std::string>> personalBookshelf;
public:
    /**
     * User main cosntructor
    */
    User(const std::string& name);

    /**
     * method returning users name - text
    */
    std::string getName() const;

    /**
     * method for adding book to reading list - takes paraps pointer to book and users comment if already read or reading currently
    */
    void addToBookshelf(IKsiazka* book, const std::string& status);

    /**
     * Method allowing user to rate the book
    */
    void rateBook(const std::string& title, int rating);

    /**
     * method  displaying 
    */
    void displayPersonalBookshelf() const;
};

#endif /* User_h */

