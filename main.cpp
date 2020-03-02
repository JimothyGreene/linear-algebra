#include "src/vector.h"

#include <iostream>

void vectorDisplayTest(void) {
    std::cout << "Row Vector: " << std::endl;
    float vals[10] = {12,2,3,45,5,6,7,8,9,65};
    Vector rowV(vals, 10, false);
    rowV.display();
    std::cout << "Column Vector: " << std::endl;
    Vector colV(vals, 10, true);
    colV.display(); 
}

void vectorMultiplyTest(void) {
    std::cout << "Row Vector: " << std::endl;
    float vals[10] = {12,2,3,45,5,6,7,8,9,65};
    Vector rowV(vals, 10, false);
    rowV.display();
    std::cout << "Column Vector: " << std::endl;
    Vector colV(vals, 10, true);
    colV.display();
    std::cout << "Product: " << rowV.multiply(colV) << std::endl;
}

int main(void) {
    // vectorDisplayTest();
    vectorMultiplyTest();
    return 0;
}