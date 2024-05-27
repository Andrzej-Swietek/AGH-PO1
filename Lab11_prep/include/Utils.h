#pragma once

#include "FSElement.h"
#include "User.h"
#include <thread>
#include <mutex>
#include <vector>



/** @brief Util Function Asynchronously searching file with given name through given directory with respect to a user
 * @param[in] user - User that is to own searched file
 * @param[in] fileName - The file name we want to find
 * @return vector of potentially found files
*/
std::vector<FSElement*> performAsyncUserSearch(const User *user, const std::string &fileName);


/** @brief Util Function searching file with given name through given directory with respect to a user
 * @param[in] element - The directory we search through
 * @param[in] fileName - The file name we want to find
 * @param[in] user - User that is to own searched file
 * @return vector of potentially found files
*/
std::vector<FSElement*> searchFiles(const FSElement* element, const std::string& fileName, const User* user);