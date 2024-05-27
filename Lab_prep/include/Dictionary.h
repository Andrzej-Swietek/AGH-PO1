#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <map>
#include <string>


class Dictionary {
public:
    /** @brief Default Constructor
     *
     */
    Dictionary();


    /** @brief Move Constructor
     *
     * @param other[in] reference to "old" dictionary object that we move from
     */
    Dictionary(Dictionary &&other);

    /** @brief Destructor
     *
     */
    ~Dictionary();

    /** Move Semantics Method
     * Function Implementing moving semantics
     * @return rvalue reference to dictionary
     */
    Dictionary&& move();


    /**
     * Assign operator overload
     * @param other
     * @return
     */
    Dictionary& operator=(Dictionary &&other);


    /**
     * Brackets operator overload
     * @param index[in]
     * @return
     */
    const int& operator[](std::string index) const;

    /**
     *
     * @param index
     * @param value
     */
    void add(std::string index, int value);
//    void add(const std::string& index, const T& value);

    /**
     *
     * @param index
     */
    void remove(std::string index);

private:
    std::map<std::string, int> map;
};


#endif
