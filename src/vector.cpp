#include "vector.h"

Vector::Vector(void) {
    std::vector<float> vals;
    this->values_ = vals;
    this->length_ = 1;
    this->column_ = true; 
}

/**
 * Constructs a Vector object with set values
 * 
 * Copies parameter vals[] to a new array
 * 
 * Initializes length_ to len
 * 
 * Initializes column_ to col
 */ 
Vector::Vector(std::vector<float> vals, bool col) {
    this->values_ = vals;
    this->length_ = vals.size();
    this->column_ = col;
}

int Vector::getLength(void) {
    return this->length_;
}

std::vector<float> Vector::getValues(void) {
    return this->values_;
}

Vector Vector::toggleColumnStatus(void) {
    std::vector<float> vals = this->values_;
    if(this->column_) {
        Vector rowVect(vals, false);
        return rowVect;
    } else {
        Vector colVect(vals, true);
        return colVect;
    }
}

float Vector::truncate(float value) {
    if (std::abs(value) < 0.001) value = 0;
    return value;
}

/**
 * Displays the vector one value after another
 * separated by spaces
 * 
 * Values are enclosed by [ ]
 */
void Vector::display(void) {
    if (this->column_) {
        std::cout << "[ " << this->values_[0] << std::endl;
        for (int i = 1; i < this->length_-1; i++) {
            std::cout << "  " << this->values_[i] << " " << std::endl;
        }
        std::cout << "  " << this->values_[this->length_-1] << " ]" << std::endl;
    } else {
        std::cout << "[ ";
        for (int i = 0; i < this->length_; i++) {
            std::cout << this->values_[i] << " ";
        }
        std::cout << "]" << std::endl;
    }
}

/**
 * Adds two vectors together
 * 
 * If two vectors are the same length
 * each pair of values is summed
 * 
 * If two vectors are different lengths
 * each pair of values is summed
 * and the remaining values are appended
 */
Vector Vector::addVector(Vector other) {
    if(this->column_ != other.column_) {return other;};
    int maxLength = this->length_ > other.length_ ? this->length_ : other.length_;
    int minLength = this->length_ < other.length_ ? this->length_ : other.length_;
    Vector sum;
    sum.length_ = maxLength;
    sum.column_ = this->column_;
    int i = 0;
    for (; i < minLength; i++) {
        float value = this->truncate(this->values_[i] + other.values_[i]);
        sum.values_.push_back(value);
    }
    if (maxLength == this->length_) {
        for (; i < maxLength; i++) {
            sum.values_.push_back(this->values_[i]);
        }
    } else {
        for (; i < maxLength; i++) {
            sum.values_.push_back(other.values_[i]);
        }
    }
    return sum;
}

/** 
 * Adds a scalar value to a Vector object
 */
void Vector::addScalar(float scalar) {
    for (int i = 0; i < this->length_; i++) {
        this->values_[i] += this->truncate(scalar);
    }
}

/**
 * Concatenates two Vector objects together
 * 
 * New values_ array is created with a length
 * of the two Vector lengths summed
 * 
 * Both values_ arrays are copied into the new
 * values_ array with the tail values_ at the end
 * 
 * Current Vector object takes the new values_ 
 * array as its own
 */
void Vector::concatenate(Vector tail) {
    
    int newLength = this->length_ + tail.length_;
    std::vector<float> newArray;
    for (int i = 0; i < this->length_; i++) {
        newArray[i] = this->values_[i];
    }
    for (int i = 0; i < tail.length_; i++) {
        newArray[i+this->length_] = tail.values_[i];
    }
    this->values_ = newArray;
    this->length_ = newLength;
}

float Vector::multiplyVector(Vector multiplier) {       // TODO: Check if order or row x column changes anything
    if(this->column_ == multiplier.column_) {return 69.42;}
    float product = 0;
    for (int i = 0; i < this->length_ && i < multiplier.length_; i++) {
        product += this->truncate(this->values_[i] * multiplier.values_[i]);
    }
    return product;
}

void Vector::multiplyScalar(float scalar) {
    for (int i = 0; i < this->length_; i++) {
        if (this->values_[i] != 0) {
            this->values_[i] *= this->truncate(scalar);
        }
    }
}