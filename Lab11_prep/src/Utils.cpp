#include "Utils.h"
#include <iostream>
#include <future>

#include "Dir.h"
#include "File.h"
#include "Link.h"

std::vector<FSElement*> searchFiles(const FSElement* element, const std::string& fileName, const User* user)
{
    std::vector<FSElement*> results;
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
                std::vector<FSElement*> subResults = searchFiles(sub, fileName, user);
                results.insert(results.end(), subResults.begin(), subResults.end());
            }
        }
    }
    return results;
}

std::vector<FSElement*> performAsyncUserSearch(const User* user, const std::string &fileName)
{
    std::future<std::vector<FSElement*>> future = std::async(std::launch::async, searchFiles, user->GetHomedir(), fileName, user);
    return future.get();
}
