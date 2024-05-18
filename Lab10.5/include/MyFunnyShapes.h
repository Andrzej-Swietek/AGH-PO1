#ifndef MYFUNNYSHAPES_H
#define MYFUNNYSHAPES_H

#include <iostream>

// Base class Shape
template<typename T>
class Shape {
public:
    virtual T area() const = 0;
};

// Derived class Circle
template<typename T>
class Circle : public Shape<T> {
private:
    T radius_; // Standardize variable names

public:
    Circle(T r) : radius_(r) {}

    T area() const override {
        return 3.14 * radius_ * radius_;
    }

    // Overloading the + operator for Circle
    Circle<T> operator+(const Circle<T>& other) {
        return Circle<T>(radius_ + other.radius_);
    }

    // Overloading the << operator for Circle
    friend std::ostream& operator<<(std::ostream& os, const Circle<T>& circle) {
        return os << "Circle - Radius: " << circle.radius_;
    }
};

// Derived class Rectangle
template<typename T>
class Rectangle : public Shape<T> {
    // Private members
    T length_{}; // Initialize variables
    T width_{};

public:
    // Constructor
    Rectangle(T l, T w) : length_(l), width_(w) {}

    // Calculate the area of the rectangle
    T area() const override {
        return length_ * width_;
    }

    // Overloading the + operator for Rectangle
    Rectangle<T> operator+(const Rectangle<T>& other) {
        return Rectangle<T>(length_ + other.length_, width_ + other.width_);
    }

    // Overloading the << operator for Rectangle
    friend std::ostream& operator<<(std::ostream& os, const Rectangle<T>& rectangle) {
        return os << "Rectangle:\n"
                  << "Length: " << rectangle.length_ << "\n"
                  << "Width:  " << rectangle.width_;
    }
};

#endif // MYFUNNYSHAPES_H
