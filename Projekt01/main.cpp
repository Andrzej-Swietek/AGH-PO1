#include <iostream>
#include <vector>
#include "IKsiazka.h"
#include "Ksiazka.h"
#include "Czasopismo.h"
#include "Komiks.h"

#include "Library.h"
#include "User.h"

int main() {

    Library library;

    // tytuł, autor, id, gstunek (gatunki? - to przeciążenie ponadprogramowe, kto podoła dostanie uśmiechniętego emotikona w komentarzu do oceny), na której półce się znajduje
    Ksiazka* ksiazka = new Ksiazka("W pustyni i w puszczy", "Henryk Sienkiewicz", 1, "Przygodowa", 5);
    Czasopismo* czasopismo = new Czasopismo("National Geographic", "John Doe", 2, "Przyroda", 7);
    // Komiks* komiks = new Komiks("Batman", "Bob Kane", 3, "DC Comics","Superbohaterowie", 9);
    Komiks* komiks = komiks = new Komiks("Batman", "Bob Kane", 3, "DC Comics", "Superbohaterowie", 9);

    library.addMaterial(ksiazka);
    library.addMaterial(czasopismo);
    library.addMaterial(komiks);

    User user1("Jan Piotrowski");
    User user2("Anna Pietruszka");

    // Wypożycz książki przez użytkowników
    library.borrowBook("Batman", user1);
    library.borrowBook("Wiedźmin", user2); // Próba wypożyczenia nieistniejącej książki
    library.borrowBook("Batman", user2); // Próba wypożyczenia niedostępnej już książki
    library.borrowBook("W pustyni i w puszczy", user2);


    // Wyświetl informacje o wypożyczonych książkach
    std::cout << "\nKonto użytkowinka " << user1.getName() << ":\n";
    user1.displayBorrowedBooks();

    std::cout << "\nKonto użytkowinka " << user2.getName() << ":\n";
    user2.displayBorrowedBooks();

    // Zwróć książki
    library.returnBook("W pustyni i w puszczy", user1);
    library.returnBook("Batman", user1);
    library.returnBook("W pustyni i w puszczy", user2);

    // Wyświetl informacje o wszystkich książkach w bibliotece
    std::cout << "\nWszystkie książki w bibliotece:\n";
    library.displayAllBooks();

    return 0;
}


//int main(){
    //    std::vector<IKsiazka*> ksiazki;
//
//    // tytuł, autor, id, gstunek, na której półce się znajduje
//    Ksiazka* ksiazka = new Ksiazka("W pustyni i w puszczy", "Henryk Sienkiewicz", 1, "Przygodowa", 5);
//    Czasopismo* czasopismo = new Czasopismo("National Geographic", "John Doe", 2, "Przyroda", 7);
//    Komiks* komiks = new Komiks("Batman", "Bob Kane", 3, "DC Comics", "Superbohaterowie", 9);
//
//    ksiazki.push_back(ksiazka);
//    ksiazki.push_back(czasopismo);
//    ksiazki.push_back(komiks);
//
//    for (IKsiazka* ksiazka : ksiazki) {
//        ksiazka->wyswietlInformacje();
//    }
//
//    // Nie zapomnijcie zwolnić pamięci pozostałych książek po zakończeniu działania programu.
//    for (IKsiazka* ksiazka : ksiazki) {
//        delete ksiazka;
//    }
//
//    return 0;
//}

/*

Mój tytuł: W pustyni i w puszczy, autor: Henryk Sienkiewicz, id: 1, gatunek: Przygodowa, leżę na półce: 5
Mój tytuł: National Geographic, autor: John Doe, id: 2, gatunek: Przyroda, leżę na półce: 7
Mój tytuł: Batman, autor: Bob Kane, id: 3, gatunek: DC Comics, leżę na półce: 9

*/