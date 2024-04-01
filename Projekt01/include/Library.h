//
// Created by andrzej on 01.04.24.
//

#ifndef POINT_LIBRARY_H
#define POINT_LIBRARY_H
#include<iostream>
#include <string>
#include <vector>

#include "IKsiazka.h"
#include "User.h"

class Library {
public:
    /**
     * @brief Library Object destructor
     * @return no return
     */
    ~Library();

    /**
     * @brief Method resposible for adding new books to the library data bank
     * @param[in] material - const reference to IKsiazka derived object
     * @return no return
     */
    void addMaterial(IKsiazka *material);

    /**
     * @brief Method responsible for allowing user to borrow a book from library
     * Function modifies both user and library object
     *
     * @param title - the title of the book to be borrowed by user
     * @param user - user reference
     */
    void borrowBook(std::string title, User &user);


    /**
     * @brief Method allowing user to return book back to library
     * Function modifies both user and library object
     *
     * @param title - the title of the book to be borrowed by user
     * @param user - user reference
     */
    void returnBook(std::string title, User &user);


    /**
     * @brief Method allowing to print all books in the library
     * @return - no return
     */
    void displayAllBooks() const;

private:
    std::vector<IKsiazka*> books;
};

#endif //POINT_LIBRARY_H
