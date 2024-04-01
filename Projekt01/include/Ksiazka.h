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


    virtual void wyswietlInformacje() override;

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

    friend std::ostream &operator<<(std::ostream &os, const Ksiazka &ksiazka);

private:
    int id;
    std::string title;
    std::string author;
    std::string genre;
    int shelf_id;
};


#endif //AGH_PO1_KSIAZKA_H
