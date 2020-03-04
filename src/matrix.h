/**
 * @file matrix.h
 * 
 * @brief Header file for the Matrix class implementation
 * 
 * @author Rishi Ponnekanti
 * 
 */ 

#ifndef MATRIX_H
#define MATRIX_H

#include "vector.h"

#include <vector>

class Matrix {
    private: 
        std::vector<Vector> values_;
        int columns_;
        int rows_;
        bool colMajor_;

        Matrix identity(int n);
    public:
        Matrix(void);
        Matrix(std::vector<Vector> vals);
        void display(void);
        void toRowMajor(void);
        void toColMajor(void);
        Matrix multiplyMatrix(Matrix multiplier);
        void rowReduce(bool display);
        float determinant(void);
        Matrix invert(void);
};

#endif