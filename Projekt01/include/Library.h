//
// Created by andrzej on 01.04.24.
//

#ifndef POINT_LIBRARY_H
#define POINT_LIBRARY_H
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <unordered_map>

#include "IKsiazka.h"
#include "User.h"
#include "LibraryIterator.h"

class Library {
public:

    /**
     * @brief Default constructor
     * @return no return
     */
    Library();

    /**
     * @brief Constructor that initializes the library with a vector of IKsiazka pointers.
     * @param booksVector Vector of IKsiazka pointers representing the initial books in the library.
     */
    Library(const std::vector<IKsiazka*>& booksVector);

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
     * @brief Method for removing a book from the library.
     * @param title Title of the book to be removed.
     * @return True if the book was successfully removed, false otherwise (e.g., if the book was not found).
     */
    bool removeMaterial(const std::string& title);


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



    /**
     * @brief Method allowing to change the shelf position for books in the library.
     * @param title Title of the book to be moved.
     * @param newShelfId New position on the shelf.
     * @return No return value.
     */
    void moveBookToShelf(std::string title, int newShelfId);


    /**
     * @brief Method for swapping positions of two books.
     * @param title1 Title of the first book to be swapped.
     * @param title2 Title of the second book to be swapped.
     * @return No return value.
     */
    void swapBooks(std::string title1, std::string title2);

    /**
     * @brief Method for displaying (just) all borrowed books.
     * @return No return value.
     */
    void displayBorrowedBooks() const;

    /**
     * @brief Method allowing to add multiple books at once
     * @param collection - vector of new IKsiazka derived objects' pointers
     */
    void addCollection(const std::vector<IKsiazka*>& collection);


    ///  ======================= Aggregations  ========================

    /**
     * @brief Method for sorting all books by title.
     * @return A copy of the vector containing sorted books.
     */
    std::vector<IKsiazka *> sortByTitle() const;


    /**
     * @brief Method for sorting all books by ID.
     * @return A copy of the vector containing sorted books.
     */
    std::vector<IKsiazka *> sortById() const;


    /**
     * @brief Method for grouping books by genre.
     * @return An unordered map where keys are genres and values are vectors of books belonging to each genre.
     */
    std::unordered_map<std::string, std::vector<IKsiazka*>> booksByGenre() const;


    /**
     * @brief Method for grouping books by author.
     * @return An unordered map where keys are authors and values are vectors of books written by each author.
     */
    std::unordered_map<std::string, std::vector<IKsiazka*>> booksByAuthor() const;


    /**
     * @brief Method for grouping books by availability.
     * @return An unordered map where keys are "available" or "unavailable" and values are vectors of books in each category.
     */
    std::unordered_map<std::string, std::vector<IKsiazka*>> booksByAvailability() const;


    /**
     * @brief Method for grouping books according to a provided group criteria.
     * @param groupCriteria The criteria based on which books will be grouped. Possible values: "author", "genre", or "availability".
     * @return An unordered map representing the grouping, where keys depend on the group criteria.
     */
    std::unordered_map<std::string, std::vector<IKsiazka*>> groupBy(const std::string& groupCriteria) const;





    ///  ========================= Searches =========================

    /**
     * @brief Search for books in the library by title.
     *
     * @param title The title of the book to search for.
     * @return A vector of pointers to books with the specified title.
     */
    std::vector<IKsiazka*> searchByTitle(const std::string& title) const;


    /**
     * @brief Search for books in the library by author.
     *
     * @param author The author of the book to search for.
     * @return A vector of pointers to books by the specified author.
     */
    std::vector<IKsiazka*> searchByAuthor(const std::string& author) const;


    /**
     * @brief Search for books in the library by genre.
     *
     * @param genre The genre of the book to search for.
     * @return A vector of pointers to books with the specified genre.
     */
    std::vector<IKsiazka*> searchByGenre(const std::string& genre) const;



    ///  ====================== Operator Overloads ======================


    /**
     * @brief Overloaded subscript operator to access a book by its title.
     * @param title Title of the book to access.
     * @return Pointer to the book object if found, nullptr otherwise.
     */
    IKsiazka* operator[](const std::string title) const;


    /**
     * @brief Overloaded subscript operator to access a book by its ID.
     * @param id ID of the book to access.
     * @return Pointer to the book object if found, nullptr otherwise.
     */
    IKsiazka* operator[](int id) const;


    /// ====================== Operator Overloads ======================

    /**
     * Method allowing user to iterate over library collection
     * Adhering to Iterator Design Pattern
     * @return Iterator object pointer
     */
    LibraryIterator* createIterator();

private:
    std::vector<IKsiazka*> books;

    std::unordered_map<std::string, std::vector<IKsiazka*>> groupBy(std::function<std::string(const IKsiazka*)> groupFunction) const;


};

#endif //POINT_LIBRARY_H
