#include "PlikZAdresatami.h"

bool PlikZAdresatami::dopiszAdresataDoPliku(string liniaZDanymiAdresata, string nazwaPliku)
{
    fstream plikTekstowy;
    plikTekstowy.open(nazwaPliku.c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true)
    {
        if (czyPlikJestPusty(nazwaPliku) == true)
        {
            plikTekstowy << liniaZDanymiAdresata;
        }
        else
        {
            plikTekstowy << endl
                         << liniaZDanymiAdresata;
        }

        if (nazwaPliku == pobierzNazwePliku())
        {
            idOstatniegoAdresata++;
        }
        plikTekstowy.close();
        return true;
    }
    return false;
}

string PlikZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat)
{
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata += MetodyPomocnicze::konwersjaIntNaString(adresat.pobierzId()) + '|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwersjaIntNaString(adresat.pobierzIdUzytkownika()) + '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNrTel() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

    return liniaZDanymiAdresata;
}

vector<Adresat> PlikZAdresatami::wczytajAdresatowZpliku(int idZalogowanegoUzytkownika)
{
    Adresat adresat;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            if (idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
            {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
    }
    else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    plikTekstowy.close();

    if (daneOstaniegoAdresataWPliku != "")
    {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
    }
    return adresaci;
}

int PlikZAdresatami::pobierzIdOstatniegoAdresata()
{
    return idOstatniegoAdresata;
}

int PlikZAdresatami::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    string idAdresataZPliku = MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika);
    int idUzytkownika = atoi(idAdresataZPliku.c_str());

    return idUzytkownika;
}

Adresat PlikZAdresatami::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami)
{
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch (numerPojedynczejDanejAdresata)
            {
            case 1:
                adresat.ustawId(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                adresat.ustawIdUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                adresat.ustawImie(pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.ustawNazwisko(pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.ustawNrTel(pojedynczaDanaAdresata);
                break;
            case 6:
                adresat.ustawEmail(pojedynczaDanaAdresata);
                break;
            case 7:
                adresat.ustawAdres(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}

int PlikZAdresatami::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdAdresata = 0;
    string idAdresataZPliku = MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata);
    int idAdresata = atoi(idAdresataZPliku.c_str());
    return idAdresata;
}

void PlikZAdresatami::zaktualizujPlik(Adresat adresat, int idAdresata, string tryb)
{
    fstream odczytywanyPlikTekstowy;
    string liniaWOdczytywanymPliku, liniaZDanymiAdresata, idAdresataZPliku;
    string nazwaPlikuTymczasowego = pobierzNazwePliku().substr(0, pobierzNazwePliku().length() - 5) + "_tymczasowo.txt";

    odczytywanyPlikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);

    liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

    if (odczytywanyPlikTekstowy.good())
    {
        while (!odczytywanyPlikTekstowy.eof())
        {
            getline(odczytywanyPlikTekstowy, liniaWOdczytywanymPliku);
            idAdresataZPliku = liniaWOdczytywanymPliku[0];

            if (idAdresata == atoi(idAdresataZPliku.c_str()))
            {
                if (tryb == "edycja")
                {
                    dopiszAdresataDoPliku(liniaZDanymiAdresata, nazwaPlikuTymczasowego);
                }
                else if (tryb == "usuwanie")
                {
                    // taktyczny komentarz
                }
                else
                {
                    cout << "Programista nie ustalil trybu, wiec nie wiem co robic. SMUTECZEG :(" << endl;
                    Sleep(1500);
                }
            }
            else
                dopiszAdresataDoPliku(liniaWOdczytywanymPliku, nazwaPlikuTymczasowego);
        }
    }
    odczytywanyPlikTekstowy.close();

    remove(pobierzNazwePliku().c_str());
    rename(nazwaPlikuTymczasowego.c_str(), pobierzNazwePliku().c_str());
}

string PlikZAdresatami::pobierzNazwePlikuZAdresatami()
{
    return pobierzNazwePliku();
}