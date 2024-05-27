#include "SoftLink.h"

#include "Dir.h"

softLink::softLink( FSElement* target, std::string name) : _name(name), _target(target) {};

std::string softLink::GetName() const
{
    return _name;
}

void softLink::print(int ind, std::ostream &stream) const
{
    for (int i = 0; i < ind; i++)
        stream << "  ";
	//should print path of the target
    stream << _name << " (SOFTLINK) -> " << _target->GetName() << "\n";
}


bool softLink::isDir() const
{ return false; }



std::ostream &operator<<(std::ostream &stream, const softLink &softLink)
{
    return stream << softLink._name;
}
