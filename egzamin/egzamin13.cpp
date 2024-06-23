#include <iostream>
#include <string>
#include <ostream>
#include <utility>


struct is_printable {

    is_printable() {}

    friend std::ostream& operator<< (std::ostream& os, const is_printable obj) {
        return os << obj._value;
    }

    void setValue(int value) {
        this->_value = std::to_string(value);
    }

    void setValue(std::string value) {
        this->_value = value;
    }

    protected:
        std::string _value;
};


class A : public is_printable {
public:
    A(const std::string text) {
        this->setValue(text);
    }

};

class B : public is_printable {
public :
    B(const int value) {
        this->setValue(value);
    }
};



int main()
{
    A a ("Tekst"); B b {123};
    std::cout<< "a:\t"<<a<<"; b:\t"<<b<<"\n";
    const is_printable& a_r = a; const is_printable& b_r = b;
    std::cout<< "a_r:\t"<<a_r<<"; b_r:\t"<<b_r<<"\n";
}

/*
a:      Tekst; b:       123
a_r:    Tekst; b_r:     123
*/