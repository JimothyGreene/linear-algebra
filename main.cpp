#include "src/vector.h"
#include "src/matrix.h"

#include <stdlib.h>


Vector randomVector(int len) {
    std::vector<float> vals;
    for (int i = 0; i < len; i++) {
        vals.push_back(rand() % 10);
    }
    Vector randVector(vals, true);
    return randVector;
}

void vectorDisplayTest(void) {
    std::cout << "Row Vector: " << std::endl;
    std::vector<float> vals = {12,2,3,45,5,6,7,8,9,65};
    Vector rowV(vals, false);
    rowV.display();
    std::cout << "Column Vector: " << std::endl;
    Vector colV(vals, true);
    colV.display(); 
}

void vectorAddVectorTest(void) {
    std::cout << "Vector 1: " << std::endl;
    std::vector<float> vals = {12,2,3,45,5,6,7,8,9,65};
    Vector vect1(vals, true);
    vect1.display();
    std::cout << "Vector 2: " << std::endl;
    Vector vect2(vals, true);
    vect2.display();
    Vector sumVector = vect1.addVector(vect2);
    std::cout << "Sum Vector: " << std::endl;
    sumVector.display();
}

void vectorAddScalarTest(void) {
    std::cout << "Original Vector:" << std::endl;
    std::vector<float> vals = {12,2,3,45,5,6,7,8,9,65};
    Vector vect(vals, true);
    vect.display();
    vect.addScalar(3);
    std::cout << "Scaled Vector" << std::endl;
    vect.display();
}

void vectorMultiplyVectorTest(void) {
    std::cout << "Row Vector: " << std::endl;
    std::vector<float> vals = {12,2,3,45,5,6,7,8,9,65};
    Vector rowV(vals, false);
    rowV.display();
    std::cout << "Column Vector: " << std::endl;
    Vector colV(vals, true);
    colV.display();
    std::cout << "Product: " << rowV.multiplyVector(colV) << std::endl;
}

void vectorMultiplyScalarTest(void) {
    std::cout << "Original Vector" << std::endl;
    std::vector<float> vals = {12,2,3,45,5,6,7,8,9,65};
    Vector vect(vals, true);
    vect.display();
    vect.multiplyScalar(3);
    std::cout << "Scaled Vector" << std::endl;
    vect.display();
}

void matrixDisplayTest(void) {
    int n = 10;
    std::vector<Vector> columns;
    for (int i = 0; i < n; i++) {
        Vector randVect = randomVector(n);
        columns.push_back(randVect);
    }
    std::vector<float> shortCol = {12,2,3};
    Vector shortVect(shortCol, true);
    columns.push_back(shortVect);
    Matrix matrix(columns);
    matrix.display();
}

int main(void) {
    // vectorDisplayTest();
    // vectorMultiplyVectorTest();
    // vectorMultiplyScalarTest();
    // vectorAddVectorTest();
    // vectorAddScalarTest();
    matrixDisplayTest();
    return 0;
}