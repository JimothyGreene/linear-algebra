#include "vector.h"

#include <iostream>

/** 
 * Constructs a Vector object with initial values of 0
 * 
 * Initializes length_ to len
 */
Vector::Vector(int len) {
    this->values_ = new float[len];
    for (int i = 0; i < len; i++) {
        this->values_[i] = 0;
    }
    this->length_ = len;
}

/**
 * Constructs a Vector object with set values
 * 
 * Copies parameter vals[] to a new array
 * 
 * Initializes length_ to len
 */ 
Vector::Vector(float vals[], int len) {
    this->values_ = new float[len];
    for (int i = 0; i < len; i++) {
        this->values_[i] = vals[i];
    }
    this->length_ = len;
}

/**
 * Displays the vector one value after another
 * separated by spaces
 * 
 * Values are enclosed by [ ]
 */
void Vector::display(void) {
    std::cout << "[ ";
    for (int i = 0; i < this->length_; i++) {
        std::cout << this->values_[i] << " ";
    }
    std::cout << "]" << std::endl;
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
    int maxLength = this->length_ > other.length_ ? this->length_ : other.length_;
    int minLength = this->length_ < other.length_ ? this->length_ : other.length_;
    Vector sum(maxLength);
    int i = 0;
    for (; i < minLength; i++) {
        sum.values_[i] = this->values_[i] + other.values_[i];
    }
    if (maxLength == this->length_) {
        for (; i < maxLength; i++) {
            sum.values_[i] = this->values_[i];
        }
    } else {
        for (; i < maxLength; i++) {
            sum.values_[i] = other.values_[i];
        }
    }
    return sum;
}


/** 
 * Adds a scalar value to a Vector object
 */
void Vector::addScalar(float scalar) {
    for (int i = 0; i < this->length_; i++) {
        this->values_[i] += scalar;
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
    float* newArray = new float[newLength];
    for (int i = 0; i < this->length_; i++) {
        newArray[i] = this->values_[i];
    }
    for (int i = 0; i < tail.length_; i++) {
        newArray[i+this->length_] = tail.values_[i];
    }
    this->values_ = newArray;
    this->length_ = newLength;
}