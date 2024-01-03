//
// Created by tonyc on 3/21/2023.
//
#include <iostream>
#include "Collection.h"
#include "Tranzactie.h"
#include "ATM.h"
#include "RepositoryCollection.h"
#include "TestList.h"

using namespace std;

void menu() {
    cout << "1. Afisare toate bancnotele introduse de noi.\n";
    cout << "2. Adaugati suma de plata.\n";
    cout << "3. Adaugati suma de plata - BACKTRACKING.\n";
    cout << "4. Iesire din program.\n";
}

int main() {
    TestList();

    // Adaugam bancnotele de care avem nevoie
    ATM atm;
    // Adaugam bancnotele si frecventa lor citind informatiile din fisierul text
    Collection<int> collection = atm.adaugareBancnote();

    vector<int> listElements;
    vector<int> occurElements;

    collection.getElems(listElements); /// Bancnote
    collection.getOccurences(occurElements); /// Frecventa fiecarei bancnote

    while (true) {
        menu();
        cout << "Alegeti o optiune:";

        int optiune = 0;
        cin >> optiune;

        if (optiune == 1) {
            cout << "Afisare toate bancnotele introduse de noi de la tastatura\n";

            cout << "Ce bancnote avem\n";
            for (int i = 0; i < collection.getSize(); i ++)
                cout << "Avem: " << occurElements[i] << " bancnote de " << listElements[i] << "." << "\n";
        } else if (optiune == 2) {
            atm.plataCuBancnote(collection.getSize(), listElements, occurElements);
        } else if(optiune == 3)
        {
            atm.plataCuBancnoteBacktracking(collection.getSize(), listElements, occurElements);
        }
        else {
            return 0;
        }
    }
}
