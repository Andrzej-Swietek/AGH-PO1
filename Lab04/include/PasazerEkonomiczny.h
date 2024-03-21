#ifndef PE_H
#define PE_H

#include<iostream>
#include"IPasazer.h"

class PasazerEkonomiczny: public IPasazer {
public:
    /*
        Constructor 
        Params strngs: name last name card number 
    */
    PasazerEkonomiczny(const std::string& imie, const std::string& nazwisko, const std::string& nrBiletu);
    // PasazerEkonomiczny(const std::string& imie, const std::string& nazwisko, const std::string& nrKartyKredytowej);
 

    /**
     * Destructor
    */
    ~PasazerEkonomiczny();


    virtual void PrzedstawSie() override;

    virtual std::string PobierzNrBiletu() override;

private:
    std::string imie;
    std::string nazwisko;
    std::string nr_karty;
};

#endif