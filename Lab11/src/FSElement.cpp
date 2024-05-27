#include "FSElement.h"
#include "Dir.h"

void FSElement::getFSElements(const std::vector<FSElement*> &sub, int lvl, Type type, std::vector<FSElement*> &els) const
{

    if (lvl == 0)
    {
        return;
    }
    
    for (FSElement* el : sub)
    {
        if (el->isDir())
        {
            if(type == Type::DIR)
            {
                els.push_back(el);
            }
            if (lvl>=0)
            {
                getFSElements(static_cast<Dir*>(el)->GetSubdirs(), lvl-1, type, els);
            }
        }
        else
        {
            if(type == Type::FILE)
            {
                els.push_back(el);
            }
        }
    }
}