#include "YPlaneReflection.h"

void yPlaneReflection() {
	generateYPlaneReflectionMatrix();
	struct point* vect;
	int j = 1;

	int index = 0;

	while (j) {
		// get the vector from shapes
		vect = getPoint(index);

		// if getVector returns NULL then break the loop
		if (vect == NULL) {
			j = 0;
		}
		// otherwise transform the vector
		else {
			// multiply vector with transform matrix
			multiplyMatrix(vect, transformationMatrix);
			// store result of multiplication in local vector structure
			// set the updated local vector back to shape using setVector
			setPoint(index, vect);
			// increment index
			index++;
		}
	}
}

void generateYPlaneReflectionMatrix() {
	for ( int i = 0; i < 4; i++ ){
		for ( int j = 0; j < 4; j++ ){
		    if ( i == j ){
			    transformationMatrix[i][j] = 1;
                if( i==1 ){
                    transformationMatrix[i][j] = -1;
                }	
		    }
		    else {
			    transformationMatrix[i][j] = 0;
		    }
		}
	}
}
