#ifndef UZYTKOWNIKMENEDZER_H
#define UZYTKOWNIKMENEDZER_H

#include <iostream>
#include <vector>
#include <Windows.h>
#include <fstream>
#include <sstream>

#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"

using namespace std;

class UzytkownikMenedzer
{
    int idZalogowanegoUzytkownika;
    vector<Uzytkownik> uzytkownicy;
    PlikZUzytkownikami plikZUzutkownikami;

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);

public:
    UzytkownikMenedzer(string nazwaPlikuZUzytkownikami) : plikZUzutkownikami(nazwaPlikuZUzytkownikami) {}
    void rejestracjaUzytkownika();
    int logowanieUzytkownika(vector<Uzytkownik> &uzytkownicy);
    int pobierzIdZalogowanegoUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void wczytajUzytkownikowZpliku();
};

#endif