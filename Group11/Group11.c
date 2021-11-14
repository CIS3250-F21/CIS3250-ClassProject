#include "YPlaneReflection.h"
#include "../main.h"

void yPlaneReflection() {
  
  // edit global float matrix 
	int i, j;

	struct point localVector;
	struct point* vect;

	j = 1, i = 0;
	// get vector
	while (j) {
		vect = getVector(i);
		// if getVector returns Null break the loop 
		if (vect == NULL) {
			j = 0;
		}
		// otherwise transform vector
		else {
			// multiply vector with transformation matrix 
			multiplyMatrix(vect);

			localVector.element[0] = vect->element[0];
			localVector.element[1] = vect->element[1];
			localVector.element[2] = vect->element[2];
			localVector.element[3] = vect->element[3];
			// set updated local vector back using set 
			setVector(i, localVector);
			// increment index 
			i++;
		}
	}

}
