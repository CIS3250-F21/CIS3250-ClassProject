#include "RotationInZ.h"

void zRotation() {
  
    generateZRotationMatrix (getZRotation ());

    struct point* currentPoint;

    for (int i = 0 ; i < inputShape -> numOfPoints ; i++) {
      
        currentPoint = getPoint (i);

        multiplyMatrix (currentPoint, transformationMatrix);

        setPoint (i, currentPoint);   
    }

}

void generateZRotationMatrix (float theta) {

    resetMatrix();
  
    transformationMatrix[0][0] = cos (theta);
    transformationMatrix[0][1] = -sin (theta);
    transformationMatrix[1][0] = sin (theta);
    transformationMatrix[1][1] = cos (theta);
}
