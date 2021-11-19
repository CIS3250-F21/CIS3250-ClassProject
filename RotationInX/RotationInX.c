#include "RotationInX.h"
#include "../main.h"

void xRotation() {

    generateXRotationMatrix(getXRotation());
    struct point* x;
    int i = 0;

    while ((x = getPoint(i)) != NULL) {
        multiplyMatrix(x, transformationMatrix);
        
        // loop through x and round close to 0, to 0.
        for (int k = 0; k < 4; k++) {
            if (compareFloat(x->element[k], 0, 0.0001) == 0) {
                x->element[k] = 0;  
            }
        }  

        setPoint(i, x);

        i++;
    }
}

void generateXRotationMatrix(float theta) {

  // apply the rotation matrix formula to the transformationMatrix 
  // with the given theta
  
  resetMatrix();

  transformationMatrix[1][1] = cos(theta);
  transformationMatrix[1][2] = (- (sin(theta)));

  transformationMatrix[2][1] = sin(theta);
  transformationMatrix[2][2] = cos(theta);
  
}
