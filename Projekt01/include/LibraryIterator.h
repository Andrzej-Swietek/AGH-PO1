//
// Created by andrzej on 02.04.24.
//

#ifndef POINT_LIBRARYITERATOR_H
#define POINT_LIBRARYITERATOR_H

#include <iostream>
#include <vector>

#include "IKsiazka.h"

class LibraryIterator {
public:

    /**
     * @brief Constructor for LibraryIterator.
     * @param books A vector of pointers to IKsiazka objects representing the collection of books.
     */
    explicit LibraryIterator(std::vector<IKsiazka*> books) : books(books), index(0) {}

    /**
     * @brief Advances the iterator to the next book in the collection.
     * @return Pointer to the next book.
     */
    IKsiazka* next() {
        if (hasNext()) {
            return books[index++];
        }
        return nullptr;
    }

    /**
     * @brief Moves the iterator to the previous book in the collection.
     * @return Pointer to the previous book.
     */
    IKsiazka* prev() {
        if (hasPrev()) {
            return books[--index];
        }
        return nullptr;
    }

    /**
     * @brief Checks if there are more books in the collection.
     * @return True if there are more books, otherwise false.
     */
    bool hasNext() const {
        return index < books.size();
    }

    /**
     * @brief Checks if there are previous books in the collection.
     * @return True if there are previous books, otherwise false.
     */
    bool hasPrev() const {
        return index > 0;
    }

    /**
     * @brief Returns an iterator pointing to the beginning of the collection.
     * @return An iterator pointing to the beginning of the collection.
     */
    IKsiazka** begin() {
        return books.data();
    }

    /**
     * @brief Returns an iterator pointing to the end of the collection.
     * @return An iterator pointing to the end of the collection.
     */
    IKsiazka** end() {
        return books.data() + books.size();
    }

private:
    std::vector<IKsiazka*> books;
    size_t index;
};

/**
 * @example For loop
 *
 * // ...
 *  Library library;
 *
 *   // Add some books to the library...
 *   library.addMaterial(new IKsiazka("Title1", "Author1", 1, "Genre1", 1, true));
 *   library.addMaterial(new IKsiazka("Title2", "Author2", 2, "Genre2", 2, true));
 *   library.addMaterial(new IKsiazka("Title3", "Author3", 3, "Genre3", 3, true));
 *
 *   // Loop over books using range-based for loop
 *   for (IKsiazka* book : *library.createIterator()) {
 *       std::cout << "Title: " << book->title << std::endl;
 *   }
 */

#endif //POINT_LIBRARYITERATOR_H
