#include <iostream>

template<typename T>
class B {
public:
    using value_type = T;

    B(T value): _val(value) {};

    T get() {
        return _val;
    }

    T _val;
};


template<typename T>
class B <T*>{
public:
    using value_type = T;

    B(T* value): _val(value) {};

    ~B() { delete _val; }

    T get() {
        return *_val;
    }

    T* _val;
};



int main()
{
    typedef B<int> int_b;
    typedef B<int*> int_p_b;        //jednak typedef

    int_b a(1);
    int_b a_copy(a);
    int_p_b b(new int_p_b::value_type{2});
    // int_p_b e = b; //error
    // b=b //error

    std::cout << "a=" << a.get() << std::endl;
    std::cout << "a_copy=" << a_copy.get()+1 << std::endl;
    std::cout <<" b=" << b.get()+1 << std::endl;
}


/*
    a=1
    a_copy=2
    b=3
 */