/*
Proszę dopisać kod, dodać nowe pliki, tak aby program wykonywał się, 
a wynik jego działania był taki sam jak podany na końcu tego pliku.

Zadaniem będzie zaimplementowanie przez Ciebie systemu zarządzania pasażerami lotu. 
System powinien obsługiwać różne typy pasażerów (np. Biznesowy, Premium Economy i Ekonomiczny) i umożliwiać dodawanie, odczytywanie i usuwanie ich (poprzez system rezerwacji).


Wymagania:

  - Zdefiniuj interfejs IPasazer, który będzie reprezentować pasażera.
      Zwróć uwagę co się powtarza się pomiędzy pasażerami i co powinni dziedziczyć po interface. 
  - Zdefiniuj klasy PasazerBiznesowy, PasazerPremiumEconomy, PasazerEkonomiczny, które będą dziedziczyć po IPracownik.
  - Zdefiniuj klasę Lot
  - Odpowiednie klasy powinny zawierać odpowiednie metody użyte w Main.cpp.
  - Przy odczytywaniu danych pasażera, zwracaj odpowiednie informacje.
  - Przoszę zadbać o odpowiednie zarządzanie pamięcią podczas usuwania pasażerów.


Proszę zadbać o zarządzanie pamięcią.
Pliku Main.cpp nie wolno modyfikować.

Program wyjściowy powinien składać się z czytelnego kodu.
Powinna być spełniona zasada D.R.Y. - Don't Repeat Yourself.

Zadania ocenianie są wg algorytmu: 
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
│   └── PasazerBiznesowy.h
└── src
    ...
    └── PasazerBiznesowy.cpp

*/

#include <iostream>
#include <vector>
#include "IPasazer.h"
#include "PasazerBiznesowy.h"
#include "PasazerPremiumEconomy.h"
#include "PasazerEkonomiczny.h"
#include "Lot.h"

int main() {
    // Przyjmuje imię, nazwisko, nr karty kredytowej, stan konta.
    PasazerBiznesowy* pasazerBiznesowy = new PasazerBiznesowy("Jan", "Kowalski", "1234567890", 5000);
    // Przyjmuje imść, nazwisko, nr karty kredytowej, czy posiada dostęp do Salonu VIP.
    PasazerPremiumEconomy* pasazerPremiumEconomy = new PasazerPremiumEconomy("Kunekunda", "Kozielska", "0987654321", true);
    // Przyjmuje imie, nazwisko, nr karty kredytowej
    PasazerEkonomiczny* pasazerEkonomiczny = new PasazerEkonomiczny("Adam", "Nowicki", "1357924680");

    // Tworzenie przykładowego lotu
    Lot* lot = new Lot("LO123", "2024-04-15 12:00", "Warszawa", "Berlin");

    // Rezerwacja biletów dla różnych klas pasażerów na lot
    lot->rezerwujBilet(pasazerBiznesowy);
    lot->rezerwujBilet(pasazerPremiumEconomy);
    lot->rezerwujBilet(pasazerEkonomiczny);

    // Wyświetlanie informacji o rezerwacji
    std::cout << "Rezerwacja biletów na lot " << lot->getNumerLotu() << ":" << std::endl;

    // Wyswietlanie informacji o rezerwacjach dla wszystkich pasazerow
    // Funkcja powinna wołać na pasażerach funkcję do podania swoich informacji (np pasażer.przedstawSie()).
    lot->wyswietlRezerwacje();

    std::cout << "O nie - lot jest overbooked!" << std::endl;

    // Usunięcie pojedynczego pasażera z lotu -  zwolnienie pamięci pasażera
    lot->zwolnijPojedynczegoPaszera("0987654321");

    // Wyświetlanie informacji o rezerwacji po usunięciu pasażera
    std::cout << "\nPo usunieciu pasazera:" << std::endl;
    lot->wyswietlRezerwacje();

    // Usunięcie wszystkich pasazerów z lotu -  zwolnienie pamięci pozostałych pasażerów
    lot->zwolnijWszystkichPaszazerowbiletu();
    return 0;
}

// Przerwa na początku outputu dla ułatwienia waszego czytania - nie jest wymagana 
// Spodziewany output
/*

Rezerwacja biletów na lot LO123:
Jestem pasażerem biznesowym.
Mam na imię: Jan Kowalski i moj nr karty kredytowej to: 1234567890
Stan konta: 5000

Jestem pasażerem Premium Economy.
Mam na imię: Kunekunda Kozielska i moj nr karty kredytowej to: 0987654321
Posiadam dostęp do Salonu VIP.

Jestem pasażerem ekonomicznym.
Mam na imię: Adam Nowicki i moj nr biletu to: 1357924680

O nie - lot jest overbooked!

Po usunieciu pasazera:
Jestem pasażerem biznesowym.
Mam na imię: Jan Kowalski i moj nr karty kredytowej to: 1234567890
Stan konta: 5000

Jestem pasażerem ekonomicznym.
Mam na imię: Adam Nowicki i moj nr karty kredytowej to: 1357924680

*/