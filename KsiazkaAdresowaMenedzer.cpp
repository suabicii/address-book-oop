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

int KsiazkaAdresowaMenedzer::wczytajAdresatowZPliku(vector<Adresat> &adresaci, int idZalogowanegoUzytkownika)
{
    return idOstatniegoAdresata = plikZAdresatami.wczytajAdresatowZpliku(adresaci, idZalogowanegoUzytkownika);
}

void KsiazkaAdresowaMenedzer::wyswietlWszystkichAdresatow(vector<Adresat> &adresaci)
{
    if (adresaci.empty())
    {
        cout << "Ksiazka adresowa jest pusta" << endl;
        Sleep(1500);
    }
    else
    {
        cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;
        for (int i = 0; i < adresaci.size(); i++)
        {
            cout << "Id: " << adresaci[i].pobierzId() << "|";
            cout << "Imie: " << adresaci[i].pobierzImie() << "|";
            cout << "Nazwisko: " << adresaci[i].pobierzNazwisko() << "|";
            cout << "Nr tel.: " << adresaci[i].pobierzNrTel() << "|";
            cout << "E-mail: " << adresaci[i].pobierzEmail() << "|";
            cout << "Adres: " << adresaci[i].pobierzAdres() << "|" << endl;
            cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;
        }
        system("pause");
    }
}