#include "PlikZAdresatami.h"

bool PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat)
{
    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true)
    {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

        if (czyPlikJestPusty() == true)
        {
            plikTekstowy << liniaZDanymiAdresata;
        }
        else
        {
            plikTekstowy << endl
                         << liniaZDanymiAdresata;
        }
        idOstatniegoAdresata++;
        plikTekstowy.close();
        return true;
    }
    return false;
}

bool PlikZAdresatami::czyPlikJestPusty()
{
    if (ifstream(NAZWA_PLIKU_Z_ADRESATAMI, ios::ate).tellg())
        return false;
    else
        return true;
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
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);

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
    string idUzytkownikaZPliku = MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika);
    int idUzytkownika = atoi(idUzytkownikaZPliku.c_str());

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

void PlikZAdresatami::zaktualizujPlik(Adresat adresat)
{
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string linia, idUzytkownikaZPliku;
    string nazwaPlikuTymczasowego = NAZWA_PLIKU_Z_ADRESATAMI + "_tymczasowo";

    odczytywanyPlikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI, ios::in);
    tymczasowyPlikTekstowy.open(nazwaPlikuTymczasowego, ios::out | ios::app);

    if (odczytywanyPlikTekstowy.good())
    {
        while (!odczytywanyPlikTekstowy.eof())
        {
            getline(odczytywanyPlikTekstowy, linia);
            idUzytkownikaZPliku = linia[0];
            if (MetodyPomocnicze::konwersjaIntNaString(adresat.pobierzId()) == idUzytkownikaZPliku)
            {
                tymczasowyPlikTekstowy << adresat.pobierzId() << "|";
                tymczasowyPlikTekstowy << adresat.pobierzIdUzytkownika() << "|";
                tymczasowyPlikTekstowy << adresat.pobierzImie() << "|";
                tymczasowyPlikTekstowy << adresat.pobierzNazwisko() << "|";
                tymczasowyPlikTekstowy << adresat.pobierzNrTel() << "|";
                tymczasowyPlikTekstowy << adresat.pobierzEmail() << "|";
                tymczasowyPlikTekstowy << adresat.pobierzAdres() << "|" << endl;
            }
            else
            {
                tymczasowyPlikTekstowy << linia << endl;
            }
        }
    }
    odczytywanyPlikTekstowy.close();
    tymczasowyPlikTekstowy.close();

    remove(NAZWA_PLIKU_Z_ADRESATAMI.c_str());
    rename(nazwaPlikuTymczasowego.c_str(), NAZWA_PLIKU_Z_ADRESATAMI.c_str());
}