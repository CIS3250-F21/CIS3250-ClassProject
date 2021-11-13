#include "ScalingInY.h"

/*
 *  GROUP 4
 *  Ayden Panhuyzen   (1103150)
 *  Connor Schulz     (1103003)
 *  Jennifer Lithgow  (1134108)
 *  Sami Edaibis      (1133434)
 */

/* The global inputShape variable is a pointer to a shape, shape*, that
 * represents a shape in 3D space. It corresponds to a list of points, as well
 * as different factors to transform the aforementioned points. points in the
 * shape can be accessed using [index] with index referring to a specific
 * point.*/
struct shape *inputShape;

//==============================================================================
//  Get and Set Fucntions
//==============================================================================

/* Gets the Y scaling value */
float getYScale() { 
  return inputShape->scaling[1]; 
}

/* Sets the Y scaling value */
void setYScale(float newYScale) { 
  inputShape->scaling[1] = newYScale; 
}

/* Gets a point struct from a given index in the inputShape */
struct point* getPoint(int index) {
    // if the index is less then 0 or greater the the number of points, or the points are null
    if ((index < 0) || (index >= inputShape->numOfPoints) || inputShape->points == NULL) {
        // return null
        return NULL;
    }

    // otherwise return the point at the index
    return inputShape->points[index];
}

/* Sets a point struct at a given index in the inputShape */
void setPoint(int index, struct point* newPoint) {
    // if the new point is null, don't set
    if (newPoint == NULL) {
        return;
    }

    // Otherwise if index is greater then 0 and is less then the number of points we have
    if ((index >= 0) && (index < inputShape->numOfPoints)) {
        // set the point at the index to the new point.
        inputShape->points[index] = newPoint;
    }
}

//==============================================================================
//  Function to Test
//==============================================================================

/* Modifies the y value of each element of the point list by multiplying the
 * current y value by the y scale value*/
int yScaling() {
    struct point * curPoint; // Holds current point
    float yScale = getYScale(); // Y scale used to modify points
    int curIndex; // Represents the index ofcurrent point being modified

    // Check if memory hasn't been allocated for the point array
    if (inputShape->points == NULL) {
        fprintf(stderr, "ERROR: Could not perform yScaling function.\n");
        return 0;
    }

    // Iterate through each point in the point array and update the y value by
    // multiplying it by the yScale value.
    for (curIndex = 0; curIndex < inputShape->numOfPoints; curIndex++) {
    curPoint = getPoint(curIndex);

    if (curPoint == NULL) {
        // point at this index is not initialised
        fprintf(stderr, "ERROR: Could not perform yScaling function at index %d.\n", curIndex);
        return 0;
    }

    curPoint->element[1] *= yScale;
    setPoint(curIndex, curPoint);
  }
  return 1;
}

void runPreTests(void) {
  int pointAmount = 5; // Number of points in the point array
  inputShape = malloc(sizeof(struct shape));
  inputShape->numOfPoints = pointAmount;

  inputShape->points = malloc(sizeof(struct point *) * pointAmount);
  for (int i = 0; i < pointAmount; i++) {
    inputShape->points[i] = malloc(sizeof(struct point));
    for (int j = 0; j < 4; j++) {
      inputShape->points[i]->element[j] = 1;
    }
  }

  testGetYScale();
  testSetYScale();
  testGetPoint();
  testSetPoint();

  // Free allocated memory
  free(inputShape->points);
  free(inputShape);
}

/* This function will run all the test cases defined above*/
void runPostTests(void) {
printf("\n\npost tests\n\n");
  int pointAmount = 5; // Number of points in the point array
  inputShape = malloc(sizeof(struct shape));
  inputShape->numOfPoints = pointAmount;

  uninitialisedYPointTest();

  inputShape->points = malloc(sizeof(struct point *) * pointAmount);
  for (int i = 0; i < pointAmount; i++) {
    inputShape->points[i] = malloc(sizeof(struct point));
    for (int j = 0; j < 4; j++) {
      inputShape->points[i]->element[j] = 1;
    }
  }

  testNegativeScale();

  testZeroScale();

  testPositiveScale();

  testFractionScale();

  // Free allocated memory
  free(inputShape->points);
  free(inputShape);
}

void runAllScalingInYTests(void) {
  runPreTests();
  runPostTests();
}
