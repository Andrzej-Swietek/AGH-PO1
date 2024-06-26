#include <iostream>

// Struktura bazowa
struct Obj {
    virtual void Draw() const = 0; // metoda czysto wirtualna
    virtual ~Obj() = default;      // wirtualny destruktor
};

// Szablon Box
template<typename T>
struct Box : Obj {
    T value;

    // Konstruktor
    Box(const T& val) : value(val) {}

    // Definicja metody Draw
    void Draw() const override {
        std::cout << __PRETTY_FUNCTION__  << " ---> " << value << std::endl;
    }

    // Operator konwersji do typu T
    operator T() const {
        return value;
    }
};

// Specjalizacja Box dla typu Box<T>
template<typename T>
struct Box<Box<T>> : Obj {
    Box<T> value;

    // Konstruktor
    Box(const Box<T>& val) : value(val) {}

    // Definicja metody Draw
    void Draw() const override {
        value.Draw();
    }

    // Operator konwersji do typu Box<T>
    operator Box<T>() const {
        return value;
    }
};

int main() {
    Box<int> b_i {13};          Obj& r_1 = b_i;  r_1.Draw(); int i = b_i;
    Box<double> b_d {14.15};    Obj& r_2 = b_d;  r_2.Draw(); double d = b_d;
    Box<Box<int>> bb_i {b_i};   const Obj& r_3 = bb_i; r_3.Draw(); Box<int> br_i = bb_i;
    Box<Box<double>> bb_d {b_d}; const Obj& r_4 = bb_d; r_4.Draw(); Box<double> b_a = bb_d;
    // Box<int> _ = 1;     // BŁĄD KOMPILACJI
}
