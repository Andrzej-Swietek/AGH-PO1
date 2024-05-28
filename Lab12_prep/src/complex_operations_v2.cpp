#include "complex_operations_v2.h"

//// Template function to add two numbers
//template <typename T>
//T add(T* a, T* b) {
//    return *a + *b;
//}
//
//// Template function to multiply two numbers
//template <typename T>
//T multiply(T* a, T* b) {
//    return (*a) * (*b);
//}
//
//// Template specialization for adding complex numbers
//template <>
//Complex add<Complex>(Complex* a, Complex* b) {
//    return Complex(a->real + b->real, a->imag + b->imag);
//}
//
//// Template specialization for multiplying complex numbers
//template <>
//Complex multiply<Complex>(Complex* a, Complex* b) {
//    return Complex(a->real * b->real - a->imag * b->imag, a->real * b->imag + a->imag * b->real);
//}
//

// Explicit instantiation of templates for basic types
//template int add<int>(int* a, int* b);
//template double add<double>(double* a, double* b);
//template int multiply<int>(int* a, int* b);
//template double multiply<double>(double* a, double* b);