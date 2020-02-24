#ifndef KSIAZKAADRESOWAMENEDZER_H
#define KSIAZKAADRESOWAMENEDZER_H

#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>

#include "Adresat.h"
#include "PlikZAdresatami.h"

using namespace std;

class KsiazkaAdresowaMenedzer
{
    vector<Adresat> adresaci;
    int idOstatniegoAdresata;
    PlikZAdresatami plikZAdresatami;

public:
    int wczytajAdresatowZPliku(vector<Adresat> &adresaci, int idZalogowanegoUzytkownika);
    int dodajAdresata(vector<Adresat> &adresaci, int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
    void wyswietlWszystkichAdresatow(vector<Adresat> &adresaci);
    int pobierzIdOstatniegoAdresata();
};

#endif