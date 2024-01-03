/*
//
// Created by tonyc on 3/21/2023.
//

#include "Collection.h"
#include <algorithm>
#include <iostream>

using namespace std;

*/
/*Collection::Collection() {
}

Collection::~Collection() {
}*//*


// Returneaza pozitia lui elem daca il gaseste in vector
*/
/*int Collection::getAt(TElem elem) {
    int sizeElements = this->elements.size();
    for (int i = 0; i < sizeElements; i ++) {
//        int elementActual = this->elements[i];
//        int elementActual = elements.get_At(i);
        int elementActual = elements.get_at(i);
        if (elementActual == elem) // Am gasit elem in vectorul nostru de this->elements
            return i;
    }
    return -1;
}*//*


*/
/*bool Collection::search(int elem)
{
    cout << "Search element:\n";
    if (getAt(elem) != -1) // Am gasit elementul
    {
        cout << "Am gasit elementul: " << elem << "\n";
        return true;
    }
    cout << "Nu am gasit elementul: " << elem << "\n";
    return false;
}*//*


*/
/*
int Collection::searchByPossition(int position)
{
//    if (elements.get_at(position) != 0)
    if (elements.get_at(position) != 0)
    {
//        int elemCautat = this->elements[position];
//        int elemCautat = elements.get_At(position);
        int elemCautat = elements.get_at(position);
        return elemCautat;
    }
    return -1;
}

int Collection::size()
{
    cout << "Size vector:\n";
    return this->elements.size();
}

int Collection::nrOccurrences(int elem)
{
    cout << "NrOccurences:\n";
    int positionElem = getAt(elem); // Luam pozitia elementului
    if (positionElem != -1) {
//        cout << elem << " gasit de: " << this->occurrences[positionElem] << " ori.\n";
//        cout << elem << " gasit de: " << occurences.get_at(positionElem) << " ori.\n";
//        return this->occurrences[positionElem];
//        return occurences.get_at(positionElem);
        return occurences.get_at(positionElem);
        return occurences.get_at(positionElem);
    }
    else
    {
        cout << elem << " Nu avem acest element adaugat\n";
        return 0;
    }
}

bool Collection::remove(int elem) {

    cout << "Remove element:\n";
    int positionFindElement = elements.get_at(elem);

    if (positionFindElement == -1)
    {
        cout << "Nu avem inca acest element " << elem << " adaugat\n";
        return false;
    }
    else
    {
        cout << "Element gasit pe pozitia " << positionFindElement << "\n";

//        int aparitiiElem = this->occurrences[positionFindElement];
        int aparitiiElem = occurences.get_at(positionFindElement);
        if (aparitiiElem != 0)
        {
//            vector<int>::iterator it;
//            it = this->elements.begin() + positionFindElement;
//            this->elements.erase(it);
//            elements.sterge(positionFindElement);
            elements.delete_at(positionFindElement);
        }
        else
        {
//            this->occurrences[positionFindElement] --;
//            this->occurences[positionFindElement] --;
            int aparitii = occurences.get_at(positionFindElement);
            occurences.update(positionFindElement, -- aparitiiElem);
        }
        return true;
    }

}
*//*


*/
/*void Collection::add(TElem bancnota, TElem nrOccurencesDatDeUtilizator) {

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

    *//*
*/
/*for(int i = 0; i < elements.size(); i ++)
        cout << elements.get_at(i) << " " << occurences.get_at(i) << "\n";
    cout << "Terminat\n";*//*
*/
/*
}*/
#include "Collection.h"

/*


*/
/*vector<int> Collection::getElems(vector<int> &listElements) {
    elements.showElems(listElements, elements);

    return listElements;
}*/



/*int Collection::getSize() {
//    return elements.getNrElems();
    return elements.size();
}

vector<int> Collection::getOccurences (vector<int> &occurElements) {
    elements.showElems(occurElements, occurences);

    return occurElements;
}*//*



*/
/*

TElem * Collection::getAllElements()
{
//    return elements.getElems();
    return elements.size();
}

TElem *Collection::getAllOccurences()
{
//    cout << "Get all occurences:\n";
    return occurences.getElems();
}*//*


*/
/*void Collection::show_bancnote_occurences()
{
    vector < int > bancnote;
    vector < int > occur_bancnote;

    bancnote = getAllElements();
    occur_bancnote = getAllOccurences();

    int size_bancnote = elements.size();

    for (int i = 0; i < size_bancnote; i ++)
        cout << elements.get_at(i) << " " << occurences.get_at(i) << "\n";
}*//*






*/
