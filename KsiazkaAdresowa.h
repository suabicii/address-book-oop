#include <iostream>

#include "UzytkownikMenedzer.h"
#include "PlikZUzytkownikami.h"
#include "KsiazkaAdresowaMenedzer.h"

using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenedzer uzytkownikMenedzer;
    KsiazkaAdresowaMenedzer ksiazkaAdresowaMenedzer;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) : uzytkownikMenedzer(nazwaPlikuZUzytkownikami)
    {
        uzytkownikMenedzer.wczytajUzytkownikowZpliku();
    }
    void rejestracjaUzytkownika();
    int logowanieUzytkownika();
    int wylogowanieUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void zmienHaslo();
    int dodajAdresata();
    int wczytajAdresatowZPliku();
    void wypiszWszystkichAdresatow();
};