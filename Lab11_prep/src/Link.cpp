#include "Link.h"

Link::Link(std::string name, FSElement* target) : _name(name), _target(target) {};

std::string Link::GetName() const
{
    return _name;
}

void Link::print(int ind, std::ostream &stream) const
{
    for (int i = 0; i < ind; i++) 
        stream << "  ";
    stream << _name << " (LINK to " << (_target->isDir() ? "DIR ":"FILE ") << _target->GetName() << ")\n";
}

bool Link::isDir() const
{ return false; }

std::ostream &operator<<(std::ostream &stream, const Link &link)
{
    return stream << link._name;
}
