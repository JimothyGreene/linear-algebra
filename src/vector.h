/**
 * @file vector.h
 * 
 * @brief Header file for the Vector class implementation
 * 
 * @author Rishi Ponnekanti
 * 
 */ 

#ifndef VECTOR_H
#define VECTOR_H

/**
 * Vector
 * 
 * Contains a length and an array of values
 * 
 * Normal vector operations may be performed
 * on this Vector object
 */
class Vector {
    private:
        float* values_; // Array of values for the vector
        int length_;    // Length of the vector
        bool column_;  // true represents column vector; false represents row vector
    public:
        /**
         * Constructor for a Vector object
         * without initial values
         * 
         * @param length Length of the vector
         */ 
        Vector(int length);

        /**
         * Constructor for a Vector object
         * with specified initial values
         * 
         * @param vals Initial values for the vector
         * @param length Length of the vector
         * @param col Boolean representing if column or row vector
         */ 
        Vector(float vals[], int length, bool col);

        /**
         * Displays the Vector object
         * to the console
         */ 
        void display(void);

        /**
         * Adds two Vector objects
         * 
         * @param other Vector object to be added
         * @return the sum Vector object if addition is valid
         * otherwise returns other
         */ 
        Vector addVector(Vector other);

        /**
         * Adds a scalar value to the Vector object
         * 
         * @param scalar Scalar value to be added
         */
        void addScalar(float scalar);

        /**
         * Concatenates two Vector objects together
         * where the current Vector precedes the parameter
         * 
         * @param tail Vector object to be concatenated
         */
        void concatenate(Vector tail);

        float multiply(Vector multiplier);
};

#endif