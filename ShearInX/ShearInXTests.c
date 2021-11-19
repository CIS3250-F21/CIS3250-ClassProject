#include "ShearInXTests.h"
#define SHEAR_FLOAT_MAX 34028234600000000000000000000000000000.0
#define SHEAR_FLOAT_MIN -1175494351000000000000000000000000000.0

void runXShearTests() 
{                        // Calls the tests
		//make sure input shape is not modified by test cases.
    struct shape* oldInputShape = inputShape;  

		//creates a common, constant set of pre-defined points for tests to pull from when creating their shape structs
    struct point** testPoints = createTestPoints();  

    errorFlag = -1;
    cleanTest(testPoints);

    errorFlag = -1;
    testShapeNull();

    errorFlag = -1;
    testPointsNull();

    errorFlag = -1;
    testLargeShearValue(testPoints);

    errorFlag = -1;
    testSmallShearValue(testPoints);

    for (int i = 0; i < 10; i++) 
		{
        free(testPoints[i]);
    }

		//refresh modified values
    free(testPoints);
    testPoints = createTestPoints();  

    errorFlag = -1;
    testWrongMagnitude(testPoints);

    inputShape = oldInputShape;
    for (int i = 0; i < 10; i++) 
		{
        free(testPoints[i]);
    }
    free(testPoints);
}

struct point** createTestPoints() 
{
    struct point** testPoints = malloc(sizeof(struct point*) * 10);
    for (int i = 0; i < 10; i++) 
		{
        testPoints[i] = malloc(sizeof(struct point));
    }

    // Origin point
    testPoints[0]->element[0] = 0.0;
    testPoints[0]->element[1] = 0.0;
    testPoints[0]->element[2] = 0.0;
    testPoints[0]->element[3] = 1.0;
    // Positive intergers
    testPoints[1]->element[0] = 1.0;
    testPoints[1]->element[1] = 2.0;
    testPoints[1]->element[2] = 3.0;
    testPoints[1]->element[3] = 1.0;
    // Real numbers
    testPoints[2]->element[0] = 3.141592;
    testPoints[2]->element[1] = -0.1;
    testPoints[2]->element[2] = -2.5;
    testPoints[2]->element[3] = 1.0;
    // Large magnitudes
    testPoints[3]->element[0] = 21445754606234.325452534;
    testPoints[3]->element[1] = -8615416565.15435341455;
    testPoints[3]->element[2] = 54145215742658418675456.0;
    testPoints[3]->element[3] = 1.0;
    // Dirty 4th value, equivalent to positive interger test
    testPoints[4]->element[0] = 2.0;
    testPoints[4]->element[1] = 4.0;
    testPoints[4]->element[2] = 6.0;
    testPoints[4]->element[3] = 2.0;

    // EXPECTED OUTPUTS FOR SHEAR Y/Z = 2:
    // Origin point
    testPoints[5]->element[0] = 0.0;
    testPoints[5]->element[1] = 0.0;
    testPoints[5]->element[2] = 0.0;
    testPoints[5]->element[3] = 1.0;
    // Positive intergers
    testPoints[6]->element[0] = 1.0;
    testPoints[6]->element[1] = 4.0;
    testPoints[6]->element[2] = 5.0;
    testPoints[6]->element[3] = 1.0;
    // Real numbers
    testPoints[7]->element[0] = 3.141592;
    testPoints[7]->element[1] = 6.183184;
    testPoints[7]->element[2] = 3.783184;
    testPoints[7]->element[3] = 1.0;
    // Large magnitudes
    testPoints[8]->element[0] = 21445754606234.325452534;
    testPoints[8]->element[1] = -8615416565.15435341455;
    testPoints[8]->element[2] = 54145215742658418675456.0;
    testPoints[8]->element[3] = 1.0;
    // Dirty 4th value
    testPoints[9]->element[0] = 1.0;
    testPoints[9]->element[1] = 4.0;
    testPoints[9]->element[2] = 5.0;
    testPoints[9]->element[3] = 1.0;

    return testPoints;
}

// --------------TESTS---------------

//CLEAN TEST:
void cleanTest(struct point** testPoints) 
{
    inputShape = malloc(sizeof(struct shape));
    inputShape->points = malloc(sizeof(struct point) * 3);
    inputShape->numOfPoints = 3;
    setPoint(0, testPoints[0]);
    setPoint(1, testPoints[1]);
    setPoint(2, testPoints[2]);
    inputShape->numOfPoints = 3;
    setYShear(2.0);
    setZShear(2.0);

    xShear();

    if (!testHelperCompare(*getPoint(0), *testPoints[5]) || !testHelperCompare(*getPoint(1), *testPoints[6]) || !testHelperCompare(*getPoint(2), *testPoints[7])) 
		{
        printf("xShear() Test cleanTest failed: Incorrect output.\nPoints were:\n");
        printPoint(*getPoint(0));
        printPoint(*getPoint(1));
        printPoint(*getPoint(2));
        printf("Expected:\n");
        printPoint(*testPoints[5]);
        printPoint(*testPoints[6]);
        printPoint(*testPoints[7]);
    } 
		else if (errorFlag == 1) 
		{
        printf("xShear() Test cleanTest failed: An error/warning was produced.\n");
    }

    free(inputShape->points);
    free(inputShape);
}

