//
// Created by andrzej on 01.04.24.
//

#ifndef AGH_PO1_CZASOPISMO_H
#define AGH_PO1_CZASOPISMO_H


#include<iostream>
#include <ostream>
#include "IKsiazka.h"

class Czasopismo : public IKsiazka {
public:
/// ================== Constructors & Destructors ==================

    /**
     * @brief Czasopismo main constructor
     * @param[in] title - text title of the book
     * @param[in] author - text name and lastname of books author
     * @param[in] id - integer identifier of given book - unique
     * @param[in] genre - text name of which genre the book is
     * @param[in] shelf_id - integer id of shelf where book is placed
     * @return no return
     */
    Czasopismo(std::string title, std::string author,  int id, std::string genre, int shelf_id );



    /**
     * @brief Czasopismo main constructor
     * @param[in] title - text title of the book
     * @param[in] author - text name and lastname of books author
     * @param[in] id - integer identifier of given book - unique
     * @param[in] genre - text name of which genre the book is
     * @param[in] shelf_id - integer id of shelf where book is placed
     * @param[in] available - flag if book is available
     * @return no return
     */
    Czasopismo(std::string title, std::string author,  int id, std::string genre, int shelf_id, bool available );


    /**
     * @brief Copy constructor for Czasopismo class
     * @param[in] other - reference to another Ksiazka object
     * @return no return
     */
    Czasopismo(const Czasopismo& other);


    /**
     * @brief Move constructor for Czasopismo class
     * @param[in] other - rvalue reference to another Ksiazka object
     * @return no return
     */
    Czasopismo(Czasopismo&& other) noexcept;


    ///  ====================== Operator Overloads ======================

    /**
     * @brief Copy assignment operator for Ksiazka class
     * @param[in] other - reference to another Ksiazka object
     * @return reference to the current Ksiazka object
     */
    Czasopismo& operator=(const Czasopismo& other);


    /**
     * @brief Move assignment operator for Ksiazka class
     * @param[in] other - rvalue reference to another Ksiazka object
     * @return reference to the current Ksiazka object
     */
    Czasopismo& operator=(Czasopismo&& other) noexcept;

private:
};


#endif //AGH_PO1_CZASOPISMO_H
