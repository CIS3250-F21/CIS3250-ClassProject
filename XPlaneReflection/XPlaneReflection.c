#include "XPlaneReflection.h"
#include "../main.h"

void xPlaneReflection() {
    generateXPlaneReflectionMatrix();
    struct point* p;
    int i = 0;

    while ((p = getPoint(i)) != NULL)
    {
		multiplyMatrix( p, transformationMatrix );
		setVector( i, p );
        i++;
	}
}

void generateXPlaneReflectionMatrix() {
	for ( int i = 0; i < 4; i++ ){
		for ( int j = 0; j < 4; j++ ){
		    if ( i == j ){
			    transformationMatrix[i][j] = 1;
                if( i==0 ){
                    transformationMatrix[i][j] = -1;
                }	
		    }
		    else {
			    transformationMatrix[i][j] = 0;
		    }
		}
	}
}