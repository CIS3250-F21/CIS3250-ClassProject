#include "GlobalScaling.h"

void globalScaling(){
    resetMatrix();
    float globalScaleValue = 1.0;
    globalScaleValue = getGlobalScale();
    struct point* p;
    int i = 0;
    transformationMatrix[3][3] = globalScaleValue;

    if(globalScaleValue == 0){
        fprintf(stderr, "Global scale value is invalid\n");
        exit(EXIT_FAILURE);
    } else {
         float fourthValue;
        while((p = getPoint(i)) != NULL){
            multiplyMatrix( p, transformationMatrix );

            fourthValue = p->element[3];
            if( fourthValue  != 1) {
                for(int j = 3; j >= 0; j--) {
                    p->element[j] /= fourthValue;
                }
            }
            setPoint( i, p );
            i++;
        }
    }



    resetMatrix();
}