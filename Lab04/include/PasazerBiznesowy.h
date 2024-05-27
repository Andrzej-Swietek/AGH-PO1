#ifndef PB_H
#define PB_H

#include<iostream>
#include"IPasazer.h"

class PasazerBiznesowy : public IPasazer {
public:
    /*
        Constructor 
        Params strngs: name last name card number , money
    */
    PasazerBiznesowy(const std::string& imie, const std::string& nazwisko, const std::string& nrKartyKredytowej, double stanKonta);

    /**
     * Destructor
    */
    ~PasazerBiznesowy();

    /**
     * Method getting numer of ticket - used for Lot-> get user by 
    */
    virtual void PrzedstawSie() override;
    
    virtual std::string PobierzNrBiletu() override;

private: 
    std::string imie;
    std::string nazwisko;
    std::string nr_karty;
    int stanKonta = 0;
};

#endif