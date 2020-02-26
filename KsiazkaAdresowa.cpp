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
    return uzytkownikMenedzer.logowanieUzytkownika();
}

void KsiazkaAdresowa::zmienHaslo()
{
    uzytkownikMenedzer.zmianaHasla();
}

int KsiazkaAdresowa::wylogowanieUzytkownika()
{
    return uzytkownikMenedzer.wylogowanieUzytkownika();
}

int KsiazkaAdresowa::dodajAdresata()
{
    return uzytkownikMenedzer.pobierzIdOstatniegoAdresata();
}

int KsiazkaAdresowa::wczytajAdresatowZPliku()
{
    return uzytkownikMenedzer.pobierzIdOstatniegoAdresataZPliku();
}

void KsiazkaAdresowa::wypiszWszystkichAdresatow()
{
    uzytkownikMenedzer.wypiszWszystkichAdresatow();
}