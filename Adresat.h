#ifndef ADRESAT_H
#define ADRESAT_H

#include <iostream>

using namespace std;

class Adresat
{
    int id;
    string imie;
    string nazwisko;
    string nrTel;
    string email;
    string adres;

public:
    void ustawId(int noweId);
    void ustawImie(string noweImie);
    void ustawNazwisko(string noweNazwisko);
    void ustawNrTel(string nowyNrTel);
    void ustawEmail(string nowyEmail);
    void ustawAdres(string nowyAdres);

    int pobierzId();
    string pobierzImie();
    string pobierzNazwisko();
    string pobierzNrTel();
    string pobierzEmail();
    string pobierzAdres();
};

#endif