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
    Ksiazka(std::string& title, std::string& author,  int id, std::string& genre, int shelf_id );


    ///

    /**
     *  @brief Method Responsible for displaying vital information about the book
     *  @override Method overriding method from IKsiazka class
     *  @return no returns
     */
    virtual void wyswietlInformacje() override;


    virtual std::string getTitle() override;


    /// ======================= Getters & Setter =======================

    /**
     * @brief Getter Method responsible for getting value of book's shelf ID
     * @return integer value of shelf identifier
     */
    int getShelfId() const;


    /**
     * @brief Setter Method responsible for setting new value for this book's shelf id
     * @param newId - new shelf identifier integer value
     * @return no return
     */
    void setShelfId(int newId);



    /// ====================== Operator Overloads ======================
    /**
     * @brief Out stream operator overload
     * @param os - reference to output stream object from standard library
     * @param ksiazka - const reference to Ksiazka class obeject that is to be printed
     * @return
     */
    friend std::ostream &operator<<(std::ostream &os, const Ksiazka &ksiazka);


    /**
     * Equality operator overload
     * @param rhs - right hand side Ksiazka const reference
     * @return true if objects have the same fields, false otherwise
     */
    bool operator==(const Ksiazka &rhs) const;


    /**
     * Inequality operator overload
     * @param rhs - right hand side Ksiazka const reference
     * @return true if objects have different fields, false otherwise
     */
    bool operator!=(const Ksiazka &rhs) const;


    /**
     * @brief overload of less operator
     * @param rhs - right hand side Ksiazka const reference
     * @return true if shelf id is smaller
     */
    bool operator<(const Ksiazka &rhs) const;


    /**
     * @brief overload of greater operator
     * @param rhs - right hand side Ksiazka const reference
     * @return true if shelf id is bigger
     */
    bool operator>(const Ksiazka &rhs) const;


    /**
     * @brief overload of less or equal operator
     * @param rhs - right hand side Ksiazka const reference
     * @return true if shelf id is smaller or equal
     */
    bool operator<=(const Ksiazka &rhs) const;


    /**
     * @brief overload of greater or equal operator
     * @param rhs - right hand side Ksiazka const reference
     * @return true if shelf id is greater or equal
     */
    bool operator>=(const Ksiazka &rhs) const;

private:
    int id;
    std::string title;
    std::string author;
    std::string genre;
    int shelf_id;
};


#endif //AGH_PO1_KSIAZKA_H
