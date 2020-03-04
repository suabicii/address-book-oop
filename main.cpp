#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");
    char wybor;
    bool czyUzytkownikJestZalogowany = false;
    // taktyczny komentarz
    while (1)
    {
        if (!czyUzytkownikJestZalogowany)
        {
            system("cls");
            cout << "    >>> MENU  GLOWNE <<<" << endl;
            cout << "---------------------------" << endl;
            cout << "1. Rejestracja" << endl;
            cout << "2. Logowanie" << endl;
            cout << "3. Koniec programu" << endl;
            cout << "---------------------------" << endl;
            cout << "Twoj wybor: ";
            cin >> wybor;

            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.rejestracjaUzytkownika();
                break;
            case '2':
                ksiazkaAdresowa.logowanieUzytkownika();
                czyUzytkownikJestZalogowany = true;
                break;
            case '3':
                exit(0);
                break;
            default:
                cout << "Nie ma takiej opcji w menu!" << endl;
                Sleep(1500);
                break;
            }
        }
        else
        {
            system("cls");
            cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
            cout << "---------------------------" << endl;
            cout << "1. Dodaj adresata" << endl;
            cout << "2. Wyswietl adresatow" << endl;
            cout << "3. Edytuj adresata" << endl;
            cout << "4. Usun adresata" << endl;
            cout << "---------------------------" << endl;
            cout << "5. Zmien haslo" << endl;
            cout << "6. Wyloguj sie" << endl;
            cout << "---------------------------" << endl;
            cout << "Twoj wybor: ";
            cin >> wybor;

            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.dodajAdresata();
                break;
            case '2':
                ksiazkaAdresowa.wypiszWszystkichAdresatow();
                break;
            case '3':
                ksiazkaAdresowa.edytujAdresata();
                break;
            case '4':
                ksiazkaAdresowa.usunAdresata();
                break;
            case '5':
                ksiazkaAdresowa.zmienHaslo();
                break;
            case '6':
                ksiazkaAdresowa.wylogowanieUzytkownika();
                czyUzytkownikJestZalogowany = false;
                break;
            default:
                cout << "Nie ma takiej opcji w menu!" << endl;
                Sleep(1500);
                break;
            }
        }
    }

    return 0;
}
