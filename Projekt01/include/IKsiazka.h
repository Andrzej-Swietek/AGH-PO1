//
// Created by andrzej on 01.04.24.
//

#ifndef AGH_PO1_IKSIAZKA_H
#define AGH_PO1_IKSIAZKA_H

#include <iostream>
#include <vector>
#include <ostream>
#include <string>

class IKsiazka {
public:
    /// ================== Constructors & Destructors ==================

    /**
     * @brief IKsiazka main constructor
     * @param[in] title - text title of the book
     * @param[in] author - text name and lastname of books author
     * @param[in] id - integer identifier of given book - unique
     * @param[in] genre - text name of which genre the book is
     * @param[in] shelf_id - integer id of shelf where book is placed
     * @return no return
     */
    IKsiazka(std::string& title, std::string& author,  int id, std::string& genre, int shelf_id );


    /**
     * @brief Ksiazka extended main constructor
     * @param[in] title - text title of the book
     * @param[in] author - text name and lastname of books author
     * @param[in] id - integer identifier of given book - unique
     * @param[in] genre - text name of which genre the book is
     * @param[in] shelf_id - integer id of shelf where book is placed
     * @param[in] available - flag if book is available
     * @return no return
     */
    IKsiazka(std::string& title, std::string& author,  int id, std::string& genre, int shelf_id, bool available );


    /**
     * @brief Copy Constructor
     * @param other - IKsiazka derived object's const reference
     */
    IKsiazka(const IKsiazka& other);


    /**
     * @brief Move Constructor
     * @param other - IKsiazka derived object's const reference
     */
    IKsiazka(IKsiazka&& other) noexcept;


    /**
     * @brief IKsiazka Destructor
     * Destructor set to default destructor
     *
     * @return no return
     */
    ~IKsiazka() = default;



    ///


    /**
     * @brief Method responsible for presenting important information about given book
     * @virtual - Pure virtual function
     * @return no return
     */
    virtual void wyswietlInformacje();


    /// ======================= Getters & Setter =======================

    /**
     * @brief Method responsible for retrieving title of given book
     * @virtual
     * @return title field
     */
    virtual std::string getTitle();


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
    friend std::ostream &operator<<(std::ostream &os, const IKsiazka &ksiazka);


    /**
     * Equality operator overload
     * @param rhs - right hand side Ksiazka const reference
     * @return true if objects have the same fields, false otherwise
     */
    bool operator==(const IKsiazka &rhs) const;


    /**
     * Inequality operator overload
     * @param rhs - right hand side Ksiazka const reference
     * @return true if objects have different fields, false otherwise
     */
    bool operator!=(const IKsiazka &rhs) const;


    /**
     * @brief overload of less operator
     * @param rhs - right hand side Ksiazka const reference
     * @return true if shelf id is smaller
     */
    bool operator<(const IKsiazka &rhs) const;


    /**
     * @brief overload of greater operator
     * @param rhs - right hand side Ksiazka const reference
     * @return true if shelf id is bigger
     */
    bool operator>(const IKsiazka &rhs) const;


    /**
     * @brief overload of less or equal operator
     * @param rhs - right hand side Ksiazka const reference
     * @return true if shelf id is smaller or equal
     */
    bool operator<=(const IKsiazka &rhs) const;


    /**
     * @brief overload of greater or equal operator
     * @param rhs - right hand side Ksiazka const reference
     * @return true if shelf id is greater or equal
     */
    bool operator>=(const IKsiazka &rhs) const;


    /**
     * @brief Copy assign operator
     * @param other - IKsiazka derived object's const reference
     * @return - IKsiazka derived object's reference
     */
    IKsiazka& operator=(const IKsiazka& other);


    /**
     * Move Assignment Operator
     * @param other - IKsiazka derived object's const reference
     * @return - IKsiazka derived temporary object
     */
    IKsiazka& operator=(IKsiazka&& other) noexcept;

protected:
    int id;
    std::string title;
    std::string author;
    std::string genre;
    int shelf_id;
    bool available;
};

#endif //AGH_PO1_IKSIAZKA_H
