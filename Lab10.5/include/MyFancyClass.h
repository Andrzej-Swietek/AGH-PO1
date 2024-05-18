#ifndef MYFANCYCLASS_H
#define MYFANCYCLASS_H

#include <iostream>

template<typename T>
class Stack {
private:
    T* data;
    int top;
    int capacity;

public:
    Stack(int size) : capacity(size), top(-1) {
        data = new T[capacity];
    }

    ~Stack() {
        delete[] data;
    }

    void push(T element) {
        if (top == capacity - 1) {
            std::cout << "Stack Overflow!" << std::endl;
            return;
        }
        data[++top] = element;
    }

    T pop() {
        if (top == -1) {
            std::cout << "Stack Underflow!" << std::endl;
            return T();
        }
        return data[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

#endif // MYFANCYCLASS_H