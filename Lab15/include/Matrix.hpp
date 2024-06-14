#pragma once

#include <iostream>
#include "Vector.hpp"
#include "AlgebraicStructure.hpp"
#include <vector>
#include <functional>

template <typename T>
class Matrix: public AlgebraicStructure<T> {
public:
    Matrix(int size_x, int size_y) : _size_x(size_x), _size_y(size_y), _matrix(size_y, Vector<T>(size_x)) {}

    Matrix(const Matrix<T>& m) : _size_x(m._size_x), _size_y(m._size_y), _matrix(m._matrix) {}

    virtual T add() override {
        return T{};
    }

    virtual T multiply() override {
        return T{};
    }

    Matrix<T> operator+(const Matrix<T>& other) {
        if (_size_x != other._size_x || _size_y != other._size_y) {
            throw std::invalid_argument("Matrices must be of the same size");
        }

        Matrix<T> tmp(_size_x, _size_y);
        for (int i = 0; i < _size_y; i++) {
            for (int j = 0; j < _size_x; j++) {
                tmp[i][j] = _matrix[i][j] + other._matrix[i][j];
            }
        }
        return tmp;
    }

    Vector<T>& operator[](int index) {
        return _matrix[index];
    }

    const Vector<T>& operator[](int index) const {
        return _matrix[index];
    }

    void print() const {
        std::cout << "\n";
        for (const auto& vector : _matrix) {
            vector.print();
        }
        std::cout << "\n";
    }

    void applyLambda(std::function<void(T&)> callback) {
        for (auto& vector : _matrix) {
            vector.applyLambda(callback);
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix<T>& m) {
        m.print();
        return os;
    }

private:
    int _size_x, _size_y;
    std::vector<Vector<T>> _matrix;
};
