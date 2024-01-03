//
// Created by tonyc on 4/25/2023.
//

#ifndef LAB2_VECTORDINAMIC_H
#define LAB2_VECTORDINAMIC_H


typedef int TElem;

class VectorDinamic{
private:
    //TODO definiti o reprezentare
    int capacitate;
    int nrElems;
    TElem* elems;

    void resize();
public:
    int getCapacitate();
    int getNrElems();
    TElem * getElems();

    /// Constructor cu parametri
    /// \param capacitate - se aloca memorie pentru un vector de capacitate elemente
    /// \raise invalid input exception, daca capacitate <= 0
    VectorDinamic (int capacitate);

    /// destructor - dealoca memoria
    ~VectorDinamic();

    ///
    /// \return numarul de elemente din vectorul dinamic
    int size();

    ///
    /// \param i, 0 <= i < numarul de elemente din vector
    /// \return elementul de pe pozitia i din vector
    /// \raise invalid input exception, daca i nu este o pozitie valida
    TElem getAt(int i);

    /// actualizeaza elementul de pe pozitia i cu valoarea e
    /// \param i, 0 <= i < numarul de elemente din vector
    /// \param e, element de tip TElem
    /// \return elementul de pe pozitia i care a fost inlocuit cu e
    /// \raise invalid input exception, daca i nu este o pozitie valida
    TElem update(int i, TElem e);

    /// adauga un element la sfarsitul vectorului
    /// \param e, element de tip TElem, elem adaugat la final
    void push_back(TElem e);


    /// adauga un element pe pozitia i
    /// \param i, 0 <= i < numarul de elemente din vector
    /// \param e, element de tip TElem
    /// \raise invalid input exception, daca i nu este o pozitie valida
    void addAt(int i, TElem e);

    /// stergem elementul de pe pozitia i
    /// \param i, 0 <= i < numarul de elemente din vector
    /// \return elementul de pe pozitia i
    TElem sterge(int i);

};

#endif //LAB2_VECTORDINAMIC_H
