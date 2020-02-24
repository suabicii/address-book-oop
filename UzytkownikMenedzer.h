#ifndef UZYTKOWNIKMENEDZER_H
#define UZYTKOWNIKMENEDZER_H

#include <iostream>
#include <vector>
#include <Windows.h>
#include <fstream>
#include <sstream>

#include "Uzytkownik.h"
#include "Adresat.h"
#include "PlikZUzytkownikami.h"
#include "KsiazkaAdresowaMenedzer.h"

using namespace std;

class UzytkownikMenedzer
{
    int idZalogowanegoUzytkownika;
    vector<Uzytkownik> uzytkownicy;
    vector<Adresat> adresaci;
    PlikZUzytkownikami plikZUzutkownikami;
    KsiazkaAdresowaMenedzer ksiazkaAdresowaMenedzer;

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);

public:
    UzytkownikMenedzer(string nazwaPlikuZUzytkownikami) : plikZUzutkownikami(nazwaPlikuZUzytkownikami) {}
    void rejestracjaUzytkownika();
    int logowanieUzytkownika(vector<Uzytkownik> &uzytkownicy);
    int ustawIdZalogowanegoUzytkownika();
    int pobierzIdOstatniegoAdresata();
    int pobierzIdOstatniegoAdresataZPliku();
    void wypiszWszystkichUzytkownikow();
    void wczytajUzytkownikowZpliku();
};

#endif