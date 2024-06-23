#include<iostream>
#include<deque>


template<typename T = int, template<typename...> class StorageType = std::deque>
class fifo
{
public:

    fifo(){
        std::cout<<__PRETTY_FUNCTION__<<"\n";
    }

    fifo(const fifo& other) {
        store = other.store;
    }

    using storage_type = StorageType<T>;

    void push(T value){ store.push_back(value); }

    size_t size() const { return store.size(); }

    T get() {
        T tmp =  store[0];
        store.pop_front();
        return tmp;
    }

    typename storage_type::const_iterator begin() const {
        return store.begin();
    }


    // Używamy typename, aby wskazać, że storage_type::const_iterator jest typem
    typename storage_type::const_iterator end(){
        return store.end();
    };

private:

    StorageType<T> store;
};



int main(){
    fifo<> ft;
    for(int i: {0,1,2,3,4})
        ft.push(i);

    fifo<int, std::deque> f = ft;

    std::cout << f.get();
    std::cout << f.size();

    for(fifo<>::storage_type::const_iterator i = f.begin(); i != f.end(); ++i)
        std::cout << *i << ",";
}
/*
  Wynik:
  fifo<T, StorageType>::fifo() [with T = int, StorageType = std::deque]
  0
  4
  1,2,3,4,
*/

/*
    W C++ typename jest używane do oznaczenia, że coś jest typem. Jest to potrzebne w niektórych kontekstach szablonów, aby kompilator mógł prawidłowo interpretować kod.

    Dlaczego typename jest potrzebne w typename storage_type::const_iterator
            Kiedy używamy szablonów, kompilator nie zawsze wie, czy dany identyfikator jest typem, czy czymś innym, np. polem statycznym lub funkcją. Dlatego w przypadku zależnych nazw w szablonach musimy jasno powiedzieć kompilatorowi, że coś jest typem.

    Przyjrzyjmy się Twojemu przykładowi:

    tym przypadku storage_type jest aliasem dla StorageType<T>, co oznacza, że storage_type::const_iterator może być różne w zależności od tego, jaki typ jest przekazywany jako StorageType. Kompilator nie wie z góry, że storage_type::const_iterator jest typem, więc musimy użyć typename, aby to jasno określić.

    Ogólne zasady używania typename
            Kiedy nie jest potrzebne:

    Gdy odwołujesz się do typu zdefiniowanego w zakresie nieszablonowym.
    Gdy odwołujesz się do typu zdefiniowanego w tym samym zakresie, co kod, który go używa.
    Kiedy jest potrzebne:

    W Wrapper, container_type jest aliasem dla Container<T>, a container_type::iterator jest typem zależnym od szablonu T. Kompilator nie może zgadnąć, że container_type::iterator jest typem bez wyraźnego wskazania typename.

    Podsumowanie
            Używanie typename jest konieczne w kontekstach szablonowych, aby pomóc kompilatorowi odróżnić typy od innych nazw, takich jak pola statyczne lub funkcje. Dzięki temu kompilator może poprawnie zinterpretować kod i uniknąć niejednoznaczności. W Twoim przypadku, typename storage_type::const_iterator jest używane, aby jednoznacznie określić, że const_iterator jest typem zdefiniowanym wewnątrz storage_type.

    */