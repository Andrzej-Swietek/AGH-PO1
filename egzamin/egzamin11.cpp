/*

1. słowo kluczowa mutable + podać przykład kodu
2. klasa abstrakcyjna
3. STL - uzupełnij kod

*/
#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

class A {
public:
    A() = default;
    void operator() (int& x) {
        x = counter--;
    }

    int counter = -1;
};


int main() {
    list<int> coll(11);
    for_each( std::begin(coll), std::end(coll), A());
    copy( coll.begin(), coll.end(), std::ostream_iterator<int>(std::cout,"; "));
    return 0;
}
//to ma się wyświetlić:
// -1; -2; -3; -4; -5; -6; -7; -8; -9; -10; -11;