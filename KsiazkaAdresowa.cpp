#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}
// dependency injection - wstrzykiwanie zaleznosci
void KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikMenedzer.logowanieUzytkownika();
    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany())
    {
        ksiazkaAdresowaMenedzer = new KsiazkaAdresowaMenedzer(NAZWA_PLIKU_Z_ADRESTATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    }
}

void KsiazkaAdresowa::zmienHaslo()
{
    uzytkownikMenedzer.zmianaHasla();
}

void KsiazkaAdresowa::wylogowanieUzytkownika()
{
    uzytkownikMenedzer.wylogowanieUzytkownika();
    delete ksiazkaAdresowaMenedzer;
    ksiazkaAdresowaMenedzer = NULL;
}

void KsiazkaAdresowa::dodajAdresata()
{
    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany())
    {
        ksiazkaAdresowaMenedzer->dodajAdresata();
    }
    else
    {
        cout << "Aby dodac adresata, nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }
}

void KsiazkaAdresowa::wypiszWszystkichAdresatow()
{
    ksiazkaAdresowaMenedzer->wyswietlWszystkichAdresatow();
}

void KsiazkaAdresowa::edytujAdresata()
{
    ksiazkaAdresowaMenedzer->edytujAdresata();
}

void KsiazkaAdresowa::usunAdresata()
{
    ksiazkaAdresowaMenedzer->usunAdresata();
}