#include "PasazerPremiumEconomy.h"


PasazerPremiumEconomy::PasazerPremiumEconomy(const std::string& imie, const std::string& nazwisko, const std::string& nrKartyKredytowej, bool czySalonVIP)
    : imie(imie), nazwisko(nazwisko), nr_karty(nrKartyKredytowej), vip(czySalonVIP) {}

void PasazerPremiumEconomy::PrzedstawSie() {
    std::cout << "Jestem pasażerem Premium Economy." << std::endl;
    std::cout << "Mam na imię: " << imie << " " << nazwisko << " i mój nr karty kredytowej to: " << nr_karty << std::endl;
    if (vip)
        std::cout << "Posiadam dostęp do Salonu VIP." << std::endl;
    else
        std::cout << "Nie posiadam dostępu do Salonu VIP." << std::endl;
}

std::string PasazerPremiumEconomy::PobierzNrBiletu() {
    return nr_karty;
}
