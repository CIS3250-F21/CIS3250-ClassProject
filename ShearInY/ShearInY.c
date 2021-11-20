#include "ShearInY.h"

void yShear() {

  //get shear values
  float xShearVal = getXShear();
  float zShearVal = getZShear();
  

  //reset matrix
  resetMatrix();

  transformationMatrix[1][0] = xShearVal;

  //change col 1, row 2
  transformationMatrix[1][2] = zShearVal;

  //multply points by matrix
  struct point* currentVector;

  //multiply matrix by point
  for(int i = 0; i < inputShape->numOfPoints; i++) {
    currentVector = getPoint(i);

    if(currentVector == NULL) 
      return;

    multiplyMatrix(currentVector, transformationMatrix);
    setPoint(i, currentVector);
    }
}
