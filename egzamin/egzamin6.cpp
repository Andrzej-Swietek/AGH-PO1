namespace std{
    class vector{};
    class list{};
    class deque{};
    class set{};
    class map{};
}

#include<cstdlib>
#include <iostream>

namespace oop {

    template <typename T>
    class Array {
    public:
        using value_type = T;

        Array(int n) {
            size = n;
            cont = new T[n];
        }


        ~Array() {
            delete cont;
        }


        Array& insert(T val) {
            T* newCont = new T[size+1];
            for(int i = 0;i<size;i++){
                newCont[i]=cont[i];
            }
            newCont[size] = val;
            size++;

            delete[] cont;
            cont = newCont;

            return *this;
        }



        T operator[](int i) {
            if(i<size) return cont[i];
            else return -1;
        }

        int operator~() {
            return size;
        }

        Array& operator+(T val) {
            return insert(val);
        }

        int size;
        T* cont;
    };

}

int main(){

    typedef oop::Array<char> type;
    type a( rand() % 10 + 6 );

    a.insert('#').insert('C') + type::value_type('+') + '+' + '0' + ('0' + 3 );

    for(unsigned i = 0; i!= ~a; ++i)
        std::cout<< a[i] << (i+1 != ~a ? "" : "\n"  );
}

/*
  #C++03
*/