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
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;

    vector<Adresat> adresaci;
    int idOstatniegoAdresata;
    PlikZAdresatami plikZAdresatami;

    Adresat podajDaneNowegoAdresata();
    void wyswietlDaneAdresata(Adresat adresat);
    char wybierzOpcjeZMenuEdycja();
    bool czyKsiazkaAdresowaJestPusta();

public:
    KsiazkaAdresowaMenedzer(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika)
        : plikZAdresatami(nazwaPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
    {
        adresaci = plikZAdresatami.wczytajAdresatowZpliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    }
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    int pobierzIdOstatniegoAdresata();
    void edytujAdresata();
    void usunAdresata();
};

#endif