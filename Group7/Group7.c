#include "Group7.h"

#include "../main.h"

void yRotation() {
    generateYRotationMatrix(getYRotation());
    struct point* y;
    int i = 0;

    while ((y = getVector(i)) != NULL) {
        multiplyMatrix(y, transformationMatrix);
        setVector(i, y);
        i++;
    }
}

void generateYRotationMatrix(float newTheta) {
    // check if matrix is null first right here
    // if (transformationMatrix == NULL) {
    //     return;
    // }

    for (int i = 0; i < 4; i++) {
        if (transformationMatrix[i] == NULL) {
            return;
        }
    }

    transformationMatrix[0][0] = cos(newTheta);
    transformationMatrix[0][1] = 0;
    transformationMatrix[0][2] = sin(newTheta);
    transformationMatrix[0][3] = 0;

    transformationMatrix[1][0] = 0;
    transformationMatrix[1][1] = 1;
    transformationMatrix[1][2] = 0;
    transformationMatrix[1][3] = 0;

    transformationMatrix[2][0] = -sin(newTheta);
    transformationMatrix[2][1] = 0;
    transformationMatrix[2][2] = cos(newTheta);
    transformationMatrix[2][3] = 0;

    transformationMatrix[3][0] = 0;
    transformationMatrix[3][1] = 0;
    transformationMatrix[3][2] = 0;
    transformationMatrix[3][3] = 1;
}
