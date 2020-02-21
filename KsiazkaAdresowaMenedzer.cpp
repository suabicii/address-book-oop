#include "KsiazkaAdresowaMenedzer.h"

KsiazkaAdresowaMenedzer::KsiazkaAdresowaMenedzer()
{
    idOstatniegoAdresata = 0;
}

int KsiazkaAdresowaMenedzer::dodajAdresata(vector<Adresat> &adresaci, int idZalogowanegoUzytkownika, int idOstatniegoAdresata)
{
    Adresat adresat;
    string imie, nazwisko, nrTel, email, adres;

    adresat.ustawId(idOstatniegoAdresata + 1);
    adresat.ustawIdUzytkownika(idZalogowanegoUzytkownika);

    cout << "Podaj imie: ";
    cin >> imie;
    adresat.ustawImie(imie);

    cout << "Podaj nazwisko: ";
    cin >> nazwisko;
    adresat.ustawNazwisko(nazwisko);

    cout << "Podaj numer telefonu: ";
    cin >> nrTel;
    adresat.ustawNrTel(nrTel);

    cout << "Podaj email: ";
    cin >> email;
    adresat.ustawEmail(email);

    cout << "Podaj adres: ";
    cin.sync();
    getline(cin, adres);
    adresat.ustawAdres(adres);

    plikZAdresatami.dopiszAdresataDoPliku(adresat);
    adresaci.push_back(adresat);

    cout << "Adresat zostal dodany" << endl;
    Sleep(1500);

    return ++idOstatniegoAdresata;
}

int KsiazkaAdresowaMenedzer::pobierzIdOstatniegoAdresata()
{
    return idOstatniegoAdresata;
}