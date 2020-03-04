#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <Windows.h>

#include "Adresat.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikZAdresatami
{
    const string NAZWA_PLIKU_Z_ADRESATAMI;
    int idOstatniegoAdresata;

    bool czyPlikJestPusty(string nazwaPliku);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    vector<Adresat> adresaci;

public:
    PlikZAdresatami(string nazwaPlikuZAdresatami)
        : NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami)
    {
        idOstatniegoAdresata = 0;
    }
    bool dopiszAdresataDoPliku(string liniaZDanymiAdresata, string nazwaPliku);
    vector<Adresat> wczytajAdresatowZpliku(int idZalogowanegoUzytkownika);
    int pobierzIdOstatniegoAdresata();
    void zaktualizujPlik(Adresat adresat, string tryb);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    string pobierzNazwePlikuZAdresatami();
};

#endif