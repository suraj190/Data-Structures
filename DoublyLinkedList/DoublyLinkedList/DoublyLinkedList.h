//
// Created by Suraj M on 2/21/19.
//

#ifndef DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H

#include <vector>
#include <memory>
#include "DoubleLinkedNode.h"
#include "DoublyLinkedListIterator.h"
#include "ReverseDoublyLinkedListIterator.h"

template<typename T>
class DoublyLinkedList {
    friend DoublyLinkedListIterator<T>;
public:
    using Node_Ptr = DoubleLinkedNode<T>*;

    using iterator =  DoublyLinkedListIterator<T>*;
    using const_iterator =  /*put the type of your const iterator here*/;
    using reverse_iterator = ReverseDoublyLinkedListIterator<T>*;
    using const_reverse_iterator = /*put the type of your const reverse iterator here*/;

    //create a Doubly Linked List that has the same values
    //as in the vector and in the same order
    explicit DoublyLinkedList(const std::vector<T>& values){

        for(auto itr = values.cbegin(); itr!= values.cend(); itr++){

            push_back(*itr);
        }

        head = new DoubleLinkedNode<T>(values.front());
        tail = new DoubleLinkedNode<T>(values.back());
        len = values.size();
    }


    //create an empty DoublyLinkedList
    DoublyLinkedList(){

        head = nullptr;
        tail = nullptr;
        len = 0;

    }


    virtual ~DoublyLinkedList(){
        clear();
    }

    //remove all of the elements from your list
    void clear();

    void clearImpl(DoubleLinkedNode<T>* node);

    //get a reference to the front element in the list
    const T& front() const;
    T& front();

    //get a reference to the last element in the list
    const T& back() const;
    T& back();

    //add a value to the front of the list
    void push_front(const T& value);

    //add a value to the back of the list
    void push_back(const T& value);



    //is the list empty?
    bool empty() const;

    //return the number of elements in the list
    int size() const;

    //return a constant bidirectional iterator to the front of the list
    const_iterator begin() const;
    const_iterator end() const;

    //return a nonconstant bidirectional iterator to the front of the list
    iterator begin();
    iterator end();

    const_reverse_iterator crbegin() const;
    const_reverse_iterator crend() const;

    reverse_iterator rbegin();
    reverse_iterator rend();

    //insert the value at the position in the list
    //I promise not to use the iterator again after the insertion is done
    //An example if we had the list 1 <-> 9 <-> 17
    //And the iterator was pointing to the 9 and we wanted to
    //insert -22 the result would be
    //1 <-> 22 <-> 9 <-> 17
    void insert(iterator& position, const T& value);

    //remove the element at the position pointed to
    //by the iterator.
    //I promise not to use the iterator again after the erase is done
    //An example if we had the list 1 <-> 9 <-> 17
    //And when the wanted to erase the iterator was at the 9
    //1 <-> 17
    void erase(iterator& position);

private:
    Node_Ptr head;
    Node_Ptr tail;
    int len;
};



template<typename T>
void DoublyLinkedList<T>::push_front(const T& value){

    DoubleLinkedNode<T>* tmp = new DoubleLinkedNode<T>(value);

    if(head== nullptr)
    {
        head=tail=tmp;
    }
    else
    {
        tmp->next=head;
        head->previous=tmp;
        head=tmp;
    }

    len++;




}

template<typename T>
void DoublyLinkedList<T>::push_back(const T& value) {

    DoubleLinkedNode<T>* tmp = new DoubleLinkedNode<T>(value);

    if(head== nullptr)
    {
        head=tail=tmp;
    }
    else
    {
        tmp->previous=tail;
        tail->next=tmp;
        tail=tmp;
    }

    len++;

}

template<typename T>
void DoublyLinkedList<T>::clear(){

    clearImpl(head);
    head = nullptr;
    tail = nullptr;
    len = 0;



}

template<typename T>
void DoublyLinkedList<T>::clearImpl(DoubleLinkedNode<T>* node){

    if(node == nullptr){
        return;
    }
    else{

        clearImpl(node->next);
        delete node;
    }

}


template<typename T>
const T& DoublyLinkedList<T>::front() const{

    if (head) {
        return head->data;
    }

    else {
        std::cout << "No value at front";
        return -99;
    }
}


template<typename T>
const T& DoublyLinkedList<T>::back() const{

    if (tail) {
        return tail->data;
    }

    else{
        std::cout<< "No value at back";
        return -99;
    }
}

template<typename T>
T& DoublyLinkedList<T>::front() {

    if (head) {
        return head->data;
    }
    else {

        std::cout<< "No value at front";
        return -99;
    }

}

template<typename T>
T& DoublyLinkedList<T>::back() {

    if (tail) {
        return tail->data;
    }
    else {

        std::cout<< "No value at back";
        return -99;
    }

}

template<typename T>
int DoublyLinkedList<T>::size() const {
    return len;
}

template<typename T>
bool DoublyLinkedList<T>::empty() const {
    return len == 0 ? true : false;
}

template<typename T>
void DoublyLinkedList<T>::insert(iterator &position, const T &value) {

    if(position>len)
        std::cout<<("Index is out of range");

    if(position==0)
    {
        PushFront(value);
        return;
    }

    if(position==len)
    {
        PushBack(value);
        return;
    }

    DoubleLinkedNode<T>* newNode=new DoubleLinkedNode<T>(value);
    DoubleLinkedNode<T>* tmp;

    if(position<len/2)
    {
        tmp=head;
        int cur=0;

        while(cur<position-1)
        {
            tmp=tmp->next;
            cur++;
        }

        newNode->previous=tmp;
        newNode->next=tmp->next;
        tmp->next=newNode;
        newNode->next->prev=newNode;

    }
    else
    {
        tmp=tail;
        int cur=len-1;

        while(cur>position-1)
        {
            tmp=tmp->previous;
            cur--;
        }

        newNode->previous=tmp;
        newNode->next=tmp->next;
        tmp->next=newNode;
        newNode->next->prev=newNode;

    }
    len++;

}


template <typename T>
void DoublyLinkedList<T>::erase(iterator& position) {
    if(position>=len) {
         std::cout<<("index is out of range");
    }

    T val;
    DoubleLinkedNode<T>* tmp;
    int cur=0;

    if(position==0){

        tmp=head;
        val=head->data;
        head=head->next;
        head->previous= nullptr;
        delete tmp;
    }

    else if(position==len-1){

        tmp=tail;
        val=tail->data;
        tail=tail->previous;
        tail->previous= nullptr;
        delete tmp;
    }

    else{

        if(position<len/2){

            tmp=head;
            cur=0;

            while(cur<position)
            {
                tmp=tmp->next;
                cur++;
            }

        }
        else{

            tmp=tail;
             cur=len-1;

            while(cur>position)
            {
                tmp=tmp->previous;
                cur--;
            }
        }

        tmp->prev->next=tmp->next;
        tmp->next->prev=tmp->previous;
        delete tmp;
    }

    len--;

}

template<typename T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::begin() {
    return DoublyLinkedListItr<T>(*this);
}

template <typename T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::end(){

    return DoublyLinkedListItr<T>(*this, nullptr);
}

//write to the stream each element in the list in order
//with a space in between them
template<typename T>
std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<T>& doublyLinkedList);

//read elements from the stream as long as it is good
// or until a newline (\n) is encountered
//if a newline is encontered it should be consumed
template<typename T>
std::istream& operator>>(std::istream& in, DoublyLinkedList<T>& doublyLinkedList);







#endif //DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H
