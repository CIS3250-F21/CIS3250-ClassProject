#include "XYZTranslation.h"

void xyzTranslation() {
    // Variable Declarations
    int index = 0;
    float x = 0, y = 0, z = 0;
    struct point *resultPoint;
    
    // Set initial values to 0
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            transformationMatrix[i][j] = 0.0;
      }
    }

    // Create the translation matrix
    transformationMatrix[0][0] = 1.0;
    transformationMatrix[1][1] = 1.0;
    transformationMatrix[2][2] = 1.0;
    transformationMatrix[3][3] = 1.0;

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
    