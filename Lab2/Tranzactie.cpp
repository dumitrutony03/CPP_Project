//
// Created by tonyc on 4/2/2023.
//

#include "Tranzactie.h"

Tranzactie::Tranzactie()
{
    this->idTranzactie = 0;
    this->suma = 0;
    this->tipBancnote = "";
    this->nrBancnote_tipBancnota = 0;
}

Tranzactie::Tranzactie(int idTranzactieAtribuire, int sumaAtribuire, string tipBancnota, int nrBancnote_tipBancnota)
{
    this->idTranzactie = idTranzactieAtribuire;
    this->suma = sumaAtribuire;
    this->tipBancnote = tipBancnota;
    this->nrBancnote_tipBancnota = nrBancnote_tipBancnota;
}

Tranzactie::~Tranzactie() {
    ///
}

ostream &operator<<(ostream &os, Tranzactie &tranzactie) {
    os << "id," << " " << "bancnota folosita, " << " " << "tipBancnote," << " " << "nrBancnote de tipBancnota folosite" << "\n";
    os << tranzactie.idTranzactie << " " << tranzactie.suma << " " << tranzactie.tipBancnote << " " << tranzactie.nrBancnote_tipBancnota << "\n";
    return os;
}

int Tranzactie::getId() {
    return this->idTranzactie;
}

int Tranzactie::getSuma() {
    return this->suma;
}

string Tranzactie::getTipBancnote() {
    return this->tipBancnote;
}

int Tranzactie::getNrBancnote_TipBancnota() {
    return this->nrBancnote_tipBancnota;
}
