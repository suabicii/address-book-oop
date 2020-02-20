#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include "Adresat.h"

using namespace std;

class PlikZAdresatami
{
    string nazwaPlikuZAdresatami;

    bool czyPlikJestPusty(string nazwaPlikuZAdresatami);

public:
    PlikZAdresatami();
    void dopiszAdresataDoPliku(Adresat adresat);
    vector<Adresat> wczytajAdresatowZpliku();
};

#endif