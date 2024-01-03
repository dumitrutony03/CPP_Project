//
// Created by tonyc on 4/2/2023.
//

#ifndef LAB2_TRANZACTIE_H
#define LAB2_TRANZACTIE_H

#include <vector>
#include <iostream>

using namespace std;

class Tranzactie
{
private:
    int idTranzactie;
    int suma;
    string tipBancnote;
    int nrBancnote_tipBancnota;
public:
    Tranzactie();
    Tranzactie(int idTranzactieAtribuire, int sumaAtribuire, string tipBancnota, int nrBancnote_tipBancnota);
    ~Tranzactie();
    int getId();
    int getSuma();
    string getTipBancnote();
    int getNrBancnote_TipBancnota();

    friend ostream &operator<<(ostream &os, Tranzactie &tranzactie);
};

#endif //LAB2_TRANZACTIE_H
