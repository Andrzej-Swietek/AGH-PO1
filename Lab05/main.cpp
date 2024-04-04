/*
Proszę dopisać kod oraz dodać nowe pliki, tak aby program wykonywał się poprawnie, a wynik jego działania był taki sam jak podany na końcu tego pliku.

Zadaniem będzie zaimplementowanie systemu zarządzania personalną historią przeczytanych książek. System powinien umożliwiać dodawanie książek do systemu, dodawanie książek na półkę, ocenianie książek przez użytkowników jak i będzie wykorzystywać wcześniej zaimplementowane klasy.

Wymagania:

  - Zdefiniuj klasę BookArchiveApp, która będzie zarządzać książkami w biblioteczce.
  - Przy dodawaniu książek na bib lioteczkę upewnij się, że książka jest dodtępna w systemie.
  - Pamiętaj że to zadanie z dziedziczenia i z jakiegoś powodu przygotowałeś interface IKsiazka na dziś. ;) 
  - Zadbaj o pilnowanie czy oceniane/dodawane na półkę książki są poprawne.

  Zauważ, że nie wszystkie elementy zaimplementowane ostatnio w nowej książce/komiksie/czasopiśmie się ostały - czy możesz to jakoś wykorzystać?


Proszę zadbać o zarządzanie pamięcią.
Pliku Main.cpp nie wolno modyfikować, chyba że w tekście zadania podano inaczej.


Program wyjściowy powinien składać się z czytelnego kodu.
Powinna być spełniona zasada D.R.Y. - Don't Repeat Yourself.

Zadania oceniane są wg algorytmu: 
  - Warunkiem przystąpienia do oceniania programu jest jego poprawna kompilacja (bez błędów). 
  - Dokumentacja - 1 pkt. 
  - Poprawna kompilacja (bez ostrzeżeń) - 2 pkt. 
  - Poprawne wykonanie (odpowiednie wyjście, brak wycieków pamięci itp.) - 3 pkt. 
  - Ocena kodu (pod względem projektowym, zgodności z OOP, przejrzystości oraz sposobu implantacji) - maks. 4 pkt. 

Programy niezgodne z tematem/celem zadania, 
ale kompilujące się (i dające potencjalnie "poprawne" wyjście) będą oceniane na 0 pkt.

Przy wykonaniu zadania nie wolno korzystać z internetu, notatek,
ani żadnych innych materiałów (np. chatboty wbudowane w edytor).

Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
właściciela nie ma praw dostępu. Rozwiązanie (czyli dodane pliki i Main.cpp 
należy wgrać do UPEL jako archiwum tar.gz, UWAGA:
* archiwum powinno zawierać katalog z zadaniem, np. lab02/
* archiwum nie powinno zawierać katalogu build/

├── CMakeLists.txt
├── Main.cpp
├── include
│   ...
│   └── BookArchiveApp.h
└── src
    ...
    └── BookArchiveApp.cpp

*/

#include <iostream>
#include "IKsiazka.h"
#include "Ksiazka.h"
#include "Czasopismo.h"
#include "Komiks.h"
#include "BookArchiveApp.h"
#include "User.h" 

int main() {
    BookArchiveApp myBookshelf;

    // (tytuł, autor, id, gstunek)
    Ksiazka* ksiazka = new Ksiazka("W pustyni i w puszczy", "Henryk Sienkiewicz", 1, "Przygodowa");
    Czasopismo* czasopismo = new Czasopismo("National Geographic", "John Doe", 2, "Przyroda");
    Komiks* komiks = new Komiks("Batman", "Bob Kane", 3, "Superbohaterowie");

    myBookshelf.addMaterialToBase(ksiazka);
    myBookshelf.addMaterialToBase(czasopismo);
    myBookshelf.addMaterialToBase(komiks);

    User user1("Jan Piotrowski");
    User user2("Anna Pietruszka");


    myBookshelf.putOnBookshelf("Batman", user1, "Chcę przeczytać");
    myBookshelf.putOnBookshelf("W pustyni i w puszczy", user1, "Przeczytałem");
    myBookshelf.putOnBookshelf("Wiedźmin", user1, "Przeczytałem"); // Próba dodania na półkę nieznanej książki.

    myBookshelf.putOnBookshelf("Batman", user2, "Przeczytałem");
    myBookshelf.putOnBookshelf("W pustyni i w puszczy", user2, "Przeczytałem");


    // Wyświetl informacje o wypożyczonych książkach
    std::cout << "\nKonto użytkowinka " << user1.getName() << ":\n";
    user1.displayPersonalBookshelf();

    std::cout << "\nKonto użytkowinka " << user2.getName() << ":\n";
    user2.displayPersonalBookshelf();

    // Zwróć książki
    myBookshelf.rateBook("Batman", user1, 9);
    myBookshelf.rateBook("Batman", user2, 5);
    myBookshelf.rateBook("W pustyni i w puszczy", user1, 10);
    myBookshelf.rateBook("W pustyni i w puszczy", user2, 1);

    // Wyświetl informacje o wszystkich książkach w bibliotece
    std::cout << "\nWszystkie książki w bazie danych:\n";
    myBookshelf.displayAllBooks();

    return 0;

}


// If U feel fancy i wystarczy Ci czasu po wykonaniu zadania - treść dodatkowa na końcu.
// Spodziewany output.:
/*

Przepraszamy - w naszej bazie nie ma książki pod tytułem "Wiedźmin".

Konto użytkownika Jan Piotrowski:
Chcę przeczytać:
- Batman
Przeczytałem: 
- W pustyni i w puszczy


Konto użytkownika Anna Pietruszka:
Chcę przeczytać:
Przeczytałem: 
- Batman
- W pustyni i w puszczy

Przepraszamy - nie można ocenić książki, której się nie przeczytało.
// Komentarz do komentarza // Lub "Przepraszamy - nie możesz ocenić książki po okładce."

Wszystkie książki w bazie danych: 
- Batman, Bob Kane, Superbohaterowie, Średnia ocena: 5.0
- National Geographic, John Doe, Przyroda, Brak ocen
- W pustyni i w puszczy, Henryk Sienkiewicz, Przygodowa, Średnia ocena: 5.5/10.
// Komentarz do komentarza // (kolejność - albo alfabetyczna, albo wg ID - jak wolicie)

*/


// Zadania dodatkowe (nie podlegają ocenie)- jeżeli ktoś dodał książkę której nie ma na liście, dodaj ją jako propozycję do dodania do bazy? 
// Nie wiem w jaki sposób - od Twojej pomysłowości zależy.

// Dodaj counter ile osób którą książkę przeczytało i czy ocenili czy nie.
