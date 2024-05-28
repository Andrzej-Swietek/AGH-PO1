/*
Proszę dopisać kod, dodać nowe pliki, tak aby program wykonywał się, 
a wynik jego działania był taki sam jak podany na końcu tego pliku.

Wymagania:
    Zdefiniuj w complex_operations.h/complex_operations.cpp metody add() oraz multiply() tak by program wykonywał się.
    Proszę wykorzystać szablony funcji przy rozwiązywaniu tego zadania - wykorzystanie szablonów jest niezbędne w rozwiązaniu tego zadania.
    Proszę zwrócić uwagę na konieczność specjalizacji w przypadku wykorzystania liczb zespolonych!!!
    Proszę zdefiniować klasę Complex reprezentującą liczbę zespoloną.

Pliku Main.cpp nie wolno modyfikować, chyba że w tekście zadania podano inaczej (Oznaczenie TODO:).

Program wyjściowy powinien składać się z czytelnego kodu. Powinna być spełniona zasada D.R.Y. - Don’t Repeat Yourself.

Zadania oceniane są wg algorytmu:

    Warunkiem przystąpienia do oceniania programu jest jego poprawna kompilacja (bez błędów).
    Dokumentacja - 1 pkt.
    Poprawna kompilacja (bez ostrzeżeń) - 2 pkt.
    Poprawne wykonanie (odpowiednie wyjście, brak wycieków pamięci itp.) - 3 pkt.
    Ocena kodu (pod względem projektowym, zgodności z OOP, przejrzystości oraz sposobu implantacji) - maks. 4 pkt.


Programy niezgodne z tematem/celem zadania, 
ale kompilujące się (i dające potencjalnie "poprawne" wyjście) będą oceniane na 0 pkt.

*/


#include <iostream>
#include <vector>
#include "complex_operations.h"

int main() {
    int a = 10, b = 20;
    double x = 1.5, y = 2.5;
    Complex c1(1.0, 2.0), c2(3.0, 4.0);
    std::vector<int> vec1 = {1, 2, 3};
    std::vector<int> vec2 = {4, 5, 6};

    std::cout << "Add integers: " << *add(&a, &b) << std::endl;
    std::cout << "Add doubles: " << *add(&x, &y) << std::endl;
    std::cout << "Add complex numbers: " << *add(&c1, &c2) << std::endl;
    
    auto vec_result = add(&vec1, &vec2);
    std::cout << "Add vectors: ";
    for (const auto& v : *vec_result) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    // Complex number multiplication:
    // (a+bi)(c+di) = (ac-bd) + (ad+bc)i

    std::cout << "Multiply integers: " << *multiply(&a, &b) << std::endl;
    std::cout << "Multiply doubles: " << *multiply(&x, &y) << std::endl;
    std::cout << "Multiply complex numbers: " << *multiply(&c1, &c2) << std::endl;
    
    auto scalar_result = multiply(&vec1, &a);
    std::cout << "Multiply vector by scalar: ";
    for (const auto& v : *scalar_result) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    return 0;
}


// Spodziewany Output:Add integers: 30
// Add doubles: 4
// Add complex numbers: (4 + 6i)
// Add vectors: 5 7 9 
// Multiply integers: 200
// Multiply doubles: 3.75
// Multiply complex numbers: (-5 + 10i)
// Multiply vector by scalar: 10 20 30 