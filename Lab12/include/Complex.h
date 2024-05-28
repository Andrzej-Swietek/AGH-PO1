#pragma once

#include <iostream>

/**
 * Class representing Complex numbers
*/
class Complex {
public:
    double real;
    double imag;

    /**
     * Default Constructor
    */
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    /**
     * Addition Operator overload
     * @param[in] other const reference to other complex number we are adding
    */
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    /** Multiplication Operator overload
     * @param[in] other const reference to other complex number we are multiplying 
    */
    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }


    /**
     * Output stream overload operator <<
     * @param[in] os - output stream instance
     * @param[in] c - complex number const reference
     * @return reference to std output stream object instance
    */
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << "(" << c.real << " + " << c.imag << "i)";
        return os;
    }
};