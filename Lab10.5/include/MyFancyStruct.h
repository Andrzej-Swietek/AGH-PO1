#ifndef MYFANCYSTRUCT_H
#define MYFANCYSTRUCT_H


template <typename T>
struct IsPointer {
    static const bool value = false;
};

template <typename T>
struct IsPointer<T*> {
    static const bool value = true;
};

// Template metafunction to calculate factorial at compile-time
template <int N>
struct Factorial {
    static const int value = N * Factorial<N - 1>::value;
};

template <>
struct Factorial<0> {
    static const int value = 1;
};


#endif // MYFANCYSTRUCT_H