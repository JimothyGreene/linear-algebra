#include <iostream>
#include "vector.h"

/** 
 * Constructs a Vector object with values of 0
 * @param len Length of the vector
 */ 
Vector::Vector(int len) {
    this->values = new int[len];
    for (int i = 0; i < len; i++) {
        this->values[i] = 0;
    }
    this->length = len;
}

/**
 * Constructs a Vector object with set values
 * @param vals Array of values for the vector object
 * @param len Length of the vector
 */ 
Vector::Vector(int vals[], int len) {
    this->values = new int[len];
    for (int i = 0; i < len; i++) {
        values[i] = vals[i];
    }
    this->length = len;
}

void Vector::display(void) {
    std::cout << "[ ";
    for (int i = 0; i < this->length; i++) {
        std::cout << this->values[i] << " ";
    }
    std::cout << "]" << std::endl;
}

Vector Vector::add(Vector other) {
    int maxLength = this->length > other.length ? this->length : other.length;
    int minLength = this->length < other.length ? this->length : other.length;
    Vector sum(maxLength);
    int i = 0;
    for (; i < minLength; i++) {
        sum.values[i] = this->values[i] + other.values[i];
    }
    if (maxLength == this->length) {
        for (; i < maxLength; i++) {
            sum.values[i] = this->values[i];
        }
    } else {
        for (; i < maxLength; i++) {
            sum.values[i] = other.values[i];
        }
    }
    return sum;
}

void Vector::concatenate(Vector tail) {
    int newLength = this->length + tail.length;
    int* newArray = new int[newLength];
    for (int i = 0; i < this->length; i++) {
        newArray[i] = this->values[i];
    }
    for (int i = 0; i < tail.length; i++) {
        newArray[i+this->length] = tail.values[i];
    }
    this->values = newArray;
    this->length = newLength;
}