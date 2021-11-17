#include "ShearInZTests.h"
#include "ShearInZ.h"

void runZShearTests() {
    validTest();
    nullPointTest();
    minimumFloatShearValueTest();
    maximumFloatShearValueTest();
    uninitializedShearValueTest();
}

/**
 *  Valid Data Test
 *  @brief: This function tests valid data for the zShear transformation
 *  @type: type
 *  Test point: {1,4,6,1}
 *  Expected point: {25,16,6,1}
 */
void validTest() {
    float xShear = 4;
    float yShear = 2;

    struct point *p1 = getPoint(0);
    p1->element[0] = 1;
    p1->element[1] = 4;
    p1->element[2] = 6;
    p1->element[3] = 1;

    struct point *pointExpected = malloc(sizeof(struct point));
    pointExpected->element[0] = 25; 
    pointExpected->element[1] = 16; 
    pointExpected->element[2] = 6; 
    pointExpected->element[3] = 1; 
    /* Equation version of Z shear multiplication matrix
    X1 = X + (xShear * Z)
    Y1 = Y + (yShear * Z)
    Z = Z (remains unchanged)
    1 = 1 (remains unchanged)
    */
    setPoint(0, p1);
    setXShear(xShear);
    setYShear(yShear);
    zShear();
    
    if(getPoint(0)->element[0] != pointExpected->element[0] || getPoint(1)->element[1] != pointExpected->element[1]) {
        fprintf(stderr, "Test1 Failed: Expected point does not match test point\n");
    } else {
        printf("Test1 Passed\n");
    }

    free(pointExpected);
}

/**
 *  Null point test
 *  @brief: This function tests whether a point is Null or not
 *  @type: dirty
 */
void nullPointTest() {
    float xShear = 4;
    float yShear = 2;

    struct point *p1 = getPoint(0);
    p1 = NULL;

    /* Equation version of Z shear multiplication matrix
    X1 = X + (xShear * Z)
    Y1 = Y + (yShear * Z)
    Z = Z (remains unchanged)
    1 = 1 (remains unchanged)
    */
    setPoint(0, p1);
    setXShear(xShear);
    setYShear(yShear);
    zShear();
    
    if(getPoint(0) == NULL) {
        fprintf(stderr, "Test2 Failed: Expected point does not match test point\n");
    } else {
        printf("Test2 Passed\n");
    }
}

/**
 *  Minimum float edge case
 *  @brief: This function tries to perform the zShear transformation with the shear values set to the minimum float value
 *  @type: dirty
 *  xShear: -FLT_MIN
 *  yShear: -FLT_MIN
 *  Test point: {1,4,6,1}
 *  Expected point: {pointTest[0] + (xShear * pointTest[2]), pointTest[1] + (xShear * pointTest[2]),6,1}
 */
void minimumFloatShearValueTest() {
    float xShear = -FLT_MIN;
    float yShear = -FLT_MIN;

    struct point *p1 = getPoint(0);
    p1->element[0] = 1;
    p1->element[1] = 4;
    p1->element[2] = 6;
    p1->element[3] = 1;

    struct point *pointExpected = malloc(sizeof(struct point));
    pointExpected->element[0] = p1->element[0] + (xShear * p1->element[2]); 
    pointExpected->element[1] = p1->element[1] + (xShear * p1->element[2]); 
    pointExpected->element[2] = 6; 
    pointExpected->element[3] = 1; 

    setPoint(0, p1);
    setXShear(xShear);
    setYShear(yShear);
    zShear();
    
    if(getPoint(0)->element[0] != pointExpected->element[0] || getPoint(1)->element[1] != pointExpected->element[1]) {
        fprintf(stderr, "Test3 Failed: Expected point does not match test point\n");
    } else {
        printf("Test3 Passed\n");
    }
    free(pointExpected);
}

/**
 *  Maxixmum float edge case
 *  @brief: This function tries to perform the zShear transformation with the shear values set to the maximum float value
 *  @type: Dirty
 *  Test point: {1,4,6,1}
 *  Expected point: {pointTest[0] + (xShear * pointTest[2]), pointTest[1] + (xShear * pointTest[2]),6,1}
 */
void maximumFloatShearValueTest() {
    float xShear = FLT_MAX;
    float yShear = FLT_MAX;

    struct point *p1 = getPoint(0);
    p1->element[0] = 1;
    p1->element[1] = 4;
    p1->element[2] = 6;
    p1->element[3] = 1;

    struct point *pointExpected = malloc(sizeof(struct point));
    pointExpected->element[0] = p1->element[0] + (xShear * p1->element[2]); 
    pointExpected->element[1] = p1->element[1] + (xShear * p1->element[2]); 
    pointExpected->element[2] = 6; 
    pointExpected->element[3] = 1; 

    setPoint(0, p1);
    setXShear(xShear);
    setYShear(yShear);
    zShear();
    
    if(getPoint(0)->element[0] != pointExpected->element[0] || getPoint(1)->element[1] != pointExpected->element[1]) {
        fprintf(stderr, "Test4 Failed: Expected point does not match test point\n");
    } else {
        printf("Test4 Passed\n");
    }
    free(pointExpected);
}
/**
 *  Uninitialzed Shear Values test
 *  @brief: This function will call zShear by passing uninitialized x and y shear values 
 *  @type: Dirty
 *  Test point: {1,4,6,1}
 *  Expected point: {1,4,6,1}
 */
void uninitializedShearValueTest() {
    float xShear = 0; //todo: need to fix this test
    float yShear = 0;  

    setXShear(xShear);
    setYShear(yShear);
    zShear();
    
    if(!inputShape->shearing[0] || !inputShape->shearing[1]) {
        fprintf(stderr, "Test5 Failed: Expected point does not match test point\n");
    } else {
        printf("Test5 Passed\n");
    }
}
