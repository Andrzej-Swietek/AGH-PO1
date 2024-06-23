#include <iostream>

// w całym kodzie można bezpośrednio wywoływać tylko dwie funkcje: printOn i operator <<
// wypisywanie może się odbywać tylko z wykorzystaniem __PRETTY_FUNCTION__ i "\n"
//  __PRETTY_FUNCTION__ zawiera pełną nazwę funkcji w danym miejscu

class B {
public:
    virtual ~B() = default;

    friend std::ostream& operator<< (std::ostream& os, const B &b)
    {
       return b.printOn(os);
    }
    virtual std::ostream& printOn(std::ostream & os) const = 0;
};

std::ostream& B::printOn(std::ostream & os) const {
    os << __PRETTY_FUNCTION__ <<"\n";
    return os;
}

class D1 : public B {
public:
    std::ostream& printOn(std::ostream & os) const override {
        os << __PRETTY_FUNCTION__ <<"\n";
        return os;
    }
};


class D2 : public D1 {
public:
};

class  D3 : public D1  {
public:
//    D3() = default;
    virtual std::ostream& printOn(std::ostream & os) const {
        os << __PRETTY_FUNCTION__ <<"\n";
        return os;
    }
    friend std::ostream& operator<< (std::ostream& os, const D3 &b)
    {
        return b.printOn(os);
    }
};

class D4 : public D3{

    virtual std::ostream& printOn(std::ostream & os) const override {
        D1::B::printOn(os);
        D1::printOn(os);
        D3::printOn(os);
        os << __PRETTY_FUNCTION__ ;
        return os;
    }
};

int main(int argc, char *argv[]) {
    // B b; odkomentowanie powoduje błąd kompilacji
    D1 d1; D2 d2; D3 d3; const D4 d4;
    std::cout << "d1: " << d1 << "d2: " << d2 << "d3: " << d3 << "d4: " << d4;
}

/* Output:
d1: virtual std::ostream& D1::printOn(std::ostream&) const
d2: virtual std::ostream& D1::printOn(std::ostream&) const
d3: virtual std::ostream& D3::printOn(std::ostream&) const
d4: virtual std::ostream& B::printOn(std::ostream&) const
virtual std::ostream& D1::printOn(std::ostream&) const
virtual std::ostream& D3::printOn(std::ostream&) const
virtual std::ostream& D4::printOn(std::ostream&) const
*/