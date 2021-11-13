#include "ScalingInX.h"

void xScaling() {
  //Rest transformation matrix before use
  resetMatrix();
  //set the first coordinate to x scale 
  transformationMatrix[0][0] = getXScale();

  //Use the transformation matrix and multiply the vectors 
  struct point **currentVector = NULL;
  
  //loop through the number of points
  for (int k = 0; k < inputShape -> numOfPoints; k++) {
    *currentVector = getPoint(k);
    multiplyMatrix(*currentVector, transformationMatrix);

    //set point at index k to new transformed point
    setPoint(k, *currentVector);
  }
  

  resetMatrix();
}
