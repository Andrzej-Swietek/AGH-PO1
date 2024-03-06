#include "Dictionary.h"


Dictionary::Dictionary() {}

Dictionary::Dictionary(Dictionary &&other) : map(std::move(other.map)) {}

Dictionary::~Dictionary() {}

Dictionary& Dictionary::operator=(Dictionary &&other) {
    if (this != &other) {
        map = std::move(other.map);
    }
    return *this;
}

const int& Dictionary::operator[](std::string index) const
{
    auto it = this->map.find(index);
    if (it == this->map.end()) {
        static const int default_value = 0;
        return default_value;
    }
    return this->map.at(index);
}


void Dictionary::add(std::string index, int value)
{
    map[index] = value;
}


void Dictionary::remove(std::string index)
{
    try {
        if (!map.count(index)) // Using count() to check if the key exists
            throw std::runtime_error("Index not found");

        map.erase(index);
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown error occurred while deleting" << std::endl;
    }
}

Dictionary&& Dictionary::move()
{
    return std::move(*this);
}

