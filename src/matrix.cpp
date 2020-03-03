#include "matrix.h"

#include <assert.h>

Matrix::Matrix(void) {
    std::vector<Vector> vals;
    this->values_ = vals;
    this->columns_ = 0;
    this->rows_ = 0;
    this->colMajor_ = true;
}

Matrix::Matrix(std::vector<Vector> vals) {
    int maxRows = 0;
    int cols = vals.size();
    for (int i = 0; i < cols; i++) {
        if (vals[i].getLength() > maxRows ) {
            maxRows = vals[i].getLength();
        }
    }
    this->values_ = vals;
    this->columns_ = cols;
    this->rows_ = maxRows;
    this->colMajor_ = true;
}

void Matrix::display(void) {
    if (this->colMajor_) {
        std::cout << "[";
        for (int i = 0; i < this->rows_; i++) {
            for (int j = 0; j < this->columns_; j++) {
                if (this->values_[j].getLength() < i+1) {
                    std::cout << " 0 ";
                } else {
                    std::cout << " " << this->values_[j].getValues()[i] << " ";
                }
            }
            if (i == this->rows_-1) {
                std::cout << "]" << std::endl;
            } else {
                std::cout << std::endl << " ";
            }
        }
    } else {
        std::cout << "[";
        for (int i = 0; i < this->rows_; i++) {
            for (int j = 0; j < this->columns_; j++) {
                if (this->values_[i].getLength() < j+1) {
                    std::cout << " 0 ";
                } else {
                    std::cout << " " << this->values_[i].getValues()[j] << " ";
                }
            }
            if (i == this->rows_-1) {
                std::cout << "]" << std::endl;
            } else {
                std::cout << std::endl << " ";
            }
        }
    }
}

void Matrix::toRowMajor(void) {
    std::vector<Vector> rows;
    for (int i = 0; i < this->rows_; i++) {
        std::vector<float> row;
        for (int j = 0; j < this->columns_; j++) {
            row.push_back(this->values_[j].getValues()[i]);
        }
        Vector rowVect(row, false);
        rows.push_back(rowVect);
    }
    this->values_ = rows;
    this->colMajor_ = false;
}

Matrix Matrix::multiplyMatrix(Matrix multiplier) {
    assert(this->columns_ == multiplier.rows_);
    this->toRowMajor();
    std::vector<Vector> productValues;
    for (int i = 0; i < multiplier.columns_; i++) {
        std::vector<float> product;
        for (int j = 0; j < this->rows_; j++) {
            product.push_back(this->values_[j].multiplyVector(multiplier.values_[i]));
        }
        Vector productVector(product, true);
        productValues.push_back(productVector);
    }
    Matrix productMatrix(productValues);
    return productMatrix;
}

void Matrix::rowReduceDisplay(void) {
    this->toRowMajor();
    for (int i = 0; i < this->rows_; i++) {
        float pivot = this->values_[i].getValues()[i];
        if (pivot != 1) {
            this->values_[i].multiplyScalar(1/pivot);
            this->display();
            for (int j = 0; j < this->rows_; j++) {
                if (i != j) {
                    float factor = -this->values_[j].getValues()[i];
                    Vector scaledVector(this->values_[i].getValues(), false);
                    scaledVector.multiplyScalar(factor);
                    this->values_[j] = this->values_[j].addVector(scaledVector);
                    this->display();
                }
            }
            std::cout << std::endl;
        }
    }
}