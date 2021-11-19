#include "XYZTranslation.h"

void xyzTranslation() {
    // Variable Declarations
    int index = 0;
    struct point *resultPoint;
    
    // Create the Identity matrix
    resetMatrix();
    
    // Edit indices in the 4th row to corresponding XYZ Values
    transformationMatrix[3][0] = getXTranslation();
    transformationMatrix[3][1] = getYTranslation();
    transformationMatrix[3][2] = getZTranslation();

    // receive a vector from the global structure
    while((resultPoint = getPoint(index)) != NULL) {
        resultPoint = getPoint(index);
        multiplyMatrix(resultPoint, transformationMatrix);
        setPoint(index, resultPoint);
        index++;
    }
}
