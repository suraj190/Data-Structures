//
// Created by Suraj M on 3/14/18.
//

#ifndef EXTRACREDIT_MYVECTOR_MYVECTOR_H
#define EXTRACREDIT_MYVECTOR_MYVECTOR_H

#include <sstream>
#include <stdexcept>
#include <memory>
#include <algorithm>
#include <vector>
#include <ostream>
#include "ConstVectorItr.h"
#include "VectorItr.h"





template<typename T>
class MyVector;

//overloaded out for MyVector. Prints {element1 element2 element3 ...}
//you may choose to make this function a friend of MyVector if you want
template<typename T>
std::ostream& operator<<(std::ostream& out, const MyVector<T>& myVector);

template<typename T>
class MyVector {

public:

    friend VectorItr<T>;



    MyVector();
    explicit MyVector(const unsigned int& numElements); //create numElements empty items
    MyVector(const unsigned int& numElements, const T& value); // create numElements items all initialized to value

    //here I am templating this particular member method over another type U
    //this will allow us to convert things like a vector<vector<string>> to a
    //MyVector<MyVector<string>> which wouldn't be possible othewise
    template <typename U>
    MyVector(const std::vector<U>& values); // create a MyVector with the same values as standard vector
    MyVector(const MyVector& orig); // create a copy of a MyVector
    virtual ~MyVector(); //clean up any dynamically allocated space for a MyVector
    MyVector& operator=(const MyVector& rhs); // make this MyVector have a COPY of all the values in rhs

    unsigned int size() const; // return the
    bool isEmpty() const; //return true if the vector has no elements in it

    T& front(); //return a reference the first element in MyVector
    const T& front() const; //return a const reference the first element in MyVector
    T& back(); //return a reference to the last element in MyVector
    const T& back() const; //return a const reference to the last element in MyVector
    T& at(const unsigned int& index); //return a reference to the element at the specified position
    const T& at(const unsigned int& index) const;  //return a const reference to the element at the specified position
    T& operator[](const unsigned int& index); //return a reference to the element at the specified position
    const T& operator[](const unsigned int& index) const; //return a const reference to the element at the specified position

    //insert a value into the vector at the specified position
    //for the iterator versions the position is wherever they are pointing at in the vector
    void insert(const unsigned int& pos, const T& value);
    void insert(const VectorItr<T>& itr, const T& value);
    void insert(const ConstVectorItr<T>& itr, const T& value);

    //remove a value from the vector at the specified position
    //for the iterator versions the position is wherever they are pointing at in the vector
    void erase(const unsigned int& pos);
    void erase(const VectorItr<T>& itr);
    void erase(const ConstVectorItr<T>& itr);

    void pushBack(const T& value); // add an element to the end of the vector
    void popBack(); // remove the last element from the vector

    void clear();// remove all the elements from the vector


    ConstVectorItr<T> begin() const;//get a constant iterator to the beginning of the vector
    ConstVectorItr<T> end() const; //get a constant iterator to the end of the vector

    VectorItr<T> begin(); //get a mutating iterator to the beginning of the vector
    VectorItr<T> end();  //get a mutating iterator to the beginning of the vector

    ConstVectorItr<T> cbegin() const;//get a constant iterator to the beginning of the vector
    ConstVectorItr<T> cend() const; //get a constant iterator to the end of the vector

    void capacityIncrement();

    int getNumContained() const;

    std::unique_ptr<T> *getMyVectorPtr() const;

private:

    int numContained;
    int capacity;
    std::unique_ptr<T>* myVectorPtr;



};




template<typename T>
std::ostream& operator<<(std::ostream& out, const MyVector<T>& myVector){

//    for(myVector<t>::iterator itr = myVector.begin(), end = myVector.end();
//        itr != end; itr++ )
//    {
//        out << (*itr) << " ";
//    }

    out<<"{";
    for( int i = 0; i<myVector.getNumContained(); i++){

        out <<*(myVector.getMyVectorPtr()[i]) << " ";
    }

    out<<"}";

    return out;
}

template<typename T>
MyVector<T>::MyVector():numContained(0),capacity(0),myVectorPtr(nullptr){


}

template<typename T>
MyVector<T>::MyVector(const unsigned int& numElements):numContained(numElements),capacity(numElements){

    myVectorPtr = new std::unique_ptr<T>[numElements];

    for(unsigned int i =0;i<numElements;i++){
        myVectorPtr[i] = std::make_unique<T>();
    }

}

template<typename T>
MyVector<T>::MyVector(const unsigned int& numElements, const T& value):numContained(numElements),capacity(numElements){

    myVectorPtr = new std::unique_ptr<T>[numElements];

    for(unsigned int i =0; i< numElements; i++){
        myVectorPtr[i] = std::make_unique<T>(value);

    }
}

template<typename T>
template<typename U>
MyVector<T>::MyVector(const std::vector<U>& values):numContained(values.size()), capacity(values.size()){

    myVectorPtr = new std::unique_ptr<T>[capacity];


    for(int i =0; i<numContained; i++){

        (myVectorPtr[i]) = std::make_unique<T>(values[i]);
    }
}

