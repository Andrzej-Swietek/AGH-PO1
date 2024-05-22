#pragma once

#include <string>
#include <algorithm>
#include "FSElement.h"

/**
 * @class Class Representing Directory
 */
class Dir : public FSElement
{
public:
    /**
     * @brief Main constructor for Directory object
     * @param[in] name - directory name
     * @return no return
    */
    Dir(std::string name);


    /**
     * @brief Method displaying list of subdirectories
     * @param[in] lvl - depth
     * @return no return
    */
    void listDirs(int lvl) const;


    /**
     * @brief Method allowing to add new FS Element to given directory
     * @param[in] element - Pointer to new File System derived Element
     * @return no return
    */
    void add(FSElement *element);


    /**
     * @brief Method allowing to find subdirectory
     * @param[in] name - name of searched subdirectory
     * @return Pointer to found subdirectory
    */
    Dir* findDir(std::string name) const;


    /**
     * @brief Operator overload +=
     * Allows to add new subdirectory
     * @param[in] element - pointer to new FS derived element
     * @return no return
    */
    void operator+=(FSElement *element);


    /**
     * @brief Method Checking if this FS Element is actually a directory
     * @return true - always is true
     */
    bool isDir() const override;


    /**
     * @brief Method allowing to print directory with proper indentation (prettified way)
     * @param indent - indentation level
     * @param stream - output stream reference
     * @return no return
    */
    void print(int indent, std::ostream &stream) const override;


    /**
     * @brief Getter for _name field
     * @return _name - directory name
    */
    std::string GetName() const override;


    /** Getter for _subdirs field
     * @return _subdirs - vector of subdirectories pointers
    */
    std::vector<FSElement*> GetSubdirs() const;


    /**
     * @brief Directory Destructor
     * Cleans up FS Elements vector on destroy
     * @return no return
     */
    ~Dir();


    /**
     * Output stream operator overload (<<)
     * @param ostream - output stream reference of std library
     * @param directory - const reference to directory that is to be displayed
     * @return reference to output stream object of std library
    */
    friend std::ostream &operator<<(std::ostream &stream, const Dir &directory);


private:
    /**
     * @brief Field containing directory's name
    */
    std::string _name;

    /**
     * @brief Field containing list (std::vector) of subdirectories in current dir
    */
    std::vector<FSElement*> _subdirs;

};