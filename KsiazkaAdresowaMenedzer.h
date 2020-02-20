#ifndef KSIAZKAADRESOWAMENEDZER_H
#define KSIAZKAADRESOWAMENEDZER_H

#include <iostream>
#include <vector>
#include "Adresat.h"

using namespace std;

class KsiazkaAdresowaMenedzer
{
    vector<Adresat> adresaci;

public:
    void wczytajAdresatowZPliku(vector<Adresat> &adresaci);
    int dodajAdresata(vector<Adresat> &adresaci, int idZalogowanegoUzytkownika);
    void wyswietlWszystkichAdresatow(vector<Adresat> &adresaci, int idZalogowanegoUzytkownika);
};

#endif