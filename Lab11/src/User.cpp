#include "User.h"
#include "FSElement.h"
#include "Type.h"

User::User(std::string name, Dir* homedir) : _name(name), _homedir(homedir) {};

std::string User::GetName() const
{
    return _name;
}

Dir* User::GetHomedir() const
{
    return _homedir;
}


bool User::HasAccessForFile(std::string file_name) const {
    std::vector<FSElement*> elements_result;
    _homedir->FSElement::getFSElements(_homedir->GetSubdirs(), 1000, Type::FILE, elements_result);

    return elements_result.size() > 0;
}