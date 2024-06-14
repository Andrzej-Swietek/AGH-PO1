#pragma once
#include <iostream>
#include "AlgebraicStructure.hpp"
#include <vector>
#include <functional>

template <typename T>
class Vector : public AlgebraicStructure<T> {
public:
    Vector(int s) : size(s), vect(s) {}
    
    Vector(const Vector<T>& other) : size(other.size), vect(other.vect) {}

    Vector(int s, const std::vector<T>& elements) : size(s), vect(elements) {}

    virtual T add() override {
        // Provide an implementation
        return T{};
    }

    virtual T multiply() override {
        // Provide an implementation
        return T{};
    }

    void applyLambda(std::function<void(T&)> callback) {
        for (auto& element : vect)
            callback(element);
    }

    T& operator[](int index) {
        return vect[index];
    }

    const T& operator[](int index) const {
        return vect[index];
    }

    Vector<T> operator+(const Vector<T>& other) {
        if (size != other.size) {
            throw std::invalid_argument("Vectors must be of the same size");
        }

        Vector<T> tmp(size);
        for (int i = 0; i < size; ++i) {
            tmp[i] = vect[i] + other[i];
        }
        return tmp;
    }

    int getSize() const {
        return size;
    }

    std::vector<T> getElements() const {
        return vect;
    }

    void print() const {
        for (const auto& element : vect) 
            std::cout << element << " ";
        std::cout << "\n";
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector<T>& vector) {
        vector.print();
        return os;
    }

private:
    int size;
    std::vector<T> vect;
};
