#ifndef PPE_H
#define PPE_H
#include<iostream>
#include"IPasazer.h"



class PasazerPremiumEconomy: public IPasazer {

public:

    /*
        Constructor 
        Params strngs: name last name card number 
    */
    PasazerPremiumEconomy(const std::string& imie, const std::string& nazwisko, const std::string& nrKartyKredytowej, bool czySalonVIP);

    /**
     * Destructor
    */
    ~PasazerPremiumEconomy();


    /**
     * Method that introduces user
    */
    virtual void PrzedstawSie() override;
    
    virtual std::string PobierzNrBiletu() override;

private: 
    bool vip = false;
    std::string imie;
    std::string nazwisko;
    std::string nr_karty;
};

#endif