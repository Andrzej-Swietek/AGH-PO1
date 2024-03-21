#ifndef Pasazer_H
#define Pasazer_H

#include<iostream>
#include <string>

class IPasazer {

public:

    // IPasazer(const std::string& name,const  std::string& lastname,const  std::string nr_karty ): imie(imie), nazwisko(lastname), nr_karty(nr_karty){}
    /**
     * PASAGER DESTRUCTOR
    */
    ~IPasazer() = default;

    /**
     * Method providing descriptiove user bio
    */
    virtual void PrzedstawSie() = 0;

    /**
     * Method getting numer of ticket - used for Lot-> get user by 
    */
    virtual std::string PobierzNrBiletu() = 0;


};

#endif  