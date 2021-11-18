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

    for (int i = 0 ; i < 4 ; i++)  {

        for (int j = 0 ; j < 4; j++) {

            transformationMatrix[i][j] = 0;

        }
    }
  
    transformationMatrix[0][0] = cos (theta);
    transformationMatrix[0][1] = -sin (theta);
    transformationMatrix[1][0] = sin (theta);
    transformationMatrix[1][1] = cos (theta);
    transformationMatrix[2][2] = 1;
    transformationMatrix[3][3] = 1;  
}
