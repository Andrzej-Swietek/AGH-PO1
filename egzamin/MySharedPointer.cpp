#include <iostream>

// Prosta klasa testowa
class Test {
public:
    Test() { std::cout << "Test created\n"; }
    ~Test() { std::cout << "Test destroyed\n"; }
    void sayHello() { std::cout << "Hello from Test\n"; }
};

// Wskaźnik współdzielony
template <typename T>
class SharedPtr {
public:
    // Konstruktor domyślny
    explicit SharedPtr(T* ptr = nullptr)
            : ptr_(ptr), ref_count_(new std::size_t(ptr ? 1 : 0)) {
    }

    // Konstruktor kopiujący
    SharedPtr(const SharedPtr& other)
            : ptr_(other.ptr_), ref_count_(other.ref_count_) {
        if (ptr_) {
            ++(*ref_count_);
        }
    }

    // Operator przypisania kopiującego
    SharedPtr& operator=(const SharedPtr& other) {
        if (this != &other) {
            release();

            ptr_ = other.ptr_;
            ref_count_ = other.ref_count_;
            if (ptr_) {
                ++(*ref_count_);
            }
        }
        return *this;
    }

    // Konstruktor przenoszący
    SharedPtr(SharedPtr&& other) noexcept
            : ptr_(other.ptr_), ref_count_(other.ref_count_) {
        other.ptr_ = nullptr;
        other.ref_count_ = nullptr;
    }

    // Operator przypisania przenoszącego
    SharedPtr& operator=(SharedPtr&& other) noexcept {
        if (this != &other) {
            release();

            ptr_ = other.ptr_;
            ref_count_ = other.ref_count_;
            other.ptr_ = nullptr;
            other.ref_count_ = nullptr;
        }
        return *this;
    }

    // Destruktor
    ~SharedPtr() {
        release();
    }

    // Operatory dereferencji
    T& operator*() const { return *ptr_; }
    T* operator->() const { return ptr_; }

    // Zwraca surowy wskaźnik
    T* get() const { return ptr_; }

    // Zwraca liczbę referencji
    std::size_t use_count() const { return *ref_count_; }

    // Sprawdza, czy wskaźnik jest pusty
    bool unique() const { return *ref_count_ == 1; }

private:
    // Zwolnienie zasobu
    void release() {
        if (ptr_ && --(*ref_count_) == 0) {
            delete ptr_;
            delete ref_count_;
        }
    }

    T* ptr_;                // Surowy wskaźnik do zarządzanego obiektu
    std::size_t* ref_count_; // Wskaźnik do licznika referencji
};

// Przykład użycia
int main() {
    {
        SharedPtr<Test> sp1(new Test());
        sp1->sayHello();

        SharedPtr<Test> sp2 = sp1;
        std::cout << "Reference count: " << sp1.use_count() << "\n";

        if (sp1.unique()) {
            std::cout << "sp1 is unique\n";
        } else {
            std::cout << "sp1 is not unique\n";
        }

        sp2->sayHello();
    } // Wskaźniki sp1 i sp2 wychodzą z zakresu, zasób jest zwalniany

    return 0;
}
