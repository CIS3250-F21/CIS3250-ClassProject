#include "GlobalScaling.h"

void globalScaling(){
    resetMatrix();
    float globalScaleValue = 1.0;
    setGlobalScale(globalScaleValue);
    globalScaleValue = 1.0;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            transformationMatrix[i][j] *= globalScaleValue;
        }
    }

    float fourthValue;
    for(int i = 0; i < 4; i++) {
        fourthValue = transformationMatrix[i][3];
        if( fourthValue != 1) {
            for(int j = 3; j >= 0; j--) {
                transformationMatrix[i][j] /= fourthValue;
            }
        }
    }

    resetMatrix();
}
