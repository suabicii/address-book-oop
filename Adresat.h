#ifndef ADRESAT_H
#define ADRESAT_H

#include <iostream>

using namespace std;

class Adresat
{
    int id;
    int idUzytkownika;
    string imie;
    string nazwisko;
    string nrTel;
    string email;
    string adres;

public:
    Adresat(int id = 0, int idUzytkownika = 0, string imie = "", string nazwisko = "", string nrTel = "", string email = "", string adres = "")
    {
        this->id = id;
        this->idUzytkownika = idUzytkownika;
        this->imie = imie;
        this->nrTel = nrTel;
        this->email = email;
        this->adres = adres;
    }
    void ustawId(int noweId);
    void ustawIdUzytkownika(int noweIdUzytkownika);
    void ustawImie(string noweImie);
    void ustawNazwisko(string noweNazwisko);
    void ustawNrTel(string nowyNrTel);
    void ustawEmail(string nowyEmail);
    void ustawAdres(string nowyAdres);

    int pobierzId();
    int pobierzIdUzytkownika();
    string pobierzImie();
    string pobierzNazwisko();
    string pobierzNrTel();
    string pobierzEmail();
    string pobierzAdres();
};

#endif