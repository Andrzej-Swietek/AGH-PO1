#include "PasazerEkonomiczny.h"
#include <iostream>

PasazerEkonomiczny::PasazerEkonomiczny(const std::string& imie, const std::string& nazwisko, const std::string& nrBiletu)
    : imie(imie), nazwisko(nazwisko), nr_karty(nrBiletu) {}

void PasazerEkonomiczny::PrzedstawSie() {
    std::cout << "Jestem pasażerem ekonomicznym." << std::endl;
    std::cout << "Mam na imię: " << imie << " " << nazwisko << " i mój nr biletu to: " << nr_karty << std::endl;
}

std::string PasazerEkonomiczny::PobierzNrBiletu() {
    return nr_karty;
}