template<typename T>
MyVector<T>::MyVector(const MyVector<T>& orig){

    myVectorPtr = new std::unique_ptr<T>[orig.capacity];

    numContained = orig.numContained;
    capacity = orig.capacity;

    for( int i = 0; i<orig.numContained; i++){

        myVectorPtr[i] = std::make_unique<T>(*(orig.myVectorPtr[i]));
    }
}

template<typename T>
MyVector<T>::~MyVector(){

    delete[] myVectorPtr;
    myVectorPtr = nullptr;
}


template<typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& rhs){

   // MyVector copy(rhs);

    return *this;
}

template<typename T>
unsigned int MyVector<T>::size() const{

    return unsigned(numContained);
}

template<typename T>
bool MyVector<T>::isEmpty() const{

    return numContained==0;
}

template<typename T>
T& MyVector<T>::front(){

    return *(myVectorPtr[0]);
}

template<typename T>
const T& MyVector<T>::front() const{

    return front();
}


template<typename T>
T& MyVector<T>::back(){

    return *(myVectorPtr[numContained-1]);
}

template<typename T>
const T& MyVector<T>::back() const{

    return back();
}

template<typename T>
T& MyVector<T>::at(const unsigned int& index){

    return *(myVectorPtr[index]);
}

template<typename T>
const T& MyVector<T>::at(const unsigned int& index) const{

    return *(myVectorPtr[index]);
}

template<typename T>
T& MyVector<T>::operator[](const unsigned int& index){

    return at(index);
}

template<typename T>
const T& MyVector<T>::operator[](const unsigned int& index) const{

    return at(index);
}


template<typename T>
void MyVector<T>::insert(const unsigned int& pos, const T& value){



    if(unsigned(capacity)<pos){


         std::out_of_range oos("Out of range on insertion handled");

         throw oos;


    }

    else{

        capacityIncrement();

        for(unsigned int i = numContained; i>pos; i--){

            myVectorPtr[i] = std::move(myVectorPtr[i-1]);

        }

        (myVectorPtr[pos]) = std::make_unique<T>(value);

        numContained++;



    }


}


template<typename T>
void MyVector<T>::insert(const VectorItr<T>& itr, const T& value){

    insert(itr.pos,value);

}

template<typename T>
void MyVector<T>::insert(const ConstVectorItr<T> &itr, const T &value) {

    insert(itr.pos,value);
}



template<typename T>
void MyVector<T>::pushBack(const T& value){



    if(capacity<=numContained){

        capacityIncrement();

    }

    (myVectorPtr[capacity-1]) = std::make_unique<T>(value);

    numContained++;


}

template<typename T>
void MyVector<T>::popBack(){

    if(numContained==0){
        std::out_of_range oos("Out of range on popBack handled");

        throw oos;
    }


    myVectorPtr[numContained-1].reset();


    numContained--;

}

template<typename T>
void MyVector<T>::capacityIncrement() {

    MyVector copy(*this);
    myVectorPtr = new std::unique_ptr<T>[capacity+1];

    capacity++;

    for( int i = 0; i<copy.numContained;i++){

        (myVectorPtr[i]) = std::make_unique<T>(*(copy.myVectorPtr[i]));
    }




}






template<typename T>
ConstVectorItr<T> MyVector<T>::begin() const {
    return ConstVectorItr<T>(*this, 0);
}

template<typename T>
ConstVectorItr<T> MyVector<T>::end() const {
    return ConstVectorItr<T>(*this, numContained);
}

template<typename T>
VectorItr<T> MyVector<T>::begin() {
    return VectorItr<T>(*this, 0);
}

template<typename T>
VectorItr<T> MyVector<T>::end() {
    return VectorItr<T>(*this,numContained);
}

template<typename T>
ConstVectorItr<T> MyVector<T>::cbegin() const {
    return ConstVectorItr<T>(*this, 0);
}

template<typename T>
ConstVectorItr<T> MyVector<T>::cend() const {
    return ConstVectorItr<T>(*this, numContained);
}

template<typename T>
void MyVector<T>::clear() {

    for( int i = 0; i<numContained; i++){
        myVectorPtr[i].reset();
    }

    numContained = 0;
    


}

template<typename T>
void MyVector<T>::erase(const unsigned int &pos) {

    if(numContained==0){

        std::out_of_range oos("Out of range on erase handled");

        throw oos;

    }

    for(int i=pos; i<numContained-1; i++)
    {
        *(myVectorPtr[i])=*(myVectorPtr[i+1]);
    }

    numContained--;

}

template<typename T>
void MyVector<T>::erase(const VectorItr<T> &itr) {

}

template<typename T>
void MyVector<T>::erase(const ConstVectorItr<T> &itr) {

}

template<typename T>
int MyVector<T>::getNumContained() const {
    return numContained;
}

template<typename T>
std::unique_ptr<T> *MyVector<T>::getMyVectorPtr() const {
    return myVectorPtr;
}


#endif //EXTRACREDIT_MYVECTOR_MYVECTOR_H
