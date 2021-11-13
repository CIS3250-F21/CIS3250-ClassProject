#include "ShearInZTests.h"

void ShearInZTests() {
    test1(); // Clean
    struct point *point = NULL;
    test2(point); // Dirty
    test3(); // Dirty
    test4(); // Dirty
    test5(); // Dirty
}

/**
 *  Valid Data Test
 *  Type: Clean
 *  - This function tests valid data for the zShear transformation
 *  xShear: 4
 *  yShear: 2
 *  Test point: {1,4,6,1}
 *  Expected point: {25,16,6,1}
 */
void test1() {
    inputShape->numOfPoints = 1;
    float xShear = 4;
    float yShear = 2;
    struct point *pointTest = {1,4,6,1};
    struct point pointExpected = {25,16,6,1};
    /* Equation version of Z shear multiplication matrix
    X1 = X + (xShear * Z)
    Y1 = Y + (yShear * Z)
    Z = Z (remains unchanged)
    1 = 1 (remains unchanged)
    */

    setPoint(0, pointTest);
    setXShear(xShear);
    setYShear(yShear);
    zShear();
    
    if(getPoint(0)->element[0] != pointExpected.element[0] || getPoint(1)->element[1] != pointExpected.element[1]) {
        fprintf(stderr, "Test1 Failed: Expected point does not match test point\n");
    } else {
        printf("Test1 Passed\n");
    }
    free(inputShape);
}

/**
 *  Null point test
 *  Type: Dirty 
 *  - This function tests whether a point is Null or not
 *  returns true if null, false otherwise
 */
void test2(struct point *testPoint) {
    return testPoint == NULL;
}

/**
 *  Minimum float edge case
 *  Type: Dirty
 *  - This function tries to perform the zShear transformation with the shear values set to the minimum float value
 *  xShear: -FLT_MIN
 *  yShear: -FLT_MIN
 *  Test point: {1,4,6,1}
 *  Expected point: {pointTest[0] + (xShear * pointTest[2]), pointTest[1] + (xShear * pointTest[2]),6,1}
 */
void test3() {
    inputShape->numOfPoints = 1;
    float xShear = -FLT_MIN;
    float yShear = -FLT_MIN;
    struct point *pointTest = {1,4,6,1};
    struct point pointExpected = {pointTest->element[0] + (xShear * pointTest->element[2]), pointTest->element[1] + (xShear * pointTest->element[2]),6,1};

    setPoint(0, pointTest);
    setXShear(xShear);
    setYShear(yShear);
    zShear();
    
    if(getPoint(0)->element[0] != pointExpected.element[0] || getPoint(1)->element[1] != pointExpected.element[1]) {
        fprintf(stderr, "Test3 Failed: Expected point does not match test point\n");
    } else {
        printf("Test3 Passed\n");
    }
}

/**
 *  Maxixmum float edge case
 *  Type: Dirty
 *  - This function tries to perform the zShear transformation with the shear values set to the maximum float value
 *  xShear: FLT_MAX
 *  yShear: FLT_MAX
 *  Test point: {1,4,6,1}
 *  Expected point: {pointTest[0] + (xShear * pointTest[2]), pointTest[1] + (xShear * pointTest[2]),6,1}
 */
void test4() {
    inputShape->numOfPoints = 1;  
    float xShear = FLT_MAX;
    float yShear = FLT_MAX;
    struct point *pointTest = {1,4,6,1};
    struct point pointExpected = {pointTest->element[0] + (xShear * pointTest->element[2]), pointTest->element[1] + (xShear * pointTest->element[2]),6,1};

    setPoint(0, pointTest);
    setXShear(xShear);
    setYShear(yShear);
    zShear();

    if(getPoint(0)->element[0] != pointExpected.element[0] || getPoint(1)->element[1] != pointExpected.element[1]) {
        fprintf(stderr, "Test4 Failed: Expected point does not match test point\n");
    } else {
        printf("Test4 Passed\n");
    }
}

/**
 *  Uninitialzed Shear Values test
 *  Type: Dirty
 *  - This function will call zShear by passing uninitialized x and y shear values 
 *  xShear: Unintialized
 *  yShear: Unintialized
 *  Test point: {1,4,6,1}
 *  Expected point: {1,4,6,1}
 */
void test5() {
    inputShape->numOfPoints = 1; 
    float xShear;
    float yShear;
    struct point *pointTest = {1,4,6,1};
    // struct point pointExpected = {1,4,6,1};

    setPoint(0, pointTest);
    setXShear(xShear);
    setYShear(yShear);
    zShear();
    
    if(!inputShape->shearing[0] || !inputShape->shearing[1]) {
        fprintf(stderr, "Test5 Failed: Expected point does not match test point\n");
    } else {
        printf("Test5 Passed\n");
    }
}