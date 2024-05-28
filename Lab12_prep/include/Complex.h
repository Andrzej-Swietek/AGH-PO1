#pragma once

#include <iostream>

class Complex {
public:
    double real;
    double imag;

    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Overload operator + for complex number addition
    Complex operator+(const Complex &other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload operator * for complex number multiplication
    Complex operator*(const Complex &other) const {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    // Overload operator << for output
    friend std::ostream& operator<<(std::ostream &out, const Complex &c) {
        out << "(" << c.real << ", " << c.imag << "i)";
        return out;
    }
};
