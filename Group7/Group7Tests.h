#ifndef GROUP_7_TESTS
#define GROUP_7_TESTS

#include <math.h>
#include <stdio.h>

#include "Group7.h"
#include "../main.h"

int compareFloat(float x, float y, float acceptedDistance);

void runGroup7Tests();

void group7TestHandler(int (*test)(), char *testString);

void setup();

// getVector Tests
int testGetVectorReturnsNullWhenIndexIsNeagtive();

int testGetVectorReturnsNullWhenIndexIsGreaterThanLength();

int testGetVectorReturnsMatchingVector();

// setVector Tests
int testSetVectorWhenIndexIsNegative();

int testSetVectorWhenIndexIsGreaterThenLength();

int testSetVectorIfVectorIsNull();

int testSetVectorIfVectorAddedAtIndex();

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
int testMatrixMultiplicationWhenVectorIsNull();  // pass null

int testMatrixMultiplicationWhenVectorIsValid();  //

// include some tests for angles here

// yRotation Tests  (MOSS)

int testYRotationWhenAngleIs0();  // Clean

int testYRotationWhenAngleIsNegative();  // Dirty

int testYRotationWhenAngleIsPositiveGreaterThanTwoPi();  // Dirty

int testYRotationHandlesNullMatrix();  // Dirty

int testYRotationHandlesNullElementOfMatrix();  // Dirty

int testYRotationHandlesNullVector();  // Dirty

int testYRotationHandlesNullVectors();  // Dirty

#endif
