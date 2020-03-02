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
    imie = MetodyPomocnicze::wczytajLinie();
    adresat.ustawImie(imie);

    cout << "Podaj nazwisko: ";
    nazwisko = MetodyPomocnicze::wczytajLinie();
    adresat.ustawNazwisko(nazwisko);

    cout << "Podaj numer telefonu: ";
    nrTel = MetodyPomocnicze::wczytajLinie();
    adresat.ustawNrTel(nrTel);

    cout << "Podaj email: ";
    email = MetodyPomocnicze::wczytajLinie();
    adresat.ustawEmail(email);

    cout << "Podaj adres: ";
    cin.sync();
    adres = MetodyPomocnicze::wczytajLinie();
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