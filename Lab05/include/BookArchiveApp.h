#ifndef BookArchiveApp_h
#define BookArchiveApp_h

#include <vector>
#include "IKsiazka.h"
#include "User.h"

class BookArchiveApp {
private:
    std::vector<IKsiazka*> materialBase;
public:
    /**
     * method allowing to add new book to collection
    */
    void addMaterialToBase(IKsiazka* item);

    /**
     * method alling to add to reame for given user
    */
    void putOnBookshelf(const std::string& title, User& user, const std::string& status);

    /**
     * Method allowing to grade book for user
    */
    void rateBook(const std::string& title, User& user, int rating);

    /**
     * method displaying all books in database
    */
    void displayAllBooks() const;
};

#endif /* BookArchiveApp_h */

