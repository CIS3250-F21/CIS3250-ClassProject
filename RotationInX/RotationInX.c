#include "RotationInX.h"
#include "../main.h"

void xRotation() {

    generateXRotationMatrix(getXRotation());
    struct point* x;
    int i = 0;

    while ((x = getPoint(i)) != NULL) {
        multiplyMatrix(x, transformationMatrix);
        setPoint(i, x);
        i++;
    }
}

void generateXRotationMatrix(float theta) {

  // apply the rotation matrix formula to the transformationMatrix 
  // with the given theta
  transformationMatrix[0][0] = 1;
  transformationMatrix[0][1] = 0;
  transformationMatrix[0][2] = 0;
  transformationMatrix[0][3] = 0;

  transformationMatrix[1][0] = 0;
  transformationMatrix[1][1] = cos(theta);
  transformationMatrix[1][2] = (- (sin(theta)));
  transformationMatrix[1][3] = 0;

  transformationMatrix[2][0] = 0;
  transformationMatrix[2][1] = sin(theta);
  transformationMatrix[2][2] = cos(theta);
  transformationMatrix[2][3] = 0;

  transformationMatrix[3][0] = 0;
  transformationMatrix[3][1] = 0;
  transformationMatrix[3][2] = 0;
  transformationMatrix[3][3] = 1;
}
