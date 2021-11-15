#include "Group8.h"

void zRotation() {
  
    float theta;
    theta = getZRotation ();
    generateZRotationMatrix (theta);
    struct point currentElement;

    for (int i = 0 ; i < inputShape -> numOfPoints ; i++) {
      
        currentElement = *(getPoint (i));

        multiplyMatrix (&currentElement, transformationMatrix);

        setPoint (i, &currentElement);
    
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
