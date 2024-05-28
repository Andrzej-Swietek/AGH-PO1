#ifndef COMPLEX_OPERATIONS_H
#define COMPLEX_OPERATIONS_H

#include <vector>
#include <memory>
#include "Complex.h"


/**
 * @brief template of function that adds 2 entities
 * @param[in] a - First element of sum
 * @param[in] b - Second element of sum
 * @return pointer to the result of the sum
*/
template<typename T>
std::shared_ptr<T> add(const T* a, const T* b) {
    return std::make_shared<T>(*a + *b);
}

// Specjalizacja dla wektorów
template<>
std::shared_ptr<std::vector<int>> add(const std::vector<int>* a, const std::vector<int>* b) {
    auto result = std::make_shared<std::vector<int>>(a->size());
    for (size_t i = 0; i < a->size(); ++i) {
        (*result)[i] = (*a)[i] + (*b)[i];
    }
    return result;
}


/**
 * @brief template of function that multiplies 2 entities
 * @param[in] a - First element of multiplication
 * @param[in] b - Second element of multiplication
 * @return pointer to the result of the multiplication -shared pointer
*/
template<typename T>
std::shared_ptr<T> multiply(const T* a, const T* b) {
    return std::make_shared<T>(*a * *b);
}

// Przeciążenie dla wektora i skalara
std::shared_ptr<std::vector<int>> multiply(const std::vector<int>* vec, const int* scalar) {
    auto result = std::make_shared<std::vector<int>>(vec->size());
    for (size_t i = 0; i < vec->size(); ++i) {
        (*result)[i] = (*vec)[i] * (*scalar);
    }
    return result;
}

#endif // COMPLEX_OPERATIONS_H

