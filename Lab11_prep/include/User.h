#pragma once

// #include "FSElement.h"
#include "Dir.h"

/**
 * @class Class Representing System's User in File System
 */
class User
{
public:
    /**
     * @brief Main constructor for User object
     * @param[in] name - user's name
     * @param[in] homedir - pointer to user's home directory
    */
    User(std::string name, Dir *homedir);


    /**
     * @brief Getter method retrieving user's name
     * @return users name
    */
    std::string GetName() const;


    /**
     * @brief Method retrieving user's home directory
     * @return pointer to user's home directory
    */
    Dir* GetHomedir() const;


private:
   /**
    * @brief Field containing user's name
    */
    std::string _name;


    /**
     * @brief Field containing pointer/reference to user's home directory
     */
    Dir *_homedir;

};