#include <iostream>
#include <list>
#include <functional>
#include <algorithm>


void f1(int x) {
    std::cout << x << " ";
}

void f2(int x) {
    if( x % 2 == 0 )
        std::cout << x << " ";
}



void print_to_if(std::ostream &os, std::initializer_list<int>::const_iterator start,  std::initializer_list<int>::const_iterator end, std::function<void(int)> f){

    std::for_each(start, end, f);
    std::cout << std::endl;
}

void print_to_if(std::ostream &os, std::list<int>::const_iterator start,  std::list<int>::const_iterator end, std::function<void(int)> f){
    std::for_each(start, end, f);
    std::cout << std::endl;
}


using namespace std;

class f3 {
public:
    f3(int x)
    {
        _val = x;
    }
   int _val;
};

void change(std::list<int>::iterator start,  std::list<int>::iterator end, f3 obj)
{
    std::for_each(start, end, [&](int &i) mutable{
        i += obj._val;
    });
}


int main(){
    const auto cl = {1,2,3,4,5,6,7}; // initializer_list<int>

    print_to_if(std::cout<<"All: ", begin(cl), end(cl), f1);
    print_to_if(std::cout<<"All: ", begin(cl), end(cl), f2);

    int add_value{-1};
    std::list<int> cl2 = {7,6,5,4,3,2,1};
    change(begin(cl2), end(cl2), f3{add_value});
    print_to_if(std::cout << "All  ", begin(cl2), end(cl2), f1);
}
/*
All: 1 2 3 4 5 6 7
All: 2 4 6
All  6 5 4 3 2 1 0
*/