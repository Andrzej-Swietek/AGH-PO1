#ifndef LOT_H
#define LOT_H

#include <iostream>
#include <vector>

#include"IPasazer.h"

class Lot {
private:
    std::string numerLotu;
    std::string data;
    std::string skad;
    std::string dokad;
    std::vector<IPasazer*> pasazerowie;
public:

    /**
     * Only Lot constructor 
     * getting as params all its fields 
    */
    Lot(const std::string& numerLotu, const std::string& data, const std::string& skad, const std::string& dokad);
    /**
     * Lot object destructor
    */
    ~Lot();

    std::string getNumerLotu() const;

    void rezerwujBilet(IPasazer* pasazer);

    void wyswietlRezerwacje() const;

    void zwolnijPojedynczegoPaszera(const std::string& nrBiletu);

    void zwolnijWszystkichPaszazerow();

    void zwolnijWszystkichPaszazerowbiletu();
};

#endif