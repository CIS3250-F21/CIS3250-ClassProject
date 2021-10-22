#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct vector {
    float vector[4];
};

struct shape {
    struct vector* vectors;
    int numOfVectors;
    int globalScalingValue;
    float scaling[3];
    float rotation[3];
    float translation[3];
    float shearing[3];
};

float** transformationMatrix;
struct shape* inputShape;
char* fileName;

//~~~~~~ Global Functions ~~~~~~//
void multiplyMatrix(struct vector* currVector, float** matrix);

//~~~~~~ Getters ~~~~~~//
struct vector getVector(int index);
float getGlobalScale();
float getXScale();
float getYScale();
float getZScale();
float getXRotation();
float getYRotation();
float getZRotation();
float getXTranslation();
float getYTranslation();
float getZTranslation();
float getXShear();
float getYShear();
float getZShear();

//~~~~~~ Setters ~~~~~~//
void setVector(int index, struct vector newVector);
void setGlobalScale(float newGlobalScale);
void setXScale(float newXScale);
void setYScale(float newYScale);
void setZScale(float newZScale);
void setXRotation(float newTheta);
void setYRotation(float newTheta);
void setZRotation(float newTheta);
void setXTranslation(float newXTranslation);
void setYTranslation(float newYTranslation);
void setZTranslation(float newZTranslation);
void setXShear(float newXShear);
void setYShear(float newYShear);
void setZShear(float newZShear);

#endif
