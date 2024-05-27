/*
Proszę dopisać kod, dodać nowe pliki, tak aby program wykonywał się, 
a wynik jego działania był taki sam jak podany na końcu tego pliku.

Wymagania:
    Użyj template function, template class, template struct... 

Pliku Main.cpp nie wolno modyfikować, chyba że w tekście zadania podano inaczej (Oznaczenie TODO:).

Program wyjściowy powinien składać się z czytelnego kodu. Powinna być spełniona zasada D.R.Y. - Don’t Repeat Yourself.

Zadania oceniane są wg algorytmu:

    Nie oceniamy


Programy niezgodne z tematem/celem zadania, 
ale kompilujące się (i dające potencjalnie "poprawne" wyjście) będą oceniane na 0/0 pkt (czyli tak jak reszta).

*/

#include <iostream>
#include "MyFancyFunctions.h"
#include "MyFancyClass.h"
#include "MyFunnyShapes.h"
#include "MyFancyStruct.h"
#include "MyThreadSafeStuff.h"
#include <thread>


int main() {

    // Template works for int 
    std::cout << "Max: " << myMax(5, 10) << std::endl;
    std::cout << "Min: " << myMin(5, 10) << std::endl;

    int xI = 5, yI = 10;
    std::cout << "Before swap: x=" << xI << ", y=" << yI << std::endl;
    mySwap(xI, yI);
    std::cout << "After swap: x=" << xI << ", y=" << yI << std::endl;


    // For double
    std::cout << "Max: " << myMax(5.3, 10.3) << std::endl;
    std::cout << "Min: " << myMin(5.3, 10.3) << std::endl;

    double xD = 5.33, yD = 10.33;
    std::cout << "Before swap: x=" << xD << ", y=" << yD << std::endl;
    mySwap(xD, yD);
    std::cout << "After swap: x=" << xD << ", y=" << yD << std::endl;


    // For string? Yes, but slightly wrong... Try to ovverride greater than operator to fix it!
    std::cout << "Max: " << myMax(std::string("5.3"), std::string("10.3")) << std::endl;
    std::cout << "Min: " << myMin(std::string("5.3"), std::string("10.3")) << std::endl;

    std::string xS = "5.33", yS = "10.33";
    std::cout << "Before swap: x=" << xS << ", y=" << yS << std::endl;
    mySwap(xS, yS);
    std::cout << "After swap: x=" << xS << ", y=" << yS << std::endl;


    // You can also try to add different types? 

    std::cout << "Sum of 5 and 10.3: " << myAdd(xI, yD) << std::endl;
    std::cout << "Sum of \'10.33\' and 5: " << myAdd(yS, xI) << std::endl;


    int num = 5;

    // Using lambda to print the square of the number
    // I would like to say, that C++ 11 make me suffer here... U cannot use 'auto' in lambda parameter declaration only in C++ >= 14 it can work. 
    auto printSquare = [](int x) {
        std::cout << "Square of " << x << " is: " << x * x << std::endl;
    };

    // Passing lambda function to template function
    myProcess(num, printSquare);


    ////////////////////////////////////////////////////////////////

    // Now template class...

    Stack<int> intStack(5);
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);
    std::cout << "Popped: " << intStack.pop() << std::endl;

    Stack<double> doubleStack(5);
    doubleStack.push(1.5);
    doubleStack.push(2.5);
    doubleStack.push(3.5);
    std::cout << "Popped: " << doubleStack.pop() << std::endl;

    ////////////////////////////////////////////////////////////////
    
    // Creating Circle objects
    Circle<double> circle1(5.0);
    Circle<double> circle2(3.0);

    // Using the area() method
    std::cout << "Area of Circle 1: " << circle1.area() << std::endl;
    std::cout << "Area of Circle 2: " << circle2.area() << std::endl;

    // Adding two Circle objects
    Circle<double> circle3 = circle1 + circle2;
    std::cout << "Circle 3 (Sum of Circle 1 and Circle 2): " << circle3 << std::endl;

    // Creating Rectangle objects
    Rectangle<int> rectangle1(4, 5);
    Rectangle<int> rectangle2(3, 6);

    // Using the area() method
    std::cout << "Area of Rectangle 1: " << rectangle1.area() << std::endl;
    std::cout << "Area of Rectangle 2: " << rectangle2.area() << std::endl;

    // Adding two Rectangle objects
    Rectangle<int> rectangle3 = rectangle1 + rectangle2;
    std::cout << "Rectangle 3 (Sum of Rectangle 1 and Rectangle 2): " << rectangle3 << std::endl;

    ////////////////////////////////////////////////////////////////
    // Template structures? 

    // Checking if simesting is a pointer
    std::cout << "Is int* a pointer? " << IsPointer<int*>::value << std::endl;    // Should print 1 (true)
    std::cout << "Is int a pointer? " << IsPointer<int>::value << std::endl;      // Should print 0 (false)

    // Or calculating factorial... But can You do it with double?
    std::cout << "Factorial of 5: " << Factorial<5>::value << std::endl;  // Compile-time calculation
    std::cout << "Factorial of 5: " << Factorial<0>::value << std::endl;  // Compile-time calculation


    ////////////////////////////////////////////////////////////////

    // Some overshooting? 

    ThreadSafeQueue<int> q;

    std::thread t1([&]() {
        for (int i = 0; i < 10; ++i) {
            q.push(i);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });

    std::thread t2([&]() {
        while (!q.isEmpty()) {
            std::cout << "Popped: " << q.pop() << std::endl;
        }
    });

    t1.join();
    t2.join();


    ThreadSafeHashMap<int, std::string> map;

    std::thread t3([&]() {
        for (int i = 0; i < 10; ++i) {
            map.insert(i, "Value " + std::to_string(i));
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });

    std::thread t4([&]() {
        std::string value;
        for (int i = 0; i < 10; ++i) {
            if (map.find(i, value)) {
                std::cout << "Found: " << value << std::endl;
            }
        }
    });

    t3.join();
    t4.join();

    std::string value;
    for (int i = 0; i < 10; ++i) {
            if (map.find(i, value)) {
                std::cout << "Found: " << value << std::endl;
            }
        }


    return 0;
}




/*Spodziewany output



*/