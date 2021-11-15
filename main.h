#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct point {
    float element[4];
};

struct shape {
    struct point** points;
    int numOfPoints;
    float scaling[4];
    float rotation[3];
    float translation[3];
    float shearing[3];
};

float transformationMatrix[4][4];
struct shape* inputShape;
char* fileName;

//~~~~~~ Global Functions ~~~~~~//
void multiplyMatrix(struct point* currPoint, float matrix[4][4]);
void resetMatrix();

//~~~~~~ Getters ~~~~~~//
struct point* getPoint(int index);
float getGloalScale();
float getXScale();
float getYScale();
float getZScale();
float getXRotation();
float getYRotation();
float getZRotation();
float getXTranslation();
float getYTranslation();
float getZTranslation();
float getXSheer();
float getYShear();
float getZSheer();

//~~~~~~ Setters ~~~~~~//
void setPoint(int index, struct point* newPoint);
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

//~~~~~ Helpers ~~~~~~//
void runAllTests();

#endif
