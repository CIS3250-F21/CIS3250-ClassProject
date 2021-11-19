#include "ShearInZ.h"

void zShear() {
    // Use the transformation matrix and multiply the points 
    struct point *currentPoint;

    // Reset transformation matrix before use
    resetMatrix();
    // store Shear Values
    transformationMatrix[2][0] = getXShear();
    transformationMatrix[2][1] = getYShear();

    // Loop call of multiply martrix on current point
    for(int i = 0; i < inputShape->numOfPoints; i++) {
        currentPoint = getPoint(i);

        if(currentPoint == NULL) return;

        multiplyMatrix(currentPoint, transformationMatrix);
        setPoint(i, currentPoint);
    }
}
