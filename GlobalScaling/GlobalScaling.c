#include "GlobalScaling.h"

void globalScaling(){
    resetMatrix();
    float globalScaleValue = 1.0;
    setGlobalScale(globalScaleValue);
    struct point* p;
    int i = 0;

    for( int x = 0; x < 3; x++) {
        transformationMatrix[x][x] = 1;
    }
    transformationMatrix[3][3] = globalScaleValue;
    for( int x = 0; x < 3; x++) {
        transformationMatrix[x][x] *= globalScaleValue;
    }
    float fourthValue;
    
    while ((p = getPoint(i)) != NULL)
    {
	    fourthValue = p.element[3];
        if( fourthValue  != 1) {
            for(int j = 3; j >= 0; j--) {
                p.element[j] /= fourthValue;
            }
        }
        multiplyMatrix( p, transformationMatrix );
        setPoint( i, p );
        i++;
	}

    resetMatrix();
}
