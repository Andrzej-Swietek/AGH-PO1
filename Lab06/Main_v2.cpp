
#include <iostream>
#include <vector>
#include "Animal.h"
#include "Lion.h"
#include "Tiger.h"
#include "Bear.h"

#include <memory>

int main() {
    std::vector<Animal*> zoo;

    // Dodaj zwierzęta do zoo
    zoo.push_back(new Lion());
    zoo.push_back(new Tiger());
    zoo.push_back(new Bear());
    

    /**
     * Komentarz
     * 
     * Wczesne wianie jest realizowane kiedy:
     *  - Wywołanie na rzecz objektu ( nie wsakznika ) np tiger.useSkill();
     *  - Uzycie kwantyfikatora zasięgu :: na wzkazniku do objektu np.  tiger_ptr->Tiger::funkcja_wirtualna();
     *  - Wywołanie w konstruktorze
    */

    Tiger* tiger = new Tiger();
    Lion* lion = new Lion();
    Bear* bear = new Bear();

    bear->Bear::useSkill(); // Wchodzi Wczesne wiazanie 
    lion->Lion::useSkill();
    tiger->Tiger::useSkill();

    bear->Bear::eat(); 
    lion->Lion::eat();
    tiger->Tiger::eat();

; 
    tiger->Tiger::interact(lion);
    tiger->Tiger::interact(bear); 

    bear->Bear::interact(tiger); 
    bear->Bear::interact(lion);
    
    lion->Lion::interact(tiger);
    lion->Lion::interact(bear);




    delete lion; delete bear; delete tiger;

    // // Każde zwierzę wykonuje swoje działania
    // for (Animal* animal : zoo) {
    //     animal->makeSound();
    //     animal->eat();
    //     // animal->sleep();
    // }

    // // Zwierzęta wchodzą w interakcje z innymi zwierzętami
    // for (Animal* animal1 : zoo) {
    //     for (Animal* animal2 : zoo) {
    //         if (animal1 != animal2) {
    //             animal1->interact(animal2);
    //         }
    //     }
    // }

    // // Zwierzęta wykorzystują swoje unikalne umiejętności
    // for (Animal* animal : zoo) {
    //     animal->useSkill();
    // }

    // // Usuń zwierzęta
    // for (Animal* animal : zoo) {
    //     delete animal;
    // }

    return 0;
}

//Dodatkowe TODO - jak zostanie wam więcej czasu:
/*
Zaproponuj w komentarzu, lub w pliku Main_v2.cpp wersję main(): która wykona to samo z wykorzystaniem wiązania wczesnego a nie późnego. 
*/


// Spodziewany output z zadania:
/*
Lion roars
Lion eats meet

Tiger growls
Tiger eats meet

Bear grunts
Bear eats fish

Lion roars at Tiger
Lion roars at Bear

Tiger stares at Lion
Tiger stares at Bear

Bear grunts at Lion
Bear grunts at Tiger

Lion uses Hyper Voice skill
Tiger uses Flare Blitz skill 
Bear uses Belly Drum skill
*/