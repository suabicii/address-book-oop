#include "KsiazkaAdresowaMenedzer.h"

void KsiazkaAdresowaMenedzer::dodajAdresata()
{
    Adresat adresat;
    string imie, nazwisko, nrTel, email, adres;

    adresat.ustawId(plikZAdresatami.pobierzIdOstatniegoAdresata() + 1);
    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    // zapisz wprowadzanie danych do odzielnej funkcji
    // if (plikZAdresatami.dopiszAdresataDoPliku(adresat))
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
}

int KsiazkaAdresowaMenedzer::pobierzIdOstatniegoAdresata()
{
    return idOstatniegoAdresata;
}

void KsiazkaAdresowaMenedzer::wyswietlWszystkichAdresatow()
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