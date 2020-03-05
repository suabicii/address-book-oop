#include "PlikTekstowy.h"

string PlikTekstowy::pobierzNazwePliku()
{
    return NAZWA_PLIKU;
}

bool PlikTekstowy::czyPlikJestPusty(string nazwa)
{
    fstream plikTekstowy;
    if (ifstream(nazwa, ios::ate).tellg())
        return false;
    else
        return true;
}