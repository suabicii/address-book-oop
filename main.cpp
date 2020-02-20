#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt");
    char wybor;

    while (1)
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

    return 0;
}
