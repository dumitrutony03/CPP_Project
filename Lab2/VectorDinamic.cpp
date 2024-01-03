//
// Created by tonyc on 4/25/2023.
//

#include <iostream>
#include "VectorDinamic.h"

VectorDinamic::VectorDinamic(int capacitate) {
    if(capacitate <= 0)
        throw std::invalid_argument("capacitatea trebuie sa fie un numar pozitiv");

    this->capacitate = capacitate;
    this->elems = new TElem [capacitate]; // aloca un spatiu de "capacitate" elemente
    this->nrElems = 0;
}

VectorDinamic::~VectorDinamic() {
    delete[] elems;
}

int VectorDinamic::size() {
    return this->nrElems;
}

TElem VectorDinamic::getAt(int i) {
    if(i < 0 || i >= nrElems)
        throw std::invalid_argument("pozitie invalida");
    return this->elems[i];
}

TElem VectorDinamic::update(int i, TElem e) {

    if ( i < 0 || i > nrElems )
        throw std::invalid_argument("pozitie invalida");
    else
    {
        TElem  element = elems[i];
        elems[i] = e;
        return element;
    }
}

void VectorDinamic::push_back(TElem e) {
    //TODO - IMPLEMENT METHOD
    if (nrElems == capacitate)
        resize();
    this->elems[nrElems] = e;
    this->nrElems ++;
}

void VectorDinamic::addAt(int i, TElem e) {
    if(i < 0 || i >= nrElems)
        throw std::invalid_argument("pozitia trebuie sa fie valida");



    elems[i] = e;
}

TElem VectorDinamic::sterge(int i) {
    if ( i < 0 || i > capacitate )
        throw std::invalid_argument("stergeti un element din intervalul 0, capacitate");
    for(int idx = i + 1; idx < capacitate; idx ++)
        elems[idx - 1] = elems[idx];
    capacitate --;
    return 0;

}


void VectorDinamic::resize() {
    capacitate *= 2;
    auto* aux = new TElem[capacitate];

    for(int i = 0; i < capacitate; i ++)
        aux[i] = elems[i];

    delete[] elems;
    elems = aux;
}

int VectorDinamic::getCapacitate() {
    return this->capacitate;
}

int VectorDinamic::getNrElems() {
    return this->nrElems;
}

TElem* VectorDinamic::getElems() {
    /*for (int i = 0; i < nrElems; i ++)
        std::cout << this->elems[i] << " ";*/

    return this->elems;
}

