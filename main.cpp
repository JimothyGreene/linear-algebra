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

Matrix randomMatrix(int m, int n) {
    std::vector<Vector> columns;
    for (int i = 0; i < n; i++) {
        Vector randVect = randomVector(m);
        columns.push_back(randVect);
    }
    return Matrix(columns);
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
    Matrix matrix = randomMatrix(3, 2);
    matrix.display();
}

void matrixMultiplyMatrixTest(void) {
    Matrix matrix1 = randomMatrix(5, 4);
    std::cout << "Matrix 1:" << std::endl;
    matrix1.display();

    Matrix matrix2 = randomMatrix(4, 6);
    std::cout << "Matrix 2:" << std::endl;
    matrix2.display();

    Matrix product = matrix1.multiplyMatrix(matrix2);
    std::cout << "Product:" << std::endl;
    product.display();
}

void matrixRowReduceTest(void) {
    Matrix matrix = randomMatrix(4, 4);
    std::cout << "Original Matrix:" << std::endl;
    matrix.display();
    std::cout << std::endl;
    matrix.rowReduce(false);
    std::cout << "Row Reduced Matrix:" << std::endl;
    matrix.display();
}

void homeworkRowReduction(void) {
    std::vector<Vector> values;

    std::vector<float> column1 = {2,3,3,3};
    std::vector<float> column2 = {4,-2,-3,0};
    std::vector<float> column3 = {-1,-1,-1,-1};
    std::vector<float> column4 = {-1,-2,-2,-1};
    std::vector<float> constants = {-1,2,-2,1};
    
    values.push_back(Vector(column1, true));
    values.push_back(Vector(column2, true));
    values.push_back(Vector(column3, true));
    values.push_back(Vector(column4, true));
    values.push_back(Vector(constants, true));

    Matrix matrix(values);

    std::cout << "Original Matrix:" << std::endl;
    matrix.display();
    std::cout << std::endl;
    matrix.rowReduce(true);
}

void matrixDeterminantTest(void) {
    Matrix matrix = randomMatrix(5, 5);
    std::cout << "Matrix:" << std::endl;
    matrix.display();
    std::cout << "Determinant = " << matrix.determinant() << std::endl;
}

void matrixInvertTest(void) {
    Matrix matrix = randomMatrix(3, 3);
    Matrix inverted = matrix.invert();
    std::cout << "Original Matrix:" << std::endl;
    matrix.display();
    std::cout << "Inverted Matrix:" << std::endl;
    inverted.display();
}

void homeworkMatrixInvertTest(void) {
    std::vector<Vector> values;
    std::vector<Vector> constantVector;

    std::vector<float> column1 = {1,0,3,-2};
    std::vector<float> column2 = {0,1,1,0};
    std::vector<float> column3 = {1,-1,-1,0};
    std::vector<float> column4 = {2,-2,2,-3};
    std::vector<float> constants = {1,2,1,2};

    values.push_back(Vector(column1, true));
    values.push_back(Vector(column2, true));
    values.push_back(Vector(column3, true));
    values.push_back(Vector(column4, true));

    constantVector.push_back(Vector(constants, true));
    Matrix constantMatrix(constantVector);
    Matrix matrix(values);

    std::cout << "Matrix:" << std::endl;
    matrix.display();
    std::cout << "Constants:" << std::endl;
    constantMatrix.display();
    Matrix inverted = matrix.invert();
    std::cout << "Inverted Matrix:" << std::endl;
    inverted.display();
    Matrix solution = inverted.multiplyMatrix(constantMatrix);
    std::cout << "Solution:" << std::endl;
    solution.display();
}

int main(void) {
    // vectorDisplayTest();
    // vectorMultiplyVectorTest();
    // vectorMultiplyScalarTest();
    // vectorAddVectorTest();
    // vectorAddScalarTest();
    // matrixDisplayTest();
    // matrixMultiplyMatrixTest();
    // matrixRowReduceTest();
    // homeworkRowReduction();
    // matrixDeterminantTest();
    // matrixInvertTest();
    homeworkMatrixInvertTest();
    return 0;
}