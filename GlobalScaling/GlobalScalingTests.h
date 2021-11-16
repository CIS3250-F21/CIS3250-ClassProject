#ifndef GLOBAL_SCALING_TESTS_H
#define GLOBAL_SCALING_TESTS_H
#include "../main.h"

void runGlobalScalingTests();

void checkIfVectorPointsWereScaledCorrectly();

void checkIfVectorPointsWereScaledCorrectlyWithZeroGlobalScaleValue();

void checkIfVectorPointsWereScaledCorrectlyWithInts();

void checkIfVectorPointsWereScaledCorrectlyWhenVectorpointsWhereDoubled();

void checkIfVectorPointsWereScaledCorrectlyWhenPassedNullPointers();

void checkIfVectorPointsWereScaledCorrectlyWithNegativeNumberGlobalScaleValue();

void makeTestPoint(int index);

#endif
