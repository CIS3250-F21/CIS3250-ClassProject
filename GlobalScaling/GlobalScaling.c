#include "GlobalScaling.h"

void globalScaling(){
    float globalScaleValue;
    setGlobalScale(globalScaleValue);

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            transformationMatrix[i][j] *= globalScaleValue;
        }
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(j == 3){
                float fourthValue = transformationMatrix[i][j];
                if(transformationMatrix[i][j] != 1){
                    transformationMatrix[i][j] /= fourthValue;
                    transformationMatrix[i][j-1] /= fourthValue;
                    transformationMatrix[i][j-2] /= fourthValue;
                    transformationMatrix[i][j-3] /= fourthValue;
                }
            }
        }
    }

    resetMatrix();
}
