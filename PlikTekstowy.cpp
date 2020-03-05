#include "PlikTekstowy.h"

string PlikTekstowy::pobierzNazwePliku()
{
    return NAZWA_PLIKU;
}

bool PlikTekstowy::czyPlikJestPusty()
{
    if (ifstream(pobierzNazwePliku(), ios::ate).tellg())
        return false;
    else
        return true;
}