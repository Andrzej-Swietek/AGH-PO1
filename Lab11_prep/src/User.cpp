#include "User.h"

User::User(std::string name, Dir* homedir) : _name(name), _homedir(homedir) {};

std::string User::GetName() const
{
    return _name;
}

Dir* User::GetHomedir() const
{
    return _homedir;
}
