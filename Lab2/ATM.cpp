//
// Created by tonyc on 4/2/2023.
//

#include <fstream>
#include "ATM.h"
#include "Tranzactie.h"

ATM::ATM(/*int sumaDePlatit*/) {
//    this->sumaDePlata = sumaDePlatit;
}

ATM::~ATM() {

}

//int ATM::getSumaDePlataATM()
//{
////    return this->sumaDePlata;

Collection<int> ATM::adaugareBancnote() {

    Collection<int> collection;

    ifstream fin("C:\\Users\\tonyc\\Downloads\\Anul 1\\SD\\LAB\\Lab3\\Lab2\\cmake-build-debug\\Bancnote_FrecventaBancnote");

    int b, occ_b;
    while (fin >> b >> occ_b) {
        cout << b << " " << occ_b << "\n";
        collection.add(b, occ_b);
    }

    /*int bancnota1  = 500, bancnota2 = 200, bancnota3 = 100, bancnota4 = 50, bancnota5 = 10;
    int occ1, occ2, occ3, occ4, occ5;

    cout << "Cate bancnote de 500:\n";
    cin >> occ1;

    cout << "Cate bancnote de 200:\n";
    cin >> occ2;

    cout << "Cate bancnote de 100:\n";
    cin >> occ3;

    cout << "Cate bancnote de 50:\n";
    cin >> occ4;

    cout << "Cate bancnote de 10:\n";
    cin >> occ5;*/

    /*cout << "Se va apela automat adaugarea de bancnote:\n";
    int bancnota1 = 500, bancnota2 = 200, bancnota3 = 100, bancnota4 = 50, bancnota5 = 10;
    int occ1 = 1, occ2 = 1, occ3 = 1, occ4 = 1, occ5 = 1;*/

    /*collection.add(bancnota1, occ1);
    collection.add(bancnota2, occ2);
    collection.add(bancnota3, occ3);
    collection.add(bancnota4, occ4);
    collection.add(bancnota5, occ5);*/

    return collection;
}

//}

bool
ATM::verificarePlata(int nrBancnote, int sumaCareTrebuiePlatita, vector<int> bancnote, vector<int> &occur_bancnote) {
    int suma = 0;

    for (int i = 0; i < nrBancnote; i++)
        suma += bancnote[i] * occur_bancnote[i];

    return (suma >= sumaCareTrebuiePlatita);
}

void ATM::plataCuBancnote(int nrBancnote, vector<int> bancnote, vector<int> &occur_bancnote) {

    int sumaCareTrebuiePlatita;

    cout << "Introduceti suma care trebuie platita:";
    cin >> sumaCareTrebuiePlatita;

    bool putemPlati = verificarePlata(nrBancnote, sumaCareTrebuiePlatita, bancnote, occur_bancnote);

    if (putemPlati) {
        // intrebam utilizatorul daca doreste sa faca plata
        int optiune = 0;

        cout << "Alegeti daca sa platiti tastand '1' \n";
        cout << "Alegeti sa nu platiti tastand '2' \n";

        cin >> optiune;

        if (optiune == 2) {
            cout << "Ati ales sa nu platiti. \n";
            return;
        }
    } else {
        cout << "Nu aveti suficiente fonduri. \n";
        return;
    }

    vector<Tranzactie *> tranzactiiDeStocat;

    int suma = 0;
    int id = 0;
    for (int i = 0; i < nrBancnote; i++) {
        int nrBancnoteFolosite = 0;
        if (occur_bancnote[i] > 0) {
            while (suma + bancnote[i] <= sumaCareTrebuiePlatita && occur_bancnote[i] > 0) // suma + bancnota[i]
            {
                suma += bancnote[i];
                string bancnotaFolosita = to_string(bancnote[i]);
                nrBancnoteFolosite++;
                auto *tranzactie = new Tranzactie(id++, bancnote[i], bancnotaFolosita, nrBancnoteFolosite);
                tranzactiiDeStocat.emplace_back(tranzactie);
                occur_bancnote[i]--;
            }
        }
    }
}

