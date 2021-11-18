#include "ZPlaneReflection.h"

void ZPlaneReflection() {
    // If Z Reflection was selected in transformation file
    if( getZReflection() != 0 ) {
        // z plane reflection matrix
        if (!(inputShape == NULL)){
        //sets transformation matrix
            for (int i = 0; i < 4; i ++) {
                for (int j = 0; j < 4; j ++) {
                    transformationMatrix[i][j] = 0.0;
                }
            }
            transformationMatrix[0][0] = 1.0;
            transformationMatrix[1][1] = 1.0;
            transformationMatrix[2][2] = -1.0;
            transformationMatrix[3][3] = 1.0;
            int index = 0;
            int good = 0;
                //multply points by matrix
            struct point* y;
            while ((y = getPoint(index)) != NULL) {
                y = getPoint(index);
                for (int o = 0; o < 4; o ++) {
                    if (y->element[o] < -FLT_MAX || y->element[o] > FLT_MAX) {
                        good = 1;
                        break;
                    } else if ((y->element[o] < FLT_MIN && y->element[o] > 0) || (y->element[o] > -FLT_MIN && y->element[o] < 0)) {
                        good = 1;
                        break;
                    }
                }
                if (good == 1) {
                    break;
                }
                multiplyMatrix(y, transformationMatrix);
                setPoint(index, y);
                index++;
            }
        }
    }
}
