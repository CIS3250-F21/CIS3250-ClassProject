#include "RotationInY.h"

#include "../main.h"

void yRotation() {
    generateYRotationMatrix(getYRotation());
    struct point* y;
    int i = 0;

    while ((y = getPoint(i)) != NULL) {
        multiplyMatrix(y, transformationMatrix);

        // loop through y and round close to 0, to 0.
        for (int k = 0; k < 4; k++) {
            if (compareFloat(y->element[k], 0, 0.0001) == 0) {
                y->element[k] = 0;  
            }
        }    

        setPoint(i, y);
        i++;
    }
}

void generateYRotationMatrix(float newTheta) {
    resetMatrix();

    transformationMatrix[0][0] = cos(newTheta);
    transformationMatrix[0][2] = sin(newTheta);

    transformationMatrix[2][0] = -sin(newTheta);
    transformationMatrix[2][2] = cos(newTheta);
}
