#ifndef ROTATIONINXTESTS_H
#define ROTATIONINXTESTS_H

#include <stdio.h>
#include <math.h>

#include "RotationInX.h"
#include "../main.h"
/*
this file contains all testing functions 
*/

int testSetXRotationWithValidTheta();

int testSetVectorifIndexIsNeg();

int testSetVectorIndexIsNumOfVectors();

int testSetVectorIfVectorIsUninitialized();

int testSetVectorIsDefinedAndIndexIsPositiveExNumofVector();

int testGetXRotation();

int testGetVectorNegativeIndex();

int testGetVectorIndexIsNumOfVectors();

int testGetVectorClean();

int testGenerateXRotationClean();

int testGenerateXRotationUninitializedTheta();

int testGenerateXRotationWhenMatrixIsNULL();

int testGenerateXRotationMatrixWhereThetaIsOverFloatMax();

int testXRotationMatrixWhenRotationIsNULL();

int testXRotationInputMatrix3x4();

int testXRotationIncorrectNumOfVectors();

int testXRotationClean();

int runTests();

#endif
