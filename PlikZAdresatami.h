#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <Windows.h>

#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "PlikTekstowy.h"

using namespace std;

class PlikZAdresatami : public PlikTekstowy
{
    int idOstatniegoAdresata;

    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    vector<Adresat> adresaci;

public:
    PlikZAdresatami(string nazwaPliku)
        : PlikTekstowy(nazwaPliku)
    {
        idOstatniegoAdresata = 0;
    }
    bool dopiszAdresataDoPliku(string liniaZDanymiAdresata, string nazwaPliku);
    vector<Adresat> wczytajAdresatowZpliku(int idZalogowanegoUzytkownika);
    int pobierzIdOstatniegoAdresata();
    void zaktualizujPlik(Adresat adresat, int idAdresata, string tryb);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    string pobierzNazwePlikuZAdresatami();
};

#endif