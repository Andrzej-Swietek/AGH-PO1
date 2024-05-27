#include "Utils.h"
#include <iostream>
#include <future>

#include "Dir.h"
#include "File.h"
#include "Link.h"

std::vector<FSElement*> searchFiles(const FSElement* element, const FSElement* element2)
{
    std::string fileName = element2->GetName(); // store end element's name
    std::vector<FSElement*> results;
    
    // if element is not a directory then 
    // there is no relative path to element 2
    if (element->isDir())
    {
        const Dir* dir = static_cast<const Dir*>(element);
        for (const FSElement* sub : dir->GetSubdirs())
        {
            if (sub->GetName() == fileName)
            {
                results.push_back(const_cast<FSElement*>(sub));
            }
            if (sub->isDir() || dynamic_cast<const Link*>(sub))
            {
                std::vector<FSElement*> subResults = searchFiles(sub, element2);
                results.insert(results.end(), subResults.begin(), subResults.end());
            }
        }
    }
    return results;
}

// std::vector<FSElement*> performAsyncUserSearch(const User* user, const std::string &fileName)
// {
//     std::future<std::vector<FSElement*>> future = std::async(std::launch::async, searchFiles, user->GetHomedir(), fileName, user);
//     return future.get();
// }


// Returns relative paths between two objects
std::string ShowRelativePaths(Dir* obj1, File* obj2) {
    std::string path = "";
    std::vector<FSElement*> results = searchFiles(obj1, obj2);
    for (auto result : results ) {
        // std::cout << result->GetName() << "\n";
        path += result->GetName();
    }

    // if(File* f = dynamic_cast<File*>(obj2)){
        std::string paths = obj2->pwd();
        std::cout << paths << std::endl;
        return paths;

    // }
}