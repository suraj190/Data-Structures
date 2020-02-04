#include <string>
#include <iostream>
#include <vector>
#include "MyVector.h"

class NoDefault {
public:
    NoDefault(const int& value) : value(value) {}

    int value;
};

std::ostream& operator<<(std::ostream& out, const NoDefault& noDefault) {
    out << noDefault.value;
    return out;
}

int main() {
    MyVector<int> intVec(std::vector<int>{1,2,3});
    MyVector<std::string> stringVec(std::vector<std::string>{"how", "now", "brown", "cow"});
    MyVector<NoDefault> noDefaultVec(std::vector<NoDefault>{7,8,9,10,11});
    MyVector<MyVector<NoDefault>> vecvec(2, noDefaultVec);

    std::cout << "intVec = " << intVec << std::endl;
    std::cout << "stringVec = " << stringVec << std::endl;
    std::cout << "noDefaultVec = " << noDefaultVec << std::endl;
    std::cout << "vecvec = " << vecvec << std::endl;

    intVec.erase(2);
    stringVec.erase(0);
    noDefaultVec.erase(3);
    vecvec.erase(1);

    std::cout << "intVec = " << intVec << std::endl;
    std::cout << "stringVec = " << stringVec << std::endl;
    std::cout << "noDefaultVec = " << noDefaultVec << std::endl;
    std::cout << "vecvec = " << vecvec << std::endl;

    std::cout << "hello" << std::endl;
    return 0;
}