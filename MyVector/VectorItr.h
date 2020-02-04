//
// Created by Suraj M on 3/14/18.
//

#ifndef EXTRACREDIT_MYVECTOR_VECTORITR_H
#define EXTRACREDIT_MYVECTOR_VECTORITR_H
#include "MyVector.h"
#include <iostream>

template<typename T>
class MyVector;

template<typename T>
class VectorItr {

public:

    VectorItr(MyVector<T>& vec, int start);



    VectorItr& operator++(); //pre
    VectorItr operator++(int); //post

    VectorItr& operator--(); // pre
    VectorItr operator--(int); //post

    VectorItr& operator+=(const unsigned int& rhs); //advance rhs elements
    VectorItr operator+(const unsigned int& rhs); //create a new iterator that is rhs elements beyond the current one

    VectorItr& operator-=(const unsigned int& rhs); //go back rhs elements
    VectorItr operator-(const unsigned int& rhs); // create a new iterator that is rhs elements before the current one

    operator bool() const; // true if pointing to an element within the vector
    bool operator!() const; // true if pointing outside the bounds of the vector
    bool operator==(const VectorItr& rhs) const; // true if referring to the same vector and (at the same position or out of bounds)
    bool operator!=(const VectorItr& rhs) const; // opposite of ==

    T& operator*(); //get the element at the current position
    const T& operator*() const; //get the element at the current position




private:

    MyVector<T>& vec;
    int upperBound,lowerBound;
    int pos;
    bool compatible(const VectorItr &other) const;


};

template<typename T>
VectorItr<T>::VectorItr(MyVector<T>& vec, int start):vec(vec),upperBound(vec.size()),lowerBound(0),pos(start){

}


template<typename T>
VectorItr<T>& VectorItr<T>::operator++(){
    pos++;
    return *this;
}

template<typename T>
VectorItr<T> VectorItr<T>::operator++(int){
    ++(*this);
    return *this;
}

template<typename T>
VectorItr<T>& VectorItr<T>::operator--(){
    pos--;
    return *this;
}

template<typename T>
VectorItr<T> VectorItr<T>::operator--(int){
    --(*this);
    return *this;
}

template<typename T>
VectorItr<T>& VectorItr<T>::operator+=(const unsigned int& rhs){
    pos+=rhs;
    return *this;
}

template<typename T>
VectorItr<T> VectorItr<T>::operator+(const unsigned int& rhs){
    VectorItr copy(*this);
    copy += rhs;
    return copy;
}

template<typename T>
VectorItr<T>& VectorItr<T>::operator-=(const unsigned int& rhs){
    pos-=rhs;
    return *this;
}

template<typename T>
VectorItr<T> VectorItr<T>::operator-(const unsigned int& rhs){
    VectorItr copy(*this);
    copy -= rhs;
    return copy;
}

template<typename T>
VectorItr<T>::operator bool() const{
    return pos>=0 && pos < upperBound;
}

template<typename T>
bool VectorItr<T>::operator!() const{
    return !static_cast<bool>(*this);
}

template<typename T>
bool VectorItr<T>::operator==(const VectorItr<T>& rhs) const{
    if (!compatible(rhs)) {
        return false;
    } else if (!*this && !rhs) { // two iterators that are out of bounds
        return true; // are considered to be the same
    } else {
        return pos == rhs.pos;
    }
}

template<typename T>
bool VectorItr<T>::compatible(const VectorItr<T>& other) const{

    return &vec == &other.vec;
}

template<typename T>
bool VectorItr<T>::operator!=(const VectorItr<T>& rhs) const{
    return !(*this == rhs);
}

template<typename T>
T& VectorItr<T>::operator*(){

    if(*this){
        return *(vec.getMyVectorPtr()[pos]);
    }

    else{
        std::out_of_range oos("Out of range on iterator dereference handled");

        throw oos;
    }
}


template<typename T>
const T& VectorItr<T>::operator*() const{

    if(*this){
        return *(vec.getMyVectorPtr()[pos]);
    }

    else{
        std::out_of_range oos("Out of range on iterator dereference handled");

        throw oos;

    }


}



#endif //EXTRACREDIT_MYVECTOR_VECTORITR_H
