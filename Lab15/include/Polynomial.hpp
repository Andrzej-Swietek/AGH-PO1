#pragma once
#include <iostream>
#include <vector>
#include "AlgebraicStructure.hpp"
#include <cmath>
#include <stdexcept>

template <typename T>
class Polynomial : public AlgebraicStructure<T> {
public:
    Polynomial() = default;
    Polynomial(const std::vector<T>& factors) : _factors(factors) {}
    Polynomial(const Polynomial& other) : _factors(other._factors) {}

    T evaluate(T x) const {
        T sum = T{};
        int i = _factors.size();
        for (const auto& element : _factors) {
            sum += element * static_cast<T>(std::pow(x, --i));
        }
        return sum;
    }

    virtual T add() override {
        return T{};
    }

    virtual T multiply() override {
        return T{};
    }

    T& operator[](int index) {
        return _factors[index];
    }

    const T& operator[](int index) const {
        return _factors[index];
    }

    Polynomial<T> operator+(const Polynomial<T>& p) const {
        if (_factors.size() != p._factors.size()) {
            throw std::invalid_argument("Polynomials must be of the same size");
        }
        std::vector<T> new_factors;
        new_factors.reserve(_factors.size());
        for (size_t i = 0; i < _factors.size(); ++i) {
            new_factors.push_back(_factors[i] + p._factors[i]);
        }
        return Polynomial<T>(new_factors);
    }

    void print() const {
        for (const auto& element : _factors) {
            std::cout << element << " ";
        }
        std::cout << "\n";
    }

private:
    std::vector<T> _factors;
};