void
ATM::Show_Result(int length, vector<int> bancnote, vector<int> &occur_bancnote, int Stack[], int optiune) {
    for (int i = 0; i <= length; i++)
        if (Stack[i] != 0)
            cout << bancnote[i] << "*" << Stack[i] << "+";
    cout << "\n";
}

void
ATM::CalculateBacktracking(int length, vector<int> bancnote, vector<int> &occur_bancnote, int Stack[], int optiune) {
    for (int i = 0; i <= length; i++)
        if (Stack[i] != 0) {
            int fr = Stack[i];
            while (fr) {
                occur_bancnote[i]--;
                fr--;
            }
        }
}

void
ATM::Back(int k, int Sum, int sumaDePlata, vector<int> bancnote, vector<int> &occur_bancnote, int Stack[], int optiune,
          int &ct) {
    for (int i = 0; bancnote[k] * i + Sum <= sumaDePlata && i <= occur_bancnote[k]; i++) {
        Stack[k] = i;
        if (bancnote[k] * i + Sum == sumaDePlata /*&& k == 7*/) /// 7 = nr de bancnote
        {
            ct ++;
            if (ct == optiune) {
                cout << "ct a ajuns la optiune\n";
                CalculateBacktracking(k, bancnote, occur_bancnote, Stack, optiune);
                return;
            }
            Show_Result(k, bancnote, occur_bancnote, Stack, optiune);
        } else if (bancnote[k] * i + Sum <= sumaDePlata/* && k < 7*/) {
            Back(k + 1, (bancnote[k] * i + Sum), sumaDePlata, bancnote, occur_bancnote, Stack, optiune, ct);
        }
    }
}

void ATM::plataCuBancnoteBacktracking(int nrBancnote, vector<int> bancnote, vector<int> &occur_bancnote) {
    int sumaCareTrebuiePlatita;

    cout << "Introduceti suma care trebuie platita:";
    cin >> sumaCareTrebuiePlatita;

    bool putemPlati = verificarePlata(nrBancnote, sumaCareTrebuiePlatita, bancnote, occur_bancnote);

    if (putemPlati) {
        // intrebam utilizatorul daca doreste sa faca plata
        int optiune = 0;

        cout << "Alegeti daca sa platiti tastand '1' \n";
        cout << "Alegeti sa nu platiti tastand '2' \n";

        cin >> optiune;

        if (optiune == 2) {
            cout << "Ati ales sa nu platiti. \n";
            return;
        }
    } else {
        cout << "Nu aveti suficiente fonduri. \n";
        return;
    }

    int Stack[10] = {};

    int optiune = 0, ct = 0;

    Back(0, 0, sumaCareTrebuiePlatita, bancnote, occur_bancnote, Stack, 0, ct);

    ct = 0;
    cout << "Alegeti una din optiuni:\n";
    cin >> optiune;
    Back(0, 0, sumaCareTrebuiePlatita, bancnote, occur_bancnote, Stack, optiune, ct);

    /*vector<Tranzactie *> tranzactiiDeStocat;

    int suma = 0;
    int id = 0;
    for (int i = 0; i < nrBancnote; i++) {
        int nrBancnoteFolosite = 0;
        if (occur_bancnote[i] > 0) {
            while (suma + bancnote[i] <= sumaCareTrebuiePlatita && occur_bancnote[i] > 0) // suma + bancnota[i]
            {
                suma += bancnote[i];
                string bancnotaFolosita = to_string(bancnote[i]);
                nrBancnoteFolosite++;
                auto *tranzactie = new Tranzactie(id++, bancnote[i], bancnotaFolosita, nrBancnoteFolosite);
                tranzactiiDeStocat.emplace_back(tranzactie);
                occur_bancnote[i]--;
            }
        }
    }*/

}

