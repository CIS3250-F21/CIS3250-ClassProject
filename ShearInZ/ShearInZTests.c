#include "ShearInZTests.h"
#include "ShearInZ.h"

void runZShearTests() {
    validTest();
    nullPointTest();
    minimumFloatShearValueTest();
    maximumFloatShearValueTest();
    uninitializedShapeStructTest();
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
    
    if(getPoint(0)->element[0] != pointExpected->element[0] || getPoint(0)->element[1] != pointExpected->element[1]) {
        fprintf(stderr, "validTestTest Failed: Expected point does not match test point\n");
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

    setPoint(0, p1);
    setXShear(xShear);
    setYShear(yShear);
    zShear();
    
    if(getPoint(0) == NULL) {
        fprintf(stderr, "nullPointTest Failed: Expected point does not match test point\n");
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
    
    if(getPoint(0)->element[0] != pointExpected->element[0] || getPoint(0)->element[1] != pointExpected->element[1]) {
        fprintf(stderr, "minimumFloatShearValueTest Failed: Expected point does not match test point\n");
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
    
    if(getPoint(0)->element[0] != pointExpected->element[0] || getPoint(0)->element[1] != pointExpected->element[1]) {
        fprintf(stderr, "maximumFloatShearValueTest Failed: Expected point does not match test point\n");
    }
    free(pointExpected);
}

/**
 *  Uninitialzed shape struct
 *  @brief: This function will test is the shape struct is initialied or not
 *  @type: Dirty
 */
void uninitializedShapeStructTest() {
    if(inputShape == NULL) {
        fprintf(stderr, "uninitializedShapeStructTest Failed: Shape struct is not initialized\n");
    }
}
