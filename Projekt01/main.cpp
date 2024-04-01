#include <iostream>
#include <vector>
#include "IKsiazka.h"
#include "Ksiazka.h"
#include "Czasopismo.h"
#include "Komiks.h"

int main() {
    std::vector<IKsiazka*> ksiazki;
    // tytuł, autor, id, gstunek, na której półce się znajduje
    Ksiazka* ksiazka = new Ksiazka("W pustyni i w puszczy", "Henryk Sienkiewicz", 1, "Przygodowa", 5);
    Czasopismo* czasopismo = new Czasopismo("National Geographic", "John Doe", 2, "Przyroda", 7);
    Komiks* komiks = new Komiks("Batman", "Bob Kane", 3, "DC Comics", "Superbohaterowie", 9);

    ksiazki.push_back(ksiazka);
    ksiazki.push_back(czasopismo);
    ksiazki.push_back(komiks);

    for (IKsiazka* ksiazka : ksiazki) {
        ksiazka->wyswietlInformacje();
    }

    // Nie zapomnijcie zwolnić pamięci pozostałych książek po zakończeniu działania programu. 
    for (IKsiazka* ksiazka : ksiazki) {
        delete ksiazka;
    }

    return 0;
}


/*

Mój tytuł: W pustyni i w puszczy, autor: Henryk Sienkiewicz, id: 1, gatunek: Przygodowa, leżę na półce: 5
Mój tytuł: National Geographic, autor: John Doe, id: 2, gatunek: Przyroda, leżę na półce: 7
Mój tytuł: Batman, autor: Bob Kane, id: 3, gatunek: DC Comics, leżę na półce: 9

*/