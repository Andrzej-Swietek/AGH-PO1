#include <iostream>

// Prosta klasa testowa
class Test
{
public:
    Test() { std::cout << "Test created\n"; }
    ~Test() { std::cout << "Test destroyed\n"; }
    void sayHello() { std::cout << "Hello from Test\n"; }
};

// Własny unikalny wskaźnik
template <typename T>
class UniquePtr
{
public:
    // Konstruktor domyślny
    explicit UniquePtr(T* ptr = nullptr) : ptr_(ptr) {}

    // Konstruktor przenoszący
    UniquePtr(UniquePtr&& other) noexcept : ptr_(other.ptr_)
    {
        other.ptr_ = nullptr;
    }

    // Operator przypisania przenoszącego
    UniquePtr& operator=(UniquePtr&& other) noexcept
    {
        if (this != &other)
        {
            delete ptr_;
            ptr_ = other.ptr_;
            other.ptr_ = nullptr;
        }
        return *this;
    }

    // Destruktor
    ~UniquePtr()
    {
        delete ptr_;
    }

    // Operatory dereferencji
    T& operator*() const { return *ptr_; }
    T* operator->() const { return ptr_; }

    // Zwraca surowy wskaźnik
    T* get() const { return ptr_; }

    // Zwalnia zarządzany obiekt i zwraca surowy wskaźnik
    T* release()
    {
        T* temp = ptr_;
        ptr_ = nullptr;
        return temp;
    }

    // Zastępuje zarządzany obiekt nowym
    void reset(T* ptr = nullptr)
    {
        delete ptr_;
        ptr_ = ptr;
    }

    // Zakaz kopiowania
    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;

private:
    T* ptr_;
};

// Przykład użycia
int main()
{
    // Tworzenie unikalnego wskaźnika do obiektu Test
    UniquePtr<Test> p1(new Test());
    p1->sayHello();

    // Przenoszenie własności
    UniquePtr<Test> p2 = std::move(p1);
    if (!p1.get())
    {
        std::cout << "p1 is null\n";
    }

    p2->sayHello();

    // Resetowanie wskaźnika
    p2.reset(new Test());
    p2->sayHello();

    // Zwolnienie zarządzanego obiektu
    Test* rawPtr = p2.release();
    if (!p2.get())
    {
        std::cout << "p2 is null after release\n";
    }
    delete rawPtr;

    return 0;
}
