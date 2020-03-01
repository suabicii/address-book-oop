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
        for (int i = 0; i < adresaci.size(); i++)
        {
            wyswietlDaneAdresata(adresaci[i]);
        }
        system("pause");
    }
}

void KsiazkaAdresowaMenedzer::wyswietlDaneAdresata(Adresat adresat)
{
    cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Id: " << adresat.pobierzId() << "|";
    cout << "Imie: " << adresat.pobierzImie() << "|";
    cout << "Nazwisko: " << adresat.pobierzNazwisko() << "|";
    cout << "Nr tel.: " << adresat.pobierzNrTel() << "|";
    cout << "E-mail: " << adresat.pobierzEmail() << "|";
    cout << "Adres: " << adresat.pobierzAdres() << "|" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;
}