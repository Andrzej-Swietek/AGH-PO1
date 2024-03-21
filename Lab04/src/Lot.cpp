#include "Lot.h"


Lot::Lot(const std::string& numerLotu, const std::string& data, const std::string& skad, const std::string& dokad)
    : numerLotu(numerLotu), data(data), skad(skad), dokad(dokad) {}

Lot::~Lot() {
    for (auto pasazer : pasazerowie) {
        delete pasazer;
    }
    pasazerowie.clear();
}


std::string Lot::getNumerLotu() const
{
    return this->numerLotu;
}


void Lot::rezerwujBilet(IPasazer* pasazer) {
    pasazerowie.push_back(pasazer);
}

void Lot::wyswietlRezerwacje() const {
    for (const auto& pasazer : pasazerowie) {
        pasazer->PrzedstawSie();
        std::cout << std::endl;
    }
}

void Lot::zwolnijPojedynczegoPaszera(const std::string& nrBiletu) {
    for (auto it = pasazerowie.begin(); it != pasazerowie.end(); ++it) {
        if ((*it)->PobierzNrBiletu() == nrBiletu) {
            delete *it;
            pasazerowie.erase(it);
            break;
        }
    }
}

void Lot::zwolnijWszystkichPaszazerow() {
    for (auto pasazer : pasazerowie) {
        delete pasazer;
    }
}

void Lot::zwolnijWszystkichPaszazerowbiletu()
{
        for (auto pasazer : pasazerowie) {
        delete pasazer;
    }
    pasazerowie.clear();
}