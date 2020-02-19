#include <iostream>

#include "UzytkownikMenedzer.h"
#include "PlikZUzytkownikami.h"

using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenedzer uzytkownikMenedzer;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) : uzytkownikMenedzer(nazwaPlikuZUzytkownikami)
    {
        uzytkownikMenedzer.wczytajUzytkownikowZpliku();
    }
    string pobierzNazwePlikuZUzytkownikami();
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
};