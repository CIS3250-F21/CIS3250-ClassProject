#include "main.h"

void yRotation(float **newMatrix, float *theta) {  // SLICK
    generateYRotationMatrix(getYRotation());
    struct vector *y;
    int i = 0;

    while ((y = getVector(i)) != NULL) {
        multiplyMatrix(y, transformationMatrix);
        setVector(i, y);
        i++;
    }
}

void generateYRotationMatrix(float theta) {
    // check if matrix is null first right here
    if (transformationMatrix == NULL) {
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (transformationMatrix[i] == NULL) {
            return;
        }
    }

    transformationMatrix[0][0] = cos(theta);
    transformationMatrix[0][1] = 0;
    transformationMatrix[0][2] = sin(theta);
    transformationMatrix[0][3] = 0;

    transformationMatrix[1][0] = 0;
    transformationMatrix[1][1] = 1;
    transformationMatrix[1][2] = 0;
    transformationMatrix[1][3] = 0;

    transformationMatrix[2][0] = -sin(theta);
    transformationMatrix[2][1] = 0;
    transformationMatrix[2][2] = cos(theta);
    transformationMatrix[2][3] = 0;

    transformationMatrix[3][0] = 0;
    transformationMatrix[3][1] = 0;
    transformationMatrix[3][2] = 0;
    transformationMatrix[3][3] = 1;
}
