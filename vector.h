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
        int length_;    // Length of the vector
        float* values_; // Array of values for the vector
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
         */ 
        Vector(float vals[], int length);

        /**
         * Displays the Vector object
         * to the consol
         */ 
        void display(void);

        /**
         * Adds two Vector objects
         * 
         * @param other Vector object to be added
         * @return the sum Vector object
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
};

#endif