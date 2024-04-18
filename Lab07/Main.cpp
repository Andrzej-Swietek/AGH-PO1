/* Zadaniem będzie zaimplementowanie systemu zarządzania postaciami w grze. System powinien umożliwiać tworzenie postaci różnych typów (wojownik, czarodziej, złodziej) oraz zarządzanie ich stanami.

Wymagania:
    
    - Zdefiniuj klasę State, która będzie przechowywała stan postaci (Wymaganie - wykorzystaj enum class, enum struct, enum....) (Idle, Attacking, Resting).
    - Zdefiniuj klasę Character, która będzie bazową klasą dla różnych typów postaci.
    - Utwórz klasy Warrior, Wizard i Thief, które dziedziczą po klasie Character i implementują jej metody wirtualne.
    - Każda postać powinna mieć możliwość zmiany swojego stanu (Idle, Attacking, Resting).
    - Pamiętaj, że to zadanie z dziedziczenia, polimorfizmu i prezentujące użycie dynamic_cast. Każda postać powinna mieć unikalne cechy i zachowania.
    - Proszę zadbać o zarządzanie pamięcią. Pamiętaj o zwolnieniu pamięci po utworzonych postaciach.
    - Metoda perform_action() powinna wykorzystać dynamic_cast do sprawdzania z jaką klasą mamy do czynienia. (złodziej z wytrychem nie może atakować)
    - Metoda equip() powinna zapewniać, że każdy rodzaj ekwipunku może wyć wykorzystany tylko przez daną klasę.

Pliku Main.cpp nie wolno modyfikować, chyba że w tekście zadania podano inaczej (Oznaczenie TODO:).

Program wyjściowy powinien składać się z czytelnego kodu. Powinna być spełniona zasada D.R.Y. - Don’t Repeat Yourself.

Zadania oceniane są wg algorytmu:

    Warunkiem przystąpienia do oceniania programu jest jego poprawna kompilacja (bez błędów).
    Dokumentacja - 1 pkt.
    Poprawna kompilacja (bez ostrzeżeń) - 2 pkt.
    Poprawne wykonanie (odpowiednie wyjście, brak wycieków pamięci itp.) - 3 pkt.
    Ocena kodu (pod względem projektowym, zgodności z OOP, przejrzystości oraz sposobu implantacji) - maks. 4 pkt. */


#include <iostream>
#include <vector>
#include "Character.h"
#include "Warrior.h"
#include "Wizard.h"
#include "Thief.h"

#include "Sword.h"
#include "Lockpick.h"
#include "Staff.h"

// void perform_action(Character* character) {
//     switch (character->get_state()) {
//         // TODO: Implement me - enum states, and use dynamic caast to get our desired outcome! 
//     }
// }


void perform_action(Character* character) {
    switch (character->get_state()) {
        case State::Idle:
            std::cout << character->get_name() << " is idling around.\n";
            break;
        case State::Attacking:
            character->perform_action();
            break;
        case State::Defending:
            std::cout << character->get_name() << " is defending.\n";
            break;
        case State::Resting:
            std::cout << character->get_name() << " is resting.\n";
            break;
    }
}


int main() {
    std::vector<Character*> characters;

    characters.push_back(new Warrior("Conan"));
    characters.push_back(new Wizard("Gandalf"));
    characters.push_back(new Thief("Carmen Sandiego"));

    Equipment* sword = new Sword();
    Equipment* staff = new Staff();
    Equipment* lockpick = new Lockpick();

    for (auto* character : characters) {
        character->equip(sword);
        character->equip(staff);
        character->equip(lockpick);
    }

    for (auto* character : characters) {
        character->set_state(State::Idle);
        perform_action(character);
    }

    for (auto* character : characters) {
        character->set_state(State::Attacking);
        perform_action(character);
    }

    for (auto* character : characters) {
        if (auto* unrelated = dynamic_cast<std::string*>(character)) {
            std::cout << "This code is never reached, as the dynamic_cast failed.\n";
            // Egzample of unreachable code and checking for class of character - if it's a string type character, then... 
        }
    }

    delete sword;
    delete staff;
    delete lockpick;

    for (auto* character : characters) {
        delete character;
    }


    characters.clear();

    return 0;
}


// Spodziewany output: 

/*

Sword created.
Staff created.
Lockpick created.

Conan the Warrior is idling around.
Gandalf the Wizard is idling around.
Carmen Sandiego the Thief is idling around.

Conan the Warrior swings a sword!
Gandalf the Wizard is casting a spell with staff!



*/

// Ponadprogramowe:
/*
(feel free to change idling for Defending and resting in feperet loop for different types of characters - use dynamic cast to get desired results)
*/
