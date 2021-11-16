#include "ShearInY.h"

void yShear() {

  //get shear values
  float xShearVal = getXShear();
  float zShearVal = getZShear();

  //reset matrix
  resetMatrix();

  //change col 1, row 0
  transformationMatrix [0] [1] = 1 + xShearVal * transformationMatrix [0] [1];

  //change col 1, row 2
  transformationMatrix [2] [1] =  1 + zShearVal * transformationMatrix [2] [1] ;

  //multply points by matrix
  struct point* temp;

  for (int i = 0; i < inputShape->numOfPoints; i++) {
    
    temp = getPoint(i);
    
    if (temp == NULL) {
      return;
    }

    multiplyMatrix(temp, transformationMatrix);
    setPoint(i, temp);

    }
}
