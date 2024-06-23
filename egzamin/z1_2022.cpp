#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> c = {1,2,3,4,5,6,7};

    std::cout << "c: ";
    std::for_each(c.begin(), c.end(), [](int x){
        std::cout << x << " ";
    });

    std::cout << "\nc parzyste: ";
    std::for_each(c.begin(), c.end(), [](int x){
        if(x % 2 == 0) std::cout << x << " ";
    });

    std::cout << "\nc malejaco: ";
//    std::sort(c.begin(), c.end(), std::greater<int>());
    std::sort(c.begin(), c.end(), [](int a, int b) -> bool  {
        return (a>b);
        // a > b > c > d
        // 7 > 6 > 5 > 4
    });
    std::for_each(c.begin(), c.end(), [](int x){
        std::cout << "[" << x << "] ";
    });

    std::cout << "\nc + x: ";
    int x=5;
    std::for_each(c.begin(), c.end(), [x](int& i) mutable {
        i += x;
    });
    std::for_each(c.begin(), c.end(), [](int x){
        std::cout << x << ", ";
    });

    // modyfikuje x i zwraca wartosc std::fucntion<int(int)>
    auto f = [&x](int i)mutable {
        x+=i;
        return x;
    };
    std::cout << "\nx: " << x << " ";
    std::cout << "f: " << f(6) << " ";
    std::cout << "x: " << x << std::endl;

    return 0;
}

//cout << endl << "The array after sorting is(asc) :";
//sort(a, a + asize);
//show(a, asize);
//cout << endl << "The array after sorting is(desc) :";
//sort(a, a + asize, greater<int>());

/*
c: 1 2 3 4 5 6 7
c parzyste: 2 4 6
c malejaco: [7] [6] [5] [4] [3] [2] [1]
c + x: 12, 11, 10, 9, 8, 7, 6,
x: 5 f: 11 x: 11
*/

//NASZ
//❯ ./a.out                                                                                                                                                                                                                                                                                                ─╯
//c: 1 2 3 4 5 6 7
//c parzyste: 2 4 6
//c malejaco: [7] [6] [5] [4] [3] [2] [1]
//c + x: 12, 11, 10, 9, 8, 7, 6,
//x: 5 f: 11 x: 11
