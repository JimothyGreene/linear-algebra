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

Matrix Matrix::identity(int n) {
    std::vector<Vector> identityVectors;
    for (int i = 0; i < n; i++) {
        std::vector<float> identityValues;
        for (int j = 0; j < n; j++) {
            if (i == j) {
                identityValues.push_back(1);
            } else {
                identityValues.push_back(0);
            }
        }
        identityVectors.push_back(Vector(identityValues, true));
    }
    return Matrix(identityVectors);
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
        rows.push_back(Vector(row, false));
    }
    this->values_ = rows;
    this->colMajor_ = false;
}

void Matrix::toColMajor(void) {
    std::vector<Vector> columns;
    for (int i = 0; i < this->columns_; i++) {
        std::vector<float> column;
        for (int j = 0; j < this->rows_; j++) {
            column.push_back(this->values_[j].getValues()[i]);
        }
        columns.push_back(Vector(column, false));
    }
    this->values_ = columns;
    this->colMajor_ = true;
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

void Matrix::rowReduce(bool display) {
    if (this->colMajor_) {this->toRowMajor();}
    for (int i = 0; i < this->rows_; i++) {
        float pivot = this->values_[i].getValues()[i];
        if (pivot != 1 && pivot != 0) {
            this->values_[i].multiplyScalar(1/pivot);
            if (display) {this->display();}
        } else if (pivot == 0) {
            for (int j = i; j < this->rows_; j++) {
                if (this->values_[j].getValues()[i]) {
                    this->values_[i] = this->values_[i].addVector(this->values_[j]);
                    if (display) {this->display();}
                    pivot = this->values_[i].getValues()[i];
                    this->values_[i].multiplyScalar(1/pivot);
                    if (display) {this->display();}
                    break;
                }
            }
            i = -1;
            if (display) {std::cout << std::endl;}
            continue;
        }
        for (int j = 0; j < this->rows_; j++) {
            if (i != j ) {
                float factor = -this->values_[j].getValues()[i];
                Vector scaledVector(this->values_[i].getValues(), false);
                scaledVector.multiplyScalar(factor);
                this->values_[j] = this->values_[j].addVector(scaledVector);
                if (display) {this->display();}
            }
        }
        if (display) {std::cout << std::endl;}
    }
    if (!this->colMajor_) {this->toColMajor();}
}

float Matrix::determinant(void) {
    assert(this->rows_ == this->columns_);
    if (this->rows_ == 2) {
        return (this->values_[0].getValues()[0] * this->values_[1].getValues()[1]) - 
                (this->values_[0].getValues()[1] * this->values_[1].getValues()[0]);
    }
    float determinant = 0;
    for (int i = 0; i < this->columns_; i++) {
        std::vector<Vector> subVectors;
        for (int j = 0; j < this->columns_; j++) {
            if (i != j) {
                std::vector<float> subValues(this->values_[j].getValues());
                subValues.erase(subValues.begin());
                Vector subVector(subValues, true);
                subVectors.push_back(subVector);
            }
        }
        if (i % 2) {
            determinant -= this->values_[i].getValues()[0] * Matrix(subVectors).determinant();
        } else {
            determinant += this->values_[i].getValues()[0] * Matrix(subVectors).determinant();
        }
    }
    return determinant;
}

Matrix Matrix::invert(void) {
    assert(this->determinant() != 0);
    Matrix identityMatrix = this->identity(this->columns_);
    std::vector<Vector> augmentedValues(this->values_);
    for (int i = 0; i < this->columns_; i++) {
        augmentedValues.push_back(identityMatrix.values_[i]);
    }
    Matrix augmentedMatrix(augmentedValues);
    augmentedMatrix.rowReduce(true);
    std::vector<Vector> invertedValues;
    for (int i = this->columns_; i < augmentedMatrix.columns_; i++) {
        invertedValues.push_back(augmentedMatrix.values_[i]);
    }
    Matrix invertedMatrix(invertedValues);
    return invertedMatrix;
}