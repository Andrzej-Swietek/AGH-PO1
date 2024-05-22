#pragma once

#include <string>
#include <vector>
#include <iostream>
#include "Type.h"

/**
 * @abstract
 * @class Class Representing File System Element
 */
class FSElement
{
public:
    /**
     * @brief Method Creating list of sub-elements of requested type
     * @param[in] sub - List of sub-directories
     * @param[in] level - Search Depth
     * @param[in] type - Searched Type : File/Dir
     * @param[in,out] elements - vector into which search results shall be saved
     * @return no return
    */
    void getFSElements(const std::vector<FSElement*> &sub, int level, Type type, std::vector<FSElement*> &elements) const;


    /**
     * @virtual
     * @brief Getter for _name field
     * @return _name - directory name
    */
    virtual std::string GetName() const = 0;


    /**
     * @brief Method Checking if this FS Element is actually a directory
     * @return true - always is true
    */
    virtual bool isDir() const = 0;


    /**
     * @virtual
     * @brief Method allowing to print FSElement with proper indentation (prettified way)
     * @param indent - indentation level
     * @param stream - output stream reference
     * @return no return
    */
    virtual void print(int indent, std::ostream &stream) const = 0;


    /**
     * @virtual
     * @brief File System Element Destructor
     * Cleans up FS Element - Default Destructor
     * @return no return
    */
    virtual ~FSElement() = default;


    void setParent(FSElement* parent) { _parent = parent; }
    FSElement* getParent() const { return _parent; }
protected:
    FSElement* _parent;
};