//DIRTY TESTS:
void testShapeNull() 
{
    //test gives xShear a null shape pointer
    inputShape = NULL;
    xShear();
    //test passes if the null pointer is noticed and program cointinues without failiure.
    if (errorFlag != 1) 
		{
        printf("xShear() Test testShapeNull failed: An error was not flagged\n");
    }
    //if the pointer was dereferenced a segfault will occur, triggering an error message
}

void testPointsNull() 
{
    //test gives an existing shape with a NULL point list
    inputShape = malloc(sizeof(struct shape));
    inputShape->points = NULL;
    inputShape->numOfPoints = 1;
    setYShear(0.0);
    setZShear(0.0);
    xShear();
    //test passes if the null pointer is noticed and program continues without failiure, but the errorFlag is set.
    if (errorFlag != 1) 
		{
        printf("xShear() Test testPointsNull failed: An error was not flagged\n");
    }
    //if the pointer was dereferenced a segfault will occur, triggering an error message
    free(inputShape);
}

void testLargeShearValue(struct point** testPoints) 
{
    //test sets y-shear value and z-shear value to maximum float-values.
    inputShape = malloc(sizeof(struct shape));
    inputShape->points = malloc(sizeof(struct point) * 3);
    inputShape->numOfPoints = 3;
    setPoint(0, testPoints[1]);
    setPoint(1, testPoints[2]);
    setPoint(2, testPoints[3]);
    inputShape->numOfPoints = 3;

    setYShear(SHEAR_FLOAT_MAX);
    setZShear(SHEAR_FLOAT_MAX);

    xShear();

    //test passes if points are modified correctly, or untouched if overflow would have occurred.
    //if the test fails, the result is a garbage value.
    if (!testHelperCompare(*getPoint(0), *testPoints[1]) || !testHelperCompare(*getPoint(1), *testPoints[2]) || !testHelperCompare(*getPoint(2), *testPoints[3])) 
		{
        printf("xShear() Test testLargeShearValue failed: points were modified when a magnitude error should have occured instead.\n");
    } 
		else if (errorFlag != 1) 
		{
        printf("xShear() Test testLargeShearValue failed: An error was not flagged\n");
    }
    free(inputShape->points);
    free(inputShape);
}

void testSmallShearValue(struct point** testPoints) 
{
    //test sets y-shear value and z-shear value to minimum float-values.
    inputShape = malloc(sizeof(struct shape));
    inputShape->points = malloc(sizeof(struct point) * 3);
    inputShape->numOfPoints = 3;
    setPoint(0, testPoints[1]);
    setPoint(1, testPoints[2]);
    setPoint(2, testPoints[3]);
    inputShape->numOfPoints = 3;

    setYShear(SHEAR_FLOAT_MIN);
    setZShear(SHEAR_FLOAT_MIN);

    xShear();

    //test passes if points are modified correctly, or untouched if overflow would have occurred.
    //if the test fails, the result is a garbage value.
    if (!testHelperCompare(*getPoint(0), *testPoints[1]) || !testHelperCompare(*getPoint(1), *testPoints[2]) || !testHelperCompare(*getPoint(2), *testPoints[3])) 
		{
        printf("xShear() Test testSmallShearValue failed: points were modified when a magnitude error should have occured instead.\n");
    } 
		else if (errorFlag != 1) 
		{
        printf("xShear() Test testSmallShearValue failed: An error was not flagged\n");
    }
    free(inputShape->points);
    free(inputShape);
}

void testWrongMagnitude(struct point** testPoints) 
{
    //test uses a vector where the 4th coord is set to an inappropriate value
    inputShape = malloc(sizeof(struct shape));
    inputShape->points = malloc(sizeof(struct point) * 2);
    inputShape->numOfPoints = 2;
    setPoint(0, testPoints[1]);
    setPoint(1, testPoints[4]);
    inputShape->numOfPoints = 2;
    setYShear(2.0);
    setZShear(2.0);
    xShear();
    //test passes if the points are equal (i.e: have been normalized.) When not in test mode this will print an warning.
    if (!testHelperCompare(*getPoint(0), *getPoint(1))) 
		{
        printf("xShear() Test testWrongManitude failed: Equivalent points were not made equal.\nPoints were:\n");
        printPoint(*getPoint(0));
        printPoint(*getPoint(1));
    } 
		else if (errorFlag != 1) 
		{
        printf("xShear() Test testWrongMagnitude failed: Passing points that are not normalized should produce a warning message\n");
    }
    free(inputShape->points);
    free(inputShape);
}

int testHelperCompare(struct point vec1, struct point vec2) 
{
    //helper function used in other tests
    return (vec1.element[0] == vec2.element[0] && vec1.element[1] == vec2.element[1] && vec1.element[2] == vec2.element[2] && vec1.element[3] == vec2.element[3]);
}

void printPoint(struct point toPrint) 
{
    printf("[%f, %f, %f, %f]\n", toPrint.element[0], toPrint.element[1], toPrint.element[2], toPrint.element[3]);
}
