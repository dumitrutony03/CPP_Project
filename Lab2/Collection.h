//
// Created by tonyc on 3/21/2023.
//

#ifndef LAB2_COLLECTION_H
#define LAB2_COLLECTION_H

#include <iostream>
#include <vector>
#include "VectorDinamic.h"
#include "List.h"

using namespace std;

template<class T>
class Collection {
private:
    /*VectorDinamic elements = VectorDinamic(10);
    VectorDinamic occurences = VectorDinamic(10);*/

    List<int> elements;
    List<int> occurences;

public:
    Collection() = default;

    ~Collection() = default;

    vector<T> getElems(vector<T> &listElements);

    vector<T> getOccurences(vector<T> &occurElements);

    void add(int bancnota, int nrOccurencesDatDeUtilizator);

    int getAt(int elem);

    int getSize() {
        return elements.size();
    }

//    bool remove(int elem);
//    bool search(int elem);
/*
    int searchByPossition(int position); // search element by position

    int size();

    int nrOccurrences(int elem);

    TElem * getAllElements();
    TElem * getAllOccurences();
*/


//    void show_bancnote_occurences();

    /*friend ostream &operator<<(ostream& os, Collection& collection)
    {
        for (int i = 0; i < collection.size(); i ++)
            os << elements[i] << " " << occurences[i] << "\n";
//            os << collection.elements[i] << " " << collection.occurrences[i] << "\n";
        return os;
    }*/
};

template<class T>
int Collection<T>::getAt(int elem) {

    int sizeElements = this->elements.size();
    for (int i = 0; i < sizeElements; i++) {
//        int elementActual = this->elements[i];
//        int elementActual = elements.get_At(i);
        int elementActual = elements.get_at(i);
        if (elementActual == elem) // Am gasit elem in vectorul nostru de this->elements
            return i;
    }
    return -1;
}

template<class T>
void Collection<T>::add(int bancnota, int nrOccurencesDatDeUtilizator) {
    //    cout << "Add element:\n";

    int position_elem = this->getAt(bancnota);
//    cout << position_elem << "\n";
    if (position_elem != -1) // Exista in sirul nostru
    {
        int aparitii_elem = occurences.get_at(position_elem);

//        cout << aparitii_elem << "\n";

        aparitii_elem++;
//        occurences.addAt(position_elem, aparitii_elem);
        occurences.set_at(position_elem, aparitii_elem);
    }
        // Nu exista acest element in sirul nostru
    else {
        this->elements.push_back(bancnota);
        this->occurences.push_back(nrOccurencesDatDeUtilizator);
    }
}

template<class T>
vector<T> Collection<T>::getOccurences(vector<T> &occurElements) {
    elements.showElems(occurElements, occurences);

    return occurElements;
}

template<class T>
vector<T> Collection<T>::getElems(vector<T> &listElements) {
    elements.showElems(listElements, elements);

    return listElements;
}

#endif //LAB2_COLLECTION_H
