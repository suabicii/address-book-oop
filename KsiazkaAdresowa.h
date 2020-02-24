#include <iostream>

#include "UzytkownikMenedzer.h"
#include "PlikZUzytkownikami.h"
#include "KsiazkaAdresowaMenedzer.h"

using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenedzer uzytkownikMenedzer;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) : uzytkownikMenedzer(nazwaPlikuZUzytkownikami)
    {
        uzytkownikMenedzer.wczytajUzytkownikowZpliku();
    }
    void rejestracjaUzytkownika();
    int logowanieUzytkownika();
    void wypiszWszystkichUzytkownikow();
    int dodajAdresata();
    int wczytajAdresatowZPliku();
};