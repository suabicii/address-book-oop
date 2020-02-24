#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

int KsiazkaAdresowa::logowanieUzytkownika()
{
    return uzytkownikMenedzer.ustawIdZalogowanegoUzytkownika();
}

int KsiazkaAdresowa::dodajAdresata()
{
    return uzytkownikMenedzer.pobierzIdOstatniegoAdresata();
}

int KsiazkaAdresowa::wczytajAdresatowZPliku()
{
    return uzytkownikMenedzer.pobierzIdOstatniegoAdresataZPliku();
}