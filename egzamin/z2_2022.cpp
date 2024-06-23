#include <utility>
#include <iostream>


/* UZUPEŁNIJ 1 */

template<typename T = float>
class Type_t {
public:
    Type_t() = default;
    explicit Type_t(T x): _v(x) {}

    friend std::ostream& operator<< (std::ostream &stream, const Type_t<T> & obj){
        return stream << obj._v << " ";
    }

    T _v;
};


using Float_t = Type_t<>; // type_t opakowywacz dowolnego typu


template<typename T>
struct ptr {

    using value_type = T;

    ptr() = default;
    explicit ptr(T* value) {
        _pointer = value;
    }

    // semantyka kopiowania zablokowana
    ptr(const T& obj) = delete;
    ptr& operator=(const T& obj) = delete;

    // semantyka przenoszenia ok
    ptr(T&& obj) {
        _pointer = obj._pointer;
        obj._pointer = nullptr;
    };

//    ptr& operator=(T&& obj) {
//        _pointer = obj._pointer;
//        obj._pointer = nullptr;
//    };
    ptr& operator=(T&& obj) = delete;

    // operator *
    T& operator*() const {
        return *_pointer;
    }

    T* operator->() const{
        return _pointer;
    }

    T* _pointer;
};



int main()
{
    using Type_t = ptr<std::pair<Float_t, Float_t>>; //

    Type_t t1{new Type_t::value_type{}};
    // Type_t t2 = t1;
    // Type_t t2; t2 = t1;
    // Type_t t2 = new Type_t::value_type();

    // Powyższe się mają nie kompilować
    (*t1).first = Type_t::value_type::first_type{1.};
    t1->second = Type_t::value_type::second_type{2.5};

    Type_t t2 = std::move(t1);


                               // tutaj było chyba const t3, ale nie pamiętam, w jaki sposób było inicjalizowane
    const Type_t t3 = std::move(t2);
    //(*t3).first= 13; // Błąd: const obiekt
    // t3->second = 13;
    // t3 = std::move(t2);
    // Powyższe się mają nie kompilować

    (*t3).first = Type_t::value_type::first_type{1};   //?
    t3->second = Type_t::value_type::second_type{2.5}; //?


    std::cout << (*t3).first._v << ", " << t3->second << std::endl;
}
/* output:
1, 2.5
*/