#include "ScalingInY.h"

/*
 *  GROUP 4
 *  Ayden Panhuyzen   (1103150)
 *  Connor Schulz     (1103003)
 *  Jennifer Lithgow  (1134108)
 *  Sami Edaibis      (1133434)
 */

void testGetYScale() {

  float valsToTest[5] = {5, 0, -5, 1.34, -1.34};
  int i;

  for (i = 0; i < 5; i++) {
    // set Y scale manually to current val
    inputShape->scaling[1] = valsToTest[i];

    // Check result
    if (getYScale() != valsToTest[i]) {
      fprintf(stderr,
              "ERROR: getYScale did not return expected value of %f, got %f "
              "instead\n",
              valsToTest[i], getYScale());
    }
  }

}

void testSetYScale() {

  float valsToTest[5] = {5, 0, -5, 1.34, -1.34};
  int i;

  for (i = 0; i < 5; i++) {
    // set Y scale to current value
    setYScale(valsToTest[i]);

    // Check result
    if (inputShape->scaling[1] != valsToTest[i]) {
      fprintf(stderr,
              "ERROR: setYScale did not return expected value of %f, got %f "
              "instead\n",
              valsToTest[i], inputShape->scaling[1]);
    }
  }

}

void testGetPoint() {
  struct point * currentPointMan, * currentPointGet;
  int i;

  // initialize array of 5 points with y values, 0, 1, -1, 100, -100
  initialisePoints();

  // match manually retrieved y value with y value from getPoint
  for (i = 0; i < 5; i++) {
    currentPointMan = inputShape->points[i];
    currentPointGet = getPoint(i);
    if (currentPointMan->element[1] != currentPointGet->element[1]) {
      fprintf(stderr,
              "ERROR: getPoint did not return expected value of %f, got %f "
              "instead\n",
              currentPointMan->element[1], currentPointGet->element[1]);
    }
  }
}

void testSetPoint() {
  float valsToTest[5] = {5, 0, -5, 1.34, -1.34};
  struct point * currentPoint = malloc (sizeof(struct point));
  int i;

  for (i = 0; i < 5; i++) {
    // modify the current points y value and set it in the points array
    currentPoint->element[1] = valsToTest[i];
    setPoint(i, currentPoint);

    // Check result
    if (inputShape->points[i]->element[1] != valsToTest[i]) {
      fprintf(stderr,
              "ERROR: setPoint did not return expected value of %f, got %f "
              "instead\n",
              valsToTest[i], inputShape->points[i]->element[1]);
    }
  }
}
