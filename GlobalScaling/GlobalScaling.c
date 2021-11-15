#include "GlobalScaling.h"

void globalScaling(){
    resetMatrix();
    float globalScaleValue = 1.0;
    globalScaleValue = getGlobalScale();
    struct point* p;
    int i = 0;

    transformationMatrix[3][3] = globalScaleValue;
 
    float fourthValue;
    while((p = getPoint(i) != NULL)){
        multiplyMatrix( p, transformationMatrix );
    }
    
    while ((p = getPoint(i)) != NULL)
    {
	    fourthValue = p->element[3];
        if( fourthValue  != 1) {
            for(int j = 3; j >= 0; j--) {
                p->element[j] /= fourthValue;
            }
        }
        setPoint( i, p );
        i++;
	}

    resetMatrix();
}
