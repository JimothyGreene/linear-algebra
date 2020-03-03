#include "matrix.h"

Matrix::Matrix(std::vector<Vector> vals, int cols) {
    int maxRows = 0;
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
    for (int i = 0; i < this->columns_; i++) {
        this->values_[i].display();
    }
}