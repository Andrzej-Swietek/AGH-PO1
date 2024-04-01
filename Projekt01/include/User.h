//
// Created by andrzej on 01.04.24.
//

#ifndef POINT_USER_H
#define POINT_USER_H
#include <iostream>
#include<vector>

#include "IKsiazka.h"

class User {
public:
    /**
     * @brief User main constructor
     *
     * Borrowed books by default empty vector
     * @param name - new user's name
     */
    explicit User(std::string& name);


    /**
     * Getter Method getting users name
     * @return
     */
    std::string getName() const;


    /**
     * @brief Method printing all books the user has borrowed from library
     *
     * @return no returns
     */
    void displayBorrowedBooks() const;
private:
    std::string name;
    std::vector<IKsiazka*> borrowedBooks;
};

#endif //POINT_USER_H
