#include "Adresat.h"

void Adresat::ustawId(int noweId)
{
    id = noweId;
}

void Adresat::ustawImie(string noweImie)
{
    imie = noweImie;
}

void Adresat::ustawNazwisko(string noweNazwisko)
{
    nazwisko = noweNazwisko;
}

void Adresat::ustawNrTel(string nowyNrTel)
{
    nrTel = nowyNrTel;
}

void Adresat::ustawEmail(string nowyEmail)
{
    email = nowyEmail;
}

void Adresat::ustawAdres(string nowyAdres)
{
    adres = nowyAdres;
}

int Adresat::pobierzId()
{
    return id;
}

string Adresat::pobierzImie()
{
    return imie;
}

string Adresat::pobierzNazwisko()
{
    return nazwisko;
}

string Adresat::pobierzNrTel()
{
    return nrTel;
}

string Adresat::pobierzEmail()
{
    return email;
}

string Adresat::pobierzAdres()
{
    return adres;
}