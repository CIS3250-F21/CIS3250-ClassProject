#include "GlobalScaling.h"

void globalScaling(){
    resetMatrix();
    float globalScaleValue = 1.0;
    globalScaleValue = getGlobalScale();
    struct point* p;
    int i = 0;

    transformationMatrix[3][3] = globalScaleValue;

    float fourthValue;
    while((p = getPoint(i)) != NULL){
        int negativeScale = 0;
        multiplyMatrix( p, transformationMatrix );
        
        fourthValue = p->element[3];
        if(globalScaleValue > 0){
            if( fourthValue  != 1) {
                for(int j = 3; j >= 0; j--) {
                    p->element[j] /= fourthValue;
                }
            }
        }
        else if(globalScaleValue < 0){
            if( fourthValue  != -1) {
                for(int j = 3; j >= 0; j--) {
                    p->element[j] /= fourthValue;
                }
                negativeScale = 1;
            }
        }
        
        if(negativeScale){
            p->element[3] *= -1;
        }
        
        setPoint( i, p );
        i++;
    }

    resetMatrix();
}
