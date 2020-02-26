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
    int max_length = this->length > other.length ? this->length : other.length;
    int min_length = this->length < other.length ? this->length : other.length;
    Vector sum(max_length);
    int i = 0;
    for (; i < min_length; i++) {
        sum.values[i] = this->values[i] + other.values[i];
    }
    if (max_length == this->length) {
        for (; i < max_length; i++) {
            sum.values[i] = this->values[i];
        }
    } else {
        for (; i < max_length; i++) {
            sum.values[i] = other.values[i];
        }
    }
    return sum;
}