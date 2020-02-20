#ifndef KSIAZKAADRESOWAMENEDZER_H
#define KSIAZKAADRESOWAMENEDZER_H

#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include "Adresat.h"

using namespace std;

class KsiazkaAdresowaMenedzer
{
    vector<Adresat> adresaci;
    int idOstatniegoAdresata;

public:
    KsiazkaAdresowaMenedzer();
    void wczytajAdresatowZPliku(vector<Adresat> &adresaci);
    int dodajAdresata(vector<Adresat> &adresaci, int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
    void wyswietlWszystkichAdresatow(vector<Adresat> &adresaci, int idZalogowanegoUzytkownika);
    int pobierzIdOstatniegoAdresata();
};

#endif