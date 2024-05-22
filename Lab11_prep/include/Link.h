#pragma once

#include <string>
#include "FSElement.h"


/**
 * @class Class Representing Symbolic Link in File System
 */
class Link : public FSElement
{
public:
    /**
     * @brief Main constructor for Symbolic Link object
     * @param[in] name - directory name
     * @param[in] target - File System Derived element that is to be a target for linking
     * @return no return
    */
    Link(std::string name, FSElement *target);


    /**
     * @brief Method Checking if this FS Element is actually a directory
     * @return depending on target type true/false
     */
    bool isDir() const override;

    /**
     * @brief Getter for _name field
     * @return _name - directory name
    */
    std::string GetName() const override;


    /**
     * @brief Method allowing to print Linked target with proper indentation (prettified way)
     * @param indent - indentation level
     * @param stream - output stream reference
     * @return no return
    */
    void print(int indent, std::ostream &stream) const override;


    /**
     * @brief Link Destructor
     * @return no return
    */
    ~Link() = default;


    /**
     * Output stream operator overload (<<)
     * @param ostream - output stream reference of std library
     * @param link - const reference to Symbolic Link object that is to be displayed
     * @return reference to output stream object of std library
    */
    friend std::ostream &operator<<(std::ostream &stream, const Link &link);

private:
    /**
     * @brief Field containing directory's name
    */
    std::string _name;

    /**
     * @brief Field containing pointer to targeted element
    */
    FSElement *_target;
};