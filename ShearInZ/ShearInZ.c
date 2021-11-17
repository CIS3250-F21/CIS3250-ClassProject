#include "ShearInZ.h"

void zShear() {
    // Use the transformation matrix and multiply the vectors 
    struct point *currentVector;

    // Reset transformation matrix before use
    resetMatrix();
    // store Shear Values
    transformationMatrix[2][0] = getXShear();
    transformationMatrix[2][1] = getYShear();

    // Loop call of multiply martrix on current point
    for(int i = 0; i < inputShape->numOfPoints; i++) {
        currentVector = getPoint(i);

        if(currentVector == NULL) return;

        multiplyMatrix(currentVector, transformationMatrix);
        setPoint(i, currentVector);
    }
}
