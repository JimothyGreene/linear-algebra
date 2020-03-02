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

class Matrix {
    private: 
        Vector* columns_;
        int rows_;
    public:
        Matrix(Vector* cols_);
        display(void);
};

#endif