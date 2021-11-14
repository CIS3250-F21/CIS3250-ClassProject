#include "YPlaneReflection.h"

void yPlaneReflection() {

	// edit the global float ** matrix
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			transformationMatrix[i][j] = 0.0;
		}
	}

	transformationMatrix[0][0] = 1;
	transformationMatrix[1][1] = -1;
	transformationMatrix[2][2] = 1;
	transformationMatrix[3][3] = 1;

	// define local vector structure for storing the product of the matrix multiplication
	struct point* vect;

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
