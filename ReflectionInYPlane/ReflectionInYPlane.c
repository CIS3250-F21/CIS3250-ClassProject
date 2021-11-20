<<<<<<< HEAD:YPlaneReflection/YPlaneReflection.c
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
    resetMatrix();
        transformationMatrix[1][1] = -1;
}
=======
#include "ReflectionInYPlane.h"

void ReflectionInYPlane() {
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
    resetMatrix();
        transformationMatrix[1][1] = -1;
}
>>>>>>> e751d3211daa75cc0957f736a3fd064f754c7f07:ReflectionInYPlane/ReflectionInYPlane.c
