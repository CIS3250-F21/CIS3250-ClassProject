#include 'Group13Tests.h'

int main(int argc, char* argv[]) {  // Calls the tests

#ifndef MAIN_H
    printf("Major Warning: xShear's functionality did not detect the inclusion of the main header. The original get/set functions written before merging have been used as a fallback. However, this behaviour may be inconsistent with the functions in main.");
#endif

    if (argc > 1 && strcmp(argv[1], "-t") == 0) {
        tstFlag = 1;
    } else {
        tstFlag = 0;
    }

    if (tstFlag) {
        struct point* testpoints = createTestpoints();  // Creates a common, constant set of pre-defined points for tests to pull from when creating their shape structs
        errorFlag = 0;
        cleanTest(testpoints);

        errorFlag = 0;
        testShapeNull();

        errorFlag = 0;
        testpointsNull();

        errorFlag = 0;
        testLargeShearValue(testpoints);

        errorFlag = 0;
        testSmallShearValue(testpoints);

        errorFlag = 0;
        testWrongMagnitude(testpoints);
    } else {
        xShear();
    }

    return 0;
}

struct point* createTestpoints() {
    struct point* testpoints = malloc(sizeof(struct point) * 10);
    // Origin point
    testpoints[0].point[0] = 0.0;
    testpoints[0].point[1] = 0.0;
    testpoints[0].point[2] = 0.0;
    testpoints[0].point[3] = 1.0;
    // Positive intergers
    testpoints[1].point[0] = 1.0;
    testpoints[1].point[1] = 2.0;
    testpoints[1].point[2] = 3.0;
    testpoints[1].point[3] = 1.0;
    // Real numbers
    testpoints[2].point[0] = 3.14159265358979323846;
    testpoints[2].point[1] = -0.1;
    testpoints[2].point[2] = -2.5;
    testpoints[2].point[3] = 1.0;
    // Large magnitudes
    testpoints[3].point[0] = 21445754606234.325452534;
    testpoints[3].point[1] = -8615416565.15435341455;
    testpoints[3].point[2] = 54145215742658418675456.0;
    testpoints[3].point[3] = 1.0;
    // Dirty 4th value
    testpoints[4].point[0] = 2.0;
    testpoints[4].point[1] = 4.0;
    testpoints[4].point[2] = 6.0;
    testpoints[4].point[3] = 2.0;

    // EXPECTED OUTPUTS FOR SHEAR Y/Z = 2:
    // Origin point
    testpoints[5].point[0] = 0.0;
    testpoints[5].point[1] = 0.0;
    testpoints[5].point[2] = 0.0;
    testpoints[5].point[3] = 1.0;
    // Positive intergers
    testpoints[6].point[0] = 1.0;
    testpoints[6].point[1] = 4.0;
    testpoints[6].point[2] = 5.0;
    testpoints[6].point[3] = 1.0;
    // Real numbers
    testpoints[7].point[0] = 3.14159265358979323846;
    testpoints[7].point[1] = 6.183186;
    testpoints[7].point[2] = 3.783185;
    testpoints[7].point[3] = 1.0;
    // Large magnitudes
    testpoints[8].point[0] = 21445754606234.325452534;
    testpoints[8].point[1] = -8615416565.15435341455;
    testpoints[8].point[2] = 54145215742658418675456.0;
    testpoints[8].point[3] = 1.0;
    // Dirty 4th value
    testpoints[9].point[0] = 1.0;
    testpoints[9].point[1] = 4.0;
    testpoints[9].point[2] = 5.0;
    testpoints[9].point[3] = 1.0;

    return testpoints;
}

// --------------TESTS---------------

//CLEAN TEST:
void cleanTest(struct point* testpoints) {
    inputShape = malloc(sizeof(struct shape));
    inputShape->points = malloc(sizeof(struct point) * 3);
    setPoint(0, testpoints[0]);
    setPoint(1, testpoints[1]);
    setPoint(2, testpoints[2]);
    inputShape->numOfpoints = 3;
    setYShear(2.0);
    setZShear(2.0);
    xShear();

    if (!testHelperCompare(getPoint(0), testpoints[5]) || !testHelperCompare(getPoint(1), testpoints[6]) || !testHelperCompare(getPoint(0), testpoints[5])) {
        printf("Test cleanTest failed: Incorrect output.\n");
    } else if (errorFlag == 1) {
        printf("Test cleanTest failed: An error/warning was produced.\n");
    }

    free(inputShape->points);
    free(inputShape);
}

