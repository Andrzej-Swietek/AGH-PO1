#ifndef MYFANCYFUNCTIONS_H
#define MYFANCYFUNCTIONS_H
#include <iostream>
#include <functional>


template<typename T>
T myMax(T a, T b) {
    return (a > b) ? a : b;
}

template<typename T>
T myMin(T a, T b) {
    return (a < b) ? a : b;
}

template<typename T>
void mySwap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template<typename T, typename U>
auto myAdd(T a, U b) -> decltype(a + b) {
    return a + b;
}

// Specialization for concatenating int and string
template<typename T>
std::string myAdd(T a, const std::string& b) {
    return std::to_string(a) + b;
}

template<typename U>
std::string myAdd(const std::string& a, U b) {
    return a + std::to_string(b);
}

template<typename T, typename Func>
void myProcess(T value, Func func) {
    func(value);
}

#endif // MYFANCYFUNCTIONS_H