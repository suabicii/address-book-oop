#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt");
    char wybor;
    int idZalogowanegoUzytkownika;

    while (1)
    {
        if (idZalogowanegoUzytkownika == 0)
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
                idZalogowanegoUzytkownika = ksiazkaAdresowa.logowanieUzytkownika();
                cout << "idZalogowanegoUzytkownika = " << idZalogowanegoUzytkownika << endl;
                system("pause");
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
            cout << "3. Wyswietl adresatow" << endl;
            cout << "---------------------------" << endl;
            cout << "4. Zmien haslo" << endl;
            cout << "5. Wyloguj sie" << endl;
            cout << "---------------------------" << endl;
            cout << "Twoj wybor: ";
            cin >> wybor;

            switch (wybor)
            {
            case '1':
                /* code */
                break;
            case '2':
                /* code */
                break;
            case '3':
                /* code */
                break;
            case '4':
                /* code */
                break;
            case '5':
                idZalogowanegoUzytkownika = 0;
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
