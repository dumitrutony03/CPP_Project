//
// Created by tonyc on 5/9/2023.
//

#ifndef LAB2_NODE_H
#define LAB2_NODE_H

template <class T>
class List;

template<class T>
class Node {
private:
    T info;
    Node<T> *next;
    Node<T> *prev;
public:
    Node(T info, Node<T> *next, Node<T> *prev) : info(info), next(next), prev(prev) {}

    Node(T info) {
        this->info = info;
        next = nullptr;
        prev = nullptr;
    }

    friend class List<T>;
};


#endif //LAB2_NODE_H
