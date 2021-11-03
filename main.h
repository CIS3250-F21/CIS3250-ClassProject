#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct vector {
    float vector[4];
};

struct shape {
    struct vector** vectors;
    int numOfVectors;
    float scaling[4];
    float rotation[3];
    float translation[3];
    float shearing[3];
};

float** transformationMatrix;
struct shape inputShape;
char* fileName;

//~~~~~~ Global Functions ~~~~~~//
void multiplyMatrix(struct vector* currVector, float** matrix);

//~~~~~~ Getters ~~~~~~//
struct vector* getVector(int index);
float getYRotation();

//~~~~~~ Setters ~~~~~~//
void setVector(int index, struct vector* newVector);
void setYRotation(float angle);

//~~~~~ Helpers ~~~~~~//
void runAllTests();

#endif
