/*
Proszę dopisać kod, dodać nowe pliki, tak aby program wykonywał się, 
a wynik jego działania był taki sam jak podany na końcu tego pliku.

Wymagania:
    - Zdefiniuj klasę wirtualną AlgebraicStructure z metodami wirtualnymi add() i multiply().
    - Zdefiniuj klasy szablonowe Vector, Matrix i Polynomial dziedziczące po AlgebraicStructure.
    (Dziedziczenie szablonu po szablonie? Oto przykładowa struktura:
    template <typename T>
    class Base {
    public:
        void interface() {
            static_cast<T*>(this)->implementation(); (W waszym przypadku niekonieczne... Ale pozwala wywołać jedną metodą różne inne metody które możecie pod tym schować.
             Optymalizacja kodu na poziomie kompilatora mała, elastyczność i reużywalność)
        }

        // Przykładowa metoda, którą T musi zaimplementować
        void implementation() {
            // Domyślna implementacja (może być pusta)
        }
    };

    template <typename T>
    class Derived : public Base<Derived<T>> {
    public:
        void implementation() {
            // Konkretna implementacja dla Derived
        }
    };
    )
    - Każda z tych klas powinna implementować odpowiednie operacje algebraiczne (dodawanie i mnożenie).
    - Przeciąż operatory + dla klasy Vector, Matrix i Polynomial.
    - Dodaj do każdej z tych klas metodę applyLambda(), która przyjmuje wyrażenie lambda i stosuje je do każdego elementu struktury.
    - Zdefiniuj wyjątki rzucane w przypadku niezgodności wymiarów przy operacjach na wektorach, macierzach lub wielomianach. // JEŻELI NIE MIELIŚCIE WYJĄTKÓW - SKIPP 
    - Zadbaj o zarządzanie pamięcią.

Pliku Main.cpp nie wolno modyfikować, chyba że w tekście zadania podano inaczej (Oznaczenie TODO:).

Program wyjściowy powinien składać się z czytelnego kodu. Powinna być spełniona zasada D.R.Y. - Don’t Repeat Yourself.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <memory>
#include <stdexcept>

// TODO: DEFINE YOUR INCLUDES STRUCTURE HERE
// #include "Your_includes0.h"
// #include "Your_includes1.h"
// #include "Your_includes2.h"
// #include "Your_includes3.h"
#include "Vector.hpp"
#include <Matrix.hpp>
#include "Polynomial.hpp"

// Plik Main.cpp
int main() {
    srand(111);
    Vector<int> v1(5);
    Vector<int> v2(5);
    // Inicjalizacja v1 i v2 wartościami
    v1.applyLambda([](int& element) { element = rand() % 10; });
    v2.applyLambda([](int& element) { element = rand() % 10; });

    Vector<int> v3 = v1 + v2;
    std::cout << "Vector v3: ";
    v3.print();

    Matrix<int> m1(3, 3);
    Matrix<int> m2(3, 3);
    // Inicjalizacja m1 i m2 wartościami
    m1.applyLambda([](int& element) { element = rand() % 10; });
    m2.applyLambda([](int& element) { element = rand() % 10; });

    Matrix<int> m3 = m1 + m2;
    std::cout << "Matrix m3: ";
    m3.print();

    Polynomial<int> p1({1, 2, 3});
    Polynomial<int> p2({4, 5, 6});

    Polynomial<int> p3 = p1 + p2;
    std::cout << "Polynomial p3: ";
    p3.print();
    std::cout << "Value of p3 at x=2: " << p3.evaluate(2) << std::endl;

    return 0;
}

/// SPODZIEWANY OUTPUT:
/*

Vector v3: 
8 10 4 11 10 

Matrix m3: 
11 10 16 
1 4 11 
7 7 9 

Polynomial p3: 
5 7 9 

Value of p3 at x=2: 55

*/