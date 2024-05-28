#include <iostream>
#include "complex_operations.h"

int main() {

    int a = 10, b = 20;
    double x = 1.5, y = 2.5;
    Complex c1(1.0, 2.0), c2(3.0, 4.0);

    std::cout << "Add integers: " << add(&a, &b) << std::endl;
    std::cout << "Add doubles: " << add(&x, &y) << std::endl;
    std::cout << "Add complex numbers: " << add(&c1, &c2) << std::endl;

    std::cout << "Multiply integers: " << multiply(&a, &b) << std::endl;
    std::cout << "Multiply doubles: " << multiply(&x, &y) << std::endl;
    std::cout << "Multiply complex numbers: " << multiply(&c1, &c2) << std::endl;

    return 0;
}