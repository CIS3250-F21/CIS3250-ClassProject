#include "ScalingInX.h"

void xScaling() {
  //Rest transformation matrix before use
  resetMatrix();
  //set the first coordinate to x scale 
  transformationMatrix[0][0] = getXScale();

  //Use the transformation matrix and multiply the Points 
  struct point *currentPoint = NULL;
  
  //loop through the number of points
  for (int k = 0; k < inputShape -> numOfPoints; k++) {
    currentPoint = getPoint(k);
    multiplyMatrix(currentPoint, transformationMatrix);

    //set point at index k to new transformed point
    setPoint(k, currentPoint);
  }
  

  resetMatrix();
}
