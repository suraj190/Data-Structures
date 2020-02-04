//
// Created by Suraj M on 3/14/18.
//

#ifndef EXTRACREDIT_MYVECTOR_CONSTVECTORITR_H
#define EXTRACREDIT_MYVECTOR_CONSTVECTORITR_H
#include "MyVector.h"

template<typename T>
class MyVector;


template <typename T>
class ConstVectorItr {

public:

    ConstVectorItr(const MyVector<T>& vec, int start);
    
    ConstVectorItr& operator++(); //pre
    ConstVectorItr operator++(int); //post

    ConstVectorItr& operator--(); // pre
    ConstVectorItr operator--(int); //post

    ConstVectorItr& operator+=(const unsigned int& rhs); //advance rhs elements
    ConstVectorItr operator+(const unsigned int& rhs); //create a new iterator that is rhs elements beyond the current one

    ConstVectorItr& operator-=(const unsigned int& rhs); //go back rhs elements
    ConstVectorItr operator-(const unsigned int& rhs); // create a new iterator that is rhs elements before the current one

    operator bool() const; // true if pointing to an element within the vector
    bool operator!() const; // true if pointing outside the bounds of the vector
    bool operator==(const ConstVectorItr& rhs) const; // true if referring to the same vector and (at the same position or out of bounds)
    bool operator!=(const ConstVectorItr& rhs) const; // opposite of ==

    const T& operator*() const; //get the element at the current position
    
private:


    const MyVector<T>& vec;
    int upperBound,lowerBound;
    int pos;
    bool compatible(const ConstVectorItr &other) const;

};

template<typename T>
ConstVectorItr<T>::ConstVectorItr(const MyVector<T>& vec, int start):vec(vec),upperBound(vec.size()),lowerBound(0),pos(start){

}


template<typename T>
ConstVectorItr<T>& ConstVectorItr<T>::operator++()  {
    pos++;
    return *this;
}

template<typename T>
ConstVectorItr<T> ConstVectorItr<T>::operator++(int){
    ++(*this);
    return *this;
}

template<typename T>
ConstVectorItr<T>& ConstVectorItr<T>::operator--(){
    pos--;
    return *this;
}

template<typename T>
ConstVectorItr<T> ConstVectorItr<T>::operator--(int){
    --(*this);
    return *this;
}

template<typename T>
ConstVectorItr<T>& ConstVectorItr<T>::operator+=(const unsigned int& rhs){
    pos+=rhs;
    return *this;
}

template<typename T>
ConstVectorItr<T> ConstVectorItr<T>::operator+(const unsigned int& rhs){
    ConstVectorItr copy(*this);
    copy += rhs;
    return copy;
}

template<typename T>
ConstVectorItr<T>& ConstVectorItr<T>::operator-=(const unsigned int& rhs){
    pos-=rhs;
    return *this;
}

template<typename T>
ConstVectorItr<T> ConstVectorItr<T>::operator-(const unsigned int& rhs){
    ConstVectorItr copy(*this);
    copy -= rhs;
    return copy;
}

template<typename T>
ConstVectorItr<T>::operator bool() const{
    return pos>=0 && pos < upperBound;
}

template<typename T>
bool ConstVectorItr<T>::operator!() const{
    return !static_cast<bool>(*this);
}

template<typename T>
bool ConstVectorItr<T>::operator==(const ConstVectorItr<T>& rhs) const{
    if (!compatible(rhs)) {
        return false;
    } else if (!*this && !rhs) { // two iterators that are out of bounds
        return true; // are considered to be the same
    } else {
        return pos == rhs.pos;
    }
}

template<typename T>
bool ConstVectorItr<T>::compatible(const ConstVectorItr<T>& other) const{

    return &vec == &other.vec;
}

template<typename T>
bool ConstVectorItr<T>::operator!=(const ConstVectorItr<T>& rhs) const{
    return !(*this == rhs);
}

template<typename T>
const T& ConstVectorItr<T>::operator*() const{

    if(*this){
        return *(vec.getMyVectorPtr()[pos]);
    }

    else{
        std::out_of_range oos("Out of range on const iterator dereference handled");

        throw oos;
    }

}



#endif //EXTRACREDIT_MYVECTOR_CONSTVECTORITR_H
