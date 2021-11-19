#include "RotationInZ.h"

void zRotation() {
  
    generateZRotationMatrix (getZRotation ());

    struct point* currentPoint;

    for (int i = 0 ; i < inputShape -> numOfPoints ; i++) {
      
        currentPoint = getPoint (i);

        multiplyMatrix (currentPoint, transformationMatrix);

        // loop through y and round close to 0, to 0.
        for (int k = 0; k < 4; k++) {
            if (compareFloat(currentPoint->element[k], 0, 0.0001) == 0) {
                currentPoint->element[k] = 0;  
            }
        }  

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
