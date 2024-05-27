#include "PasazerBiznesowy.h"


PasazerBiznesowy::PasazerBiznesowy(const std::string& imie, const std::string& nazwisko, const std::string& nrKartyKredytowej, double stanKonta)
    : imie(imie), nazwisko(nazwisko), nr_karty(nrKartyKredytowej), stanKonta(stanKonta) {}


void PasazerBiznesowy::PrzedstawSie() {
    std::cout << "Jestem pasażerem biznesowym." << std::endl;
    std::cout << "Mam na imię: " << imie << " " << nazwisko << " i mój nr karty kredytowej to: " << nr_karty << std::endl;
    std::cout << "Stan konta: " << stanKonta << std::endl;
}

std::string PasazerBiznesowy::PobierzNrBiletu() {
    return nr_karty;
}
