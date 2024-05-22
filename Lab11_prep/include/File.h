#pragma once

#include <string>
#include <algorithm>
#include "FSElement.h"

/**
 * @class Class Representing File in File System
 */
class File : public FSElement
{
public:
    /**
     * @brief Main constructor for File object
     * @param[in] name - directory name
    */
    File(std::string name);


    /**
     * @brief Method Checking if this FS Element is actually a directory
     * @return false - always is false
     */
    bool isDir() const override;


    /** metoda dostępowa do składowej _name
    * @return zwraca nazwę elementu
    */
    std::string GetName() const override;


    /**
     * @brief Method allowing to print file with proper indentation (prettified way)
     * @param indent - indentation level
     * @param stream - output stream reference
    */
    void print(int ind, std::ostream &stream) const override;


    /**
     * @brief File Destructor
     * Default destructor
     */
    ~File() = default;


    /**
     * Output stream operator overload (<<)
     * @param ostream - output stream reference of std library
     * @param file - const reference to file object that is to be displayed
     * @return reference to output stream object of std library
    */
    friend std::ostream &operator<<(std::ostream &stream, const File &file);


    /**
     * @brief Method to get the full path to the file
     * @return full path as a string
    */
    std::string pwd() const;

    /**
     * @brief Method to get the full path to the file
     * @return full path as a std::vector
    */
    std::vector<std::string> pwd_vector() const;


private:
    /**
    * @brief Field containing directory's name
   */
    std::string _name;
};