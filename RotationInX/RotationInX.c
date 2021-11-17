#include "RotationInX.h"
#include "../main.h"

void xRotation() {

    // call generateXRotationMatrix on our rotation theta
    generateXRotationMatrix(getXRotation());
    
    struct point* currPoint;

    // call multiplyMatrix on each point in inputShape
    for (int i = 0; i < inputShape -> numOfPoints; i++) {
		
        currPoint = getPoint(i);
		
        // exit if point at i doesn't exist
        if (currPoint == NULL) {
          return;
        }

        multiplyMatrix(currPoint, transformationMatrix);
        setPoint(i, currPoint);
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

  transformationMatrix[2][0] = sin(theta);
  transformationMatrix[2][1] = 0;
  transformationMatrix[2][2] = cos(theta);
  transformationMatrix[2][3] = 0;

  transformationMatrix[3][0] = 0;
  transformationMatrix[3][1] = 0;
  transformationMatrix[3][2] = 0;
  transformationMatrix[3][3] = 1;
}
