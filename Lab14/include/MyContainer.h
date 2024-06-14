#pragma once

#include <iostream>
#include <vector>
#include <string>

/**
 * @brief Template of class MyConatiner<>
 * Custom container containing elements in vector like manner
*/
template <typename T>
class MyContainer {
public:
    /**
     * @brief Method that adds element to collection
     * @param[in] element - const reference to element
     * @return no return 
    */
    void add(const T& element) {
        elements.push_back(element);
    }


    /**
     * @brief Method that gets element at given index
     * @param[in] index - index that we want to get from collection
     * @return index-th Element of the collection  
    */
    T get(int index) const {
        if (index >= 0 && index < elements.size()) {
            return elements[index];
        }
        throw std::out_of_range("Index out of range");
    }


    /**
     * @brief Method that gets current size of container
     * @return size - how many elements the container includes
    */
    int size() const {
        return elements.size();
    }

    // Overload the << operator to print the contents of the container
    friend std::ostream& operator<<(std::ostream& os, const MyContainer& container) {
        for (const auto& element : container.elements) {
            if constexpr (std::is_pointer_v<T>) {
                os << *element << " ";
            } else {
                os << element << " ";
            }
        }
        return os;
    }

private:
    std::vector<T> elements;
};
