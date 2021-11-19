#include "RotationInY.h"

#include "../main.h"

void yRotation() {
    generateYRotationMatrix(getYRotation());
    struct point* y;
    int i = 0;

    while ((y = getPoint(i)) != NULL) {
        multiplyMatrix(y, transformationMatrix);
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
