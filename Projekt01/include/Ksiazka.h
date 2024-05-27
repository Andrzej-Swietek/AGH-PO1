//
// Created by andrzej on 01.04.24.
//

#ifndef AGH_PO1_KSIAZKA_H
#define AGH_PO1_KSIAZKA_H

#include<iostream>
#include <ostream>
#include "IKsiazka.h"

class Ksiazka : public IKsiazka {
public:
/// ================== Constructors & Destructors ==================

    /**
     * @brief Ksiazka main constructor
     * @param[in] title - text title of the book
     * @param[in] author - text name and lastname of books author
     * @param[in] id - integer identifier of given book - unique
     * @param[in] genre - text name of which genre the book is
     * @param[in] shelf_id - integer id of shelf where book is placed
     * @return no return
     */
    Ksiazka(std::string title, std::string author,  int id, std::string genre, int shelf_id );



    /**
     * @brief Ksiazka main constructor
     * @param[in] title - text title of the book
     * @param[in] author - text name and lastname of books author
     * @param[in] id - integer identifier of given book - unique
     * @param[in] genre - text name of which genre the book is
     * @param[in] shelf_id - integer id of shelf where book is placed
     * @param[in] available - flag if book is available
     * @return no return
     */
    Ksiazka(std::string title, std::string author,  int id, std::string genre, int shelf_id, bool available );


    /**
     * @brief Copy constructor for Ksiazka class
     * @param[in] other - reference to another Ksiazka object
     * @return no return
     */
    Ksiazka(const Ksiazka& other);


    /**
     * @brief Move constructor for Ksiazka class
     * @param[in] other - rvalue reference to another Ksiazka object
     * @return no return
     */
    Ksiazka(Ksiazka&& other) noexcept;


    ///  ====================== Operator Overloads ======================

    /**
     * @brief Copy assignment operator for Ksiazka class
     * @param[in] other - reference to another Ksiazka object
     * @return reference to the current Ksiazka object
     */
    Ksiazka& operator=(const Ksiazka& other);


    /**
     * @brief Move assignment operator for Ksiazka class
     * @param[in] other - rvalue reference to another Ksiazka object
     * @return reference to the current Ksiazka object
     */
    Ksiazka& operator=(Ksiazka&& other) noexcept;

private:
};


#endif //AGH_PO1_KSIAZKA_H
