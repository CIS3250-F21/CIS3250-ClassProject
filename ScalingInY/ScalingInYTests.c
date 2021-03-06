#include "ScalingInYTests.h"

#include "ScalingInY.h"

//- Helper functions

/* This function initializes the Y values for the first 5 points in the point
 * array found in the 'points' field in inputShape. Values used (in the order
 * of array index) are 0, 1, -1, 100, -100 */
void populatePoints() {
    float yValues[5] = {0, 1, -1, 100, -100};
    for (int i = 0; i < inputShape->numOfPoints; i++) {
        struct point * newPoint = getPoint(i);
        for (int j = 0; j < 4; j++) {
            newPoint->element[j] = 1;
        }
        newPoint->element[1] = yValues[i];
        setPoint(i, newPoint);
    }
}

void testExpectedValues(char *testName, float *expectedValues) {
    float actualValue;

    // Compare the Y value in each point to the expected value
    int failures = 0;
    for (int i = 0; i < inputShape->numOfPoints; i++) {
        actualValue = getPoint(i)->element[1];

        // Print message if the test fails
        if (actualValue != expectedValues[i]) {
            printf("Failed %s (i = %d):\n", testName, i);
            printf("- Expected: %12f\n", expectedValues[i]);
            printf("-   Actual: %12f\n\n", actualValue);
            failures++;
        }
    }
    // Not indicating success for now.
    // if (failures <= 0) printf("All %s tests succeeded!\n", testName);
}

//- Test functions

/* This test will confirm that the yScaling function correctly computes and sets
 * the Y value for points when given a negative Y scale value. The expected
 * results for each of the Y point values set in the populatePoints function
 * are 0, -22.0, 22.0, -2200.0, and 2200.0 respectively. */
void testNegativeScale() {
    float expectedValues[5] = {0, -22.0, 22.0, -2200.0, 2200.0};
    float yScaleValue = -22.0;

    // Setup for test
    populatePoints();
    setYScale(yScaleValue);
    yScaling();

    // Ensure the values are correct
    testExpectedValues("testNegativeScale", expectedValues);
}

/* This test will confirm that the yScaling function correctly computes and sets
 * the Y value for points when given a Y scale value of 0. The expected results
 * for all of the Y point values set in the populatePoints function are 0. */
void testZeroScale() {
    float expectedValues[5] = {0, 0, 0, 0, 0};
    float yScaleValue = 0.0;

    // Setup for test
    populatePoints();
    setYScale(yScaleValue);
    yScaling();

    // Ensure the values are correct
    testExpectedValues("testZeroScale", expectedValues);
}

/* This test will confirm that the yScaling function correctly computes and sets
 * the Y value for points when given a positive Y scale value. The expected
 * results for each of the Y point values set in the populatePoints function
 * are 0, 5, -5, 500, and -500 respectively. */
void testPositiveScale() {
    float expectedValues[5] = {0, 5, -5, 500, -500};
    float yScaleValue = 5.0;

    // Setup for test
    populatePoints();
    setYScale(yScaleValue);
    yScaling();

    // Ensure the values are correct
    testExpectedValues("testPositiveScale", expectedValues);
}

/* This test will confirm that the yScaling function correctly computes and sets
 * the Y value for points when given a fractional Y scale value. The expected
 * results for each of the Y point values set in the populatePoints function
 * are 0, 0.5, -0.5, 50, and -50 respectively. */
void testFractionScale() {
    float expectedValues[5] = {0, 0.5, -0.5, 50, -50};
    float yScaleValue = 0.5;

    // Setup for test
    populatePoints();
    setYScale(yScaleValue);
    yScaling();

    // Ensure the values are correct
    testExpectedValues("testFractionScale", expectedValues);
}

void runScalingInYTests() {   
    testNegativeScale();
    testZeroScale();
    testPositiveScale();
    testFractionScale();
}
