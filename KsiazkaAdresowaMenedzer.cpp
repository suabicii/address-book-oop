#include "KsiazkaAdresowaMenedzer.h"

void KsiazkaAdresowaMenedzer::dodajAdresata()
{
    Adresat adresat;

    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl
         << endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);

    string liniaZDanymi = plikZAdresatami.zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

    if (plikZAdresatami.dopiszAdresataDoPliku(liniaZDanymi, plikZAdresatami.pobierzNazwePlikuZAdresatami()))
    {
        cout << "Adresat zostal dodany" << endl;
        Sleep(1500);
    }
    else
    {
        cout << "Blad. Nie udalo sie dodac nowego adresata do pliku" << endl;
        Sleep(1500);
    }
}

Adresat KsiazkaAdresowaMenedzer::podajDaneNowegoAdresata()
{
    string imie, nazwisko, nrTel, email, adres;
    Adresat adresat;

    adresat.ustawId(plikZAdresatami.pobierzIdOstatniegoAdresata() + 1);
    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

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

    return adresat;
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

void KsiazkaAdresowaMenedzer::edytujAdresata()
{
    Adresat adresat;
    int idEdytowanegoAdresata = 0;

    if (adresaci.empty())
    {
        cout << "Ksiazka adresowa jest pusta" << endl;
        Sleep(1500);
        return;
    }

    system("cls");
    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl
         << endl;
    cout << "Podaj ID wybranego adresata: ";
    idEdytowanegoAdresata = MetodyPomocnicze::wczytajLiczbeCalkowita();

    char wybor;
    bool czyIstniejeAdresat = false;

    for (int i = 0; i < adresaci.size(); i++)
    {
        if (adresaci[i].pobierzId() == idEdytowanegoAdresata)
        {
            cout << "Oto dane adresata: " << endl;
            wyswietlDaneAdresata(adresaci[i]);
            czyIstniejeAdresat = true;
            wybor = wybierzOpcjeZMenuEdycja();

            switch (wybor)
            {
            case '1':
                cout << "Podaj nowe imie: ";
                adresaci[i].ustawImie(MetodyPomocnicze::wczytajLinie());
                adresaci[i].ustawImie(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresaci[i].pobierzImie()));
                break;
            case '2':
                cout << "Podaj nowe nazwisko: ";
                adresaci[i].ustawNazwisko(MetodyPomocnicze::wczytajLinie());
                adresaci[i].ustawNazwisko(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresaci[i].pobierzNazwisko()));
                break;
            case '3':
                cout << "Podaj nowy numer telefonu: ";
                adresaci[i].ustawNrTel(MetodyPomocnicze::wczytajLinie());
                break;
            case '4':
                cout << "Podaj nowy email: ";
                adresaci[i].ustawEmail(MetodyPomocnicze::wczytajLinie());
                break;
            case '5':
                cout << "Podaj nowy adres zamieszkania: ";
                adresaci[i].ustawAdres(MetodyPomocnicze::wczytajLinie());
                break;
            case '6':
                cout << endl
                     << "Powrot do menu uzytkownika" << endl
                     << endl;
                break;
            default:
                cout << endl
                     << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl
                     << endl;
                break;
            }
            plikZAdresatami.zaktualizujPlik(adresaci[i], "edycja");
            if (wybor >= '1' && wybor <= '5')
            {
                cout << "Dane adresata zostaly zaktualizowane" << endl;
                Sleep(1500);
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << endl
             << "Nie ma takiego adresata." << endl
             << endl;
    }
    system("pause");
}

char KsiazkaAdresowaMenedzer::wybierzOpcjeZMenuEdycja()
{
    char wybor;

    cout << endl
         << "   >>> MENU  EDYCJA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Ktore dane zaktualizowac: " << endl;
    cout << "1 - Imie" << endl;
    cout << "2 - Nazwisko" << endl;
    cout << "3 - Numer telefonu" << endl;
    cout << "4 - Email" << endl;
    cout << "5 - Adres" << endl;
    cout << "6 - Powrot " << endl;
    cout << endl
         << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}

void KsiazkaAdresowaMenedzer::usunAdresata()
{
    int idUsuwanegoAdresata;

    if (adresaci.empty())
    {
        cout << "Ksiazka adresowa jest pusta" << endl;
        Sleep(1500);
        return;
    }

    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl
         << endl;

    cout << "Podaj ID adresata, ktorego chcesz usunac: ";
    idUsuwanegoAdresata = MetodyPomocnicze::wczytajLiczbeCalkowita();

    char znak;
    bool czyIstniejeAdresat = false;

    for (vector<Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
    {
        if (itr->pobierzId() == idUsuwanegoAdresata)
        {
            cout << "Oto dane adresata: " << endl;
            wyswietlDaneAdresata(*itr);
            czyIstniejeAdresat = true;
            cout << endl
                 << "Potwierdz naciskajac klawisz 't': ";
            znak = MetodyPomocnicze::wczytajZnak();
            if (znak == 't')
            {
                adresaci.erase(itr);
                plikZAdresatami.zaktualizujPlik(*itr, "usuwanie");
                cout << endl
                     << endl
                     << "Szukany adresat zostal USUNIETY" << endl
                     << endl;
                Sleep(1500);
                return;
            }
            else
            {
                cout << endl
                     << endl
                     << "Wybrany adresat NIE zostal usuniety" << endl
                     << endl;
                Sleep(1500);
                return;
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << endl
             << "Nie ma takiego adresata w ksiazce adresowej" << endl
             << endl;
        system("pause");
    }
}