#include "matrix.h"

Matrix::Matrix(void) {
    std::vector<Vector> vals;
    this->values_ = vals;
    this->columns_ = 0;
    this->rows_ = 0;
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
}

void Matrix::display(void) {
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
}

Matrix Matrix::multiplyMatrix(Matrix multiplier) {
    if (this->columns_ != multiplier.rows_) {return multiplier;}
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