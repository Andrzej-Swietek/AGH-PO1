#pragma once

#include "FSElement.h"
#include "User.h"
#include <thread>
#include <mutex>
#include <vector>
#include "File.h"


/** @brief Util Function Asynchronously searching file with given name through given directory with respect to a user
 * @param[in] user - User that is to own searched file
 * @param[in] fileName - The file name we want to find
 * @return vector of potentially found files
*/
//std::vector<FSElement*> performAsyncUserSearch(const User *user, const std::string &fileName);


/** @brief Util Function searching file with given name through given directory with respect to a user
 * @param[in] element - The directory we search through
 * @param[in] fileName - The file name we want to find
 * @param[in] user - User that is to own searched file
 * @return vector of potentially found files
*/
std::vector<FSElement*> searchFiles(const FSElement* element, const FSElement* element2);

/** @brief Util Function searching for a relative path between two objects in tree directory
 * @param[in] obj1 - Starting object
 * @param[in] obj2 - Second object we want to find 
 * @return 
*/
std::string ShowRelativePaths(Dir* obj1, File* obj2);