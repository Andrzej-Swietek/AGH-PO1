#include <iostream>

using namespace std;

class A {
public:

    A(): A(0, 0) {
        cout << __PRETTY_FUNCTION__ << ": _a=" << 0 << ",_b=" << 0 << "\n";
    }

    A(int a):  A(a, 0) {
        cout << __PRETTY_FUNCTION__ << ": _a=" << a << ",_b=" << 0 << "\n";
    }

    A(int a, int b): _a(a), _b(b) {
        cout << __PRETTY_FUNCTION__ << ": _a=" << a << ",_b=" << b << "\n";
    }

    A(A&& object) {
        this->_a = std::move(object._a);
        this->_b = std::move(object._b);
        cout << "A[...]: _a=" << _a << "_b="<<_b << "\n";
    }

private:
    int _a, _b;
};

int main()
{
    cout << "a->"; A a;
    cout << "b->"; A b(1);
    cout << "c->"; A c(1,2);

    cout << "d->"; A d = std::move(c);

    //A e = c;
    //A f = 1;
}
/*
a-> A::A(int,int): _a=0,_b=0
A::A(): _a=0,_b=0
b-> A::A(int,int): _a=1,_b=0
A::A(int): _a=1,_b=0
c-> A::A(int,int): _a=1,_b=2
d-> A::[...]: _a=1,_b=2
*/