//
// Created by Suraj M on 2/21/19.
//

#ifndef DOUBLYLINKEDLIST_DOUBLELINKEDNODE_H
#define DOUBLYLINKEDLIST_DOUBLELINKEDNODE_H

#include <iostream>

template<typename T>
class DoublyLinkedList;

template<typename T>
class DoublyLinkedListItr;

template<typename T>
class DoubleLinkedNode {

  public:
    T* next;
    T* previous;
    T  data;

    DoubleLinkedNode(const T& data = T(), DoubleLinkedNode *n = nullptr, DoubleLinkedNode *p = nullptr): data(data), next(n), previous(p){}
    ~DoubleLinkedNode(){}

};



#endif //DOUBLYLINKEDLIST_DOUBLELINKEDNODE_H
