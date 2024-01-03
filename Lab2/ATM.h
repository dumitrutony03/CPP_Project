//
// Created by tonyc on 4/2/2023.
//

#ifndef LAB2_ATM_H
#define LAB2_ATM_H

#include "Collection.h"

class ATM{
private:
//    int sumaDePlata;
public:
    ATM();
    ~ATM();
//    int getSumaDePlataATM();
    Collection<int> adaugareBancnote();
    bool verificarePlata(int nrBancnote, int sumaCareTrebuiePlatita, vector<int> bancnote, vector<int> &occur_bancnote);
    void plataCuBancnote(int nrBancnote, vector<int> bancnote, vector<int> &occur_bancnote);

    void Show_Result(int length, vector<int> bancnote, vector<int> &occur_bancnote, int Stack[], int optiune);
    void Back(int k, int Sum, int sumaDePlata, vector<int> bancnote, vector<int> &occur_bancnote, int Stack[], int optiune, int &ct);
    void CalculateBacktracking(int length, vector<int> bancnote, vector<int> &occur_bancnote, int Stack[], int optiune);
    void plataCuBancnoteBacktracking(int nrBancnote, vector<int> bancnote, vector<int> &occur_bancnote);
};

#endif //LAB2_ATM_H
