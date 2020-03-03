#include "matrix.h"

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