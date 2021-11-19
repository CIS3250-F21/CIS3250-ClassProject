#ifndef ROTATION_Y_TESTS_H
#define ROTATION_Y_TESTS_H

#include <math.h>
#include <stdio.h>

#include "../main.h"
#include "RotationInY.h"

void runRotationInYTests();

void rotationInYTestHandler(int (*test)(), char *testString);

void setup();

// getPoint Tests
int testGetPointReturnsNullWhenIndexIsNeagtive();

int testGetPointReturnsNullWhenIndexIsGreaterThanLength();

int testGetPointReturnsMatchingPoint();

// setPoint Tests
int testSetPointWhenIndexIsNegative();

int testSetPointWhenIndexIsGreaterThenLength();

int testSetPointIfPointIsNull();

int testSetPointIfPointAddedAtIndex();

// getYRotation Tests
int testGetYRotation();

// setYRotation Tests
int testSetYRotationWhenAngleIsValid();

// generateYRotationMatrix Tests
int testGenerateYRotationMatrixWhenTransformationMatrixIsNull();

int testGenerateYRotationMatrixWhenElementOfTransformationMatrixIsNull();

int testGenerateYRotationMatrixWhenAngleIs0();

int testGenerateYRotationMatrixWhenAngleIsNegative();

int testGenerateYRotationMatrixWhenAngleIsPositiveGreaterThanTwoPi();

// matrix multiplication Tests (SLICK)
int testMatrixMultiplicationWhenPointIsNull();  // pass null

int testMatrixMultiplicationWhenPointIsValid();  //

// include some tests for angles here

// yRotation Tests  (MOSS)

int testYRotationWhenAngleIs0();  // Clean

int testYRotationWhenAngleIsNegative();  // Dirty

int testYRotationWhenAngleIsPositiveGreaterThanTwoPi();  // Dirty

int testYRotationHandlesNullMatrix();  // Dirty

int testYRotationHandlesNullElementOfMatrix();  // Dirty

int testYRotationHandlesNullPoint();  // Dirty

int testYRotationHandlesNullPoints();  // Dirty

#endif
