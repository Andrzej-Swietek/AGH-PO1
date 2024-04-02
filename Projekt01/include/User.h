//
// Created by andrzej on 01.04.24.
//

#ifndef POINT_USER_H
#define POINT_USER_H
#include <iostream>
#include<vector>

#include "IKsiazka.h"

struct ReturnBookResult{ bool success; std::string message; };

class User {
public:
    /**
     * @brief User main constructor
     *
     * Borrowed books by default empty vector
     * @param name - new user's name
     */
    explicit User(std::string name);


    /**
     * @brief Getter Method getting users name
     * @return
     */
    std::string getName() const;


    /**
     * @brief Method printing all books the user has borrowed from library
     *
     * @return no returns
     */
    void displayBorrowedBooks() const;


    /**
     * @brief Method Allowing user to borrow book
     * @param[in] - pointer to Iksiazka derived object
     * @return no return
     */
    void borrowBook(IKsiazka*);


    /**
     * @brief Method Allowing user to return borrowed book
     * @param[in] - pointer to Iksiazka derived object
     * @return ReturnBookResult struct with status and message being results of return operation
     */
    ReturnBookResult returnBook(std::string title);


private:
    std::string name;
    std::vector<IKsiazka*> borrowedBooks;
};



#endif //POINT_USER_H
