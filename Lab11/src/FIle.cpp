#include "File.h"

File::File(std::string name) : _name(name) {};

std::string File::GetName() const
{
    return _name;
}

void File::print(int ind, std::ostream &stream) const
{
    for (int i = 0; i < ind; i++) 
        stream << "  ";
    stream << _name << " (FILE)" << "\n";
}


bool File::isDir() const
{ return false; }


std::ostream &operator<<(std::ostream &stream, const File &file)
{
    return stream << file._name;
}


std::string File::pwd() const {
    std::vector<std::string> path;
    const FSElement* current = this;
    while (current) {
        path.push_back(current->GetName());
        current = current->getParent();
    }
    std::reverse(path.begin(), path.end());
    std::string fullPath;
    for (const std::string& part : path) {
        fullPath +=  part + "/";
    }
    return fullPath;
}

std::vector<std::string> File::pwd_vector() const{
    std::vector<std::string> path;
    const FSElement* current = this;
    while (current) {
        path.push_back(current->GetName());
        current = current->getParent();
    }
    std::reverse(path.begin(), path.end());

    return path;
}