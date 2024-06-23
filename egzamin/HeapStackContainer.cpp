#include <iostream>
#include <type_traits>

// Limit rozmiaru dla alokacji na stosie
constexpr std::size_t StackAllocationLimit = 256;

// Klasa bazowa
template <typename T, std::size_t N, bool UseHeap>
class ContainerBase;

// Specjalizacja dla alokacji na stosie
template <typename T, std::size_t N>
class ContainerBase<T, N, false>
{
public:
    ContainerBase()
    {
        std::cout << "Allocating on stack\n";
    }

    T& operator[](std::size_t index)
    {
        return data[index];
    }

private:
    T data[N];
};

// Specjalizacja dla alokacji na stercie
template <typename T, std::size_t N>
class ContainerBase<T, N, true>
{
public:
    ContainerBase()
    {
        std::cout << "Allocating on heap\n";
        data = new T[N];
    }

    ~ContainerBase()
    {
        delete[] data;
    }

    T& operator[](std::size_t index)
    {
        return data[index];
    }

private:
    T* data;
};

// Główny szablon klasy
template <typename T, std::size_t N>
class Container : public ContainerBase<T, N, (N > StackAllocationLimit)>
{
};

// Przykład użycia
int main()
{
    Container<int, 100> smallContainer; // Alokacja na stosie
    Container<int, 300> largeContainer; // Alokacja na stercie

    smallContainer[0] = 1;
    largeContainer[0] = 2;

    std::cout << "smallContainer[0]: " << smallContainer[0] << "\n";
    std::cout << "largeContainer[0]: " << largeContainer[0] << "\n";

    return 0;
}