//DIRTY TESTS:
void testShapeNull() {
    // Test gives xShear a null shape pointer
    inputShape = NULL;
    xShear();
    // Test passes if the null pointer is noticed and program cointinues without failiure.
    if (errorFlag != 1) {
        printf("Test testShapeNull failed: An error was not flagged\n");
    }
    // If the pointer was dereferenced a segfault will occur, triggering an error message
}

void testpointsNull() {
    // Test gives an existing shape with a NULL point list
    inputShape = malloc(sizeof(struct shape));
    inputShape->points = NULL;
    inputShape->numOfpoints = 1;
    setYShear(0.0);
    setZShear(0.0);
    xShear();
    // Test passes if the null pointer is noticed and program continues without failiure, but the errorFlag is set.
    if (errorFlag != 1) {
        printf("Test testpointsNull failed: An error was not flagged\n");
    }
    // If the pointer was dereferenced a segfault will occur, triggering an error message
    free(inputShape);
}

void testLargeShearValue(struct point* testpoints) {
    // Test sets y-shear value and z-shear value to maximum float-values.
    inputShape = malloc(sizeof(struct shape));
    inputShape->points = malloc(sizeof(struct point) * 3);
    setPoint(0, testpoints[1]);
    setPoint(1, testpoints[2]);
    setPoint(2, testpoints[3]);
    inputShape->numOfpoints = 3;

    setYShear(FLOAT_MAX);
    setZShear(FLOAT_MAX);

    xShear();

    // Test passes if points are modified correctly, or untouched if overflow would have occurred.
    // If the test fails, the result is a garbage value.
    if (!testHelperCompare(getPoint(0), testpoints[1]) || !testHelperCompare(getPoint(1), testpoints[2]) || !testHelperCompare(getPoint(2), testpoints[3])) {
        printf("Test testLargeShearValue failed: points were modified when a magnitude error should have occured instead.\n");
    } else if (errorFlag != 1) {
        printf("Test testLargeShearValue failed: An error was not flagged\n");
    }
    free(inputShape->points);
    free(inputShape);
}

void testSmallShearValue(struct point* testpoints) {
    // Test sets y-shear value and z-shear value to minimum float-values.
    inputShape = malloc(sizeof(struct shape));
    inputShape->points = malloc(sizeof(struct point) * 3);
    setPoint(0, testpoints[1]);
    setPoint(1, testpoints[2]);
    setPoint(2, testpoints[3]);
    inputShape->numOfpoints = 3;

    setYShear(FLOAT_MIN);
    setZShear(FLOAT_MIN);

    xShear();

    // Test passes if points are modified correctly, or untouched if overflow would have occurred.
    // If the test fails, the result is a garbage value.
    if (!testHelperCompare(getPoint(0), testpoints[1]) || !testHelperCompare(getPoint(1), testpoints[2]) || !testHelperCompare(getPoint(2), testpoints[3])) {
        printf("Test testSmallShearValue failed: points were modified when a magnitude error should have occured instead.\n");
    } else if (errorFlag != 1) {
        printf("Test testSmallShearValue failed: An error was not flagged\n");
    }
    free(inputShape->points);
    free(inputShape);
}

void testWrongMagnitude(struct point* testpoints) {
    // Test sets numOfpoints to an inappropriate value
    inputShape = malloc(sizeof(struct shape));
    inputShape->points = malloc(sizeof(struct point) * 2);
    setPoint(0, testpoints[1]);
    setPoint(1, testpoints[4]);
    inputShape->numOfpoints = 2;
    setYShear(2.0);
    setZShear(2.0);
    xShear();
    // Test passes if the points are equal (i.e: have been normalized.) When not in test mode this will print an warning.
    if (!testHelperCompare(getPoint(0), getPoint(1))) {
        printf("Test testWrongManitude failed: Equivalent points were not made equal.\n");
    } else if (errorFlag != 1) {
        printf("Test testWrongMagnitude failed: Passing points that are not normalized should produce a warning message\n");
    }
    free(inputShape->points);
    free(inputShape);
}

int testHelperCompare(struct point vec1, struct point vec2) {
    // Helper function used in other tests
    return (vec1.point[0] == vec2.point[0] && vec1.point[1] == vec2.point[1] && vec1.point[2] == vec2.point[2] && vec1.point[3] == vec2.point[3]);
}