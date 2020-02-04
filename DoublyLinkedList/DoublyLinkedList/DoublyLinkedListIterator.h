//
// Created by Suraj M on 2/21/19.
//

#ifndef DOUBLYLINKEDLIST_LLITERATOR_H
#define DOUBLYLINKEDLIST_LLITERATOR_H
#include "DoubleLinkedNode.h"

template<typename T>
class DoublyLinkedListIterator {
    friend class DoubleLinkedNode<T>;
    friend class DoublyLinkedList<T>;


    //you must implement at least the methods below
    //you are free to add (and will likely need to add)
    //more members and methods

public:

    DoublyLinkedListIterator(DoublyLinkedList<T>& list);

    DoublyLinkedListIterator(DoublyLinkedListIterator& orig);

    DoublyLinkedListIterator(DoublyLinkedList<T>& list, DoubleLinkedNode<T>* start);



    //are the two iterators equal?
    //they are if they are over the same doubly linked list
    //and (they are referring to the same element in the list
    //or they are out of bounds)
    bool operator==(const DoublyLinkedListIterator<T>& rhs) const;

    //are the two iterators different?
    bool operator!=(const DoublyLinkedListIterator<T>& rhs) const;

    //is the iterator safe to dereference?
    operator bool() const;

    //go to the next element
    DoublyLinkedListIterator<T>& operator++(); //pre
    const DoublyLinkedListIterator<T> operator++(int);//post

    //go to the previous element
    DoublyLinkedListIterator<T>& operator--(); //pre
    const DoublyLinkedListIterator<T> operator--(int); //post

    //get a const reference to the value
    const T& operator*() const;

    //get a non const iterator
    T& operator*();


private:


    DoubleLinkedNode<T>* curNode;
    DoublyLinkedList<T> list;



};


template <typename T>
DoublyLinkedListIterator<T>::DoublyLinkedListIterator(DoublyLinkedList<T> &list): list(list),curNode(list.head){}




template <typename T>
DoublyLinkedListIterator<T>::DoublyLinkedListIterator(DoublyLinkedList<T> &list, DoubleLinkedNode<T> *start):list(list),curNode(start){}



template <typename T>
DoublyLinkedListIterator<T>::DoublyLinkedListIterator(DoublyLinkedListIterator &orig) {


}




template <typename T>
T& DoublyLinkedListIterator<T>::operator*(){

    return curNode->data;
}

template<typename T>
const T &DoublyLinkedListIterator<T>::operator*() const {

    return curNode->data;
}

template<typename T>
DoublyLinkedListIterator<T> &DoublyLinkedListIterator<T>::operator++() {


    if(curNode) {
        curNode = curNode->next;
        return *this;
    } else{
        std::cout<<("List is empty");
        return -99;
    }
}

template<typename T>
const DoublyLinkedListIterator<T> DoublyLinkedListIterator<T>::operator++(int) {

    if(curNode) {
        curNode = curNode->next;
        return *this;
    } else{
        std::cout<<("List is empty");
        return -99;
    }
}

template<typename T>
DoublyLinkedListIterator<T> &DoublyLinkedListIterator<T>::operator--() {

    if(curNode != 0 && curNode->previous != 0) {
        curNode = curNode->previous;
        return *this;

    }

    else{
        std::cout<<("List is empty");
        return -99;
    }
}

template<typename T>
const DoublyLinkedListIterator<T> DoublyLinkedListIterator<T>::operator--(int) {

    if(curNode != 0 && curNode->previous != 0) {
        curNode = curNode->previous;
        return *this;

    }

    else{
        std::cout<<("List is empty");
        return -99;
    }
}

template<typename T>
bool DoublyLinkedListIterator<T>::operator==(const DoublyLinkedListIterator<T> &rhs) const {

    if(&list != &rhs.linkedList){
        return false;
    } else{
        return curNode == rhs.curNode;
    }
}

template<typename T>
bool DoublyLinkedListIterator<T>::operator!=(const DoublyLinkedListIterator<T> &rhs) const {
    return !(*this == rhs);
}

template<typename T>
DoublyLinkedListIterator<T>::operator bool() const {
    return curNode != nullptr;
}


#endif //DOUBLYLINKEDLIST_LLITERATOR_H
