#include <iostream>

#include "UzytkownikMenedzer.h"
#include "PlikZUzytkownikami.h"
#include "KsiazkaAdresowaMenedzer.h"

using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenedzer uzytkownikMenedzer;
    KsiazkaAdresowaMenedzer *ksiazkaAdresowaMenedzer;
    const string NAZWA_PLIKU_Z_ADRESTATAMI;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami)
        : uzytkownikMenedzer(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESTATAMI(nazwaPlikuZAdresatami)
    {
        ksiazkaAdresowaMenedzer = NULL;
    }
    ~KsiazkaAdresowa()
    {
        delete ksiazkaAdresowaMenedzer;
        ksiazkaAdresowaMenedzer = NULL;
    }
    void rejestracjaUzytkownika();
    bool logowanieUzytkownika();
    void wylogowanieUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void zmienHaslo();
    void dodajAdresata();
    void wypiszWszystkichAdresatow();
    void edytujAdresata();
    void usunAdresata();
};