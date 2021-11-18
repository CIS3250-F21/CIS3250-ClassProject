#include "XPlaneReflection.h"
#include "../main.h"

void xPlaneReflection() {
    generateXPlaneReflectionMatrix();
    struct point* p;
    int i = 0;

	// Loop through each point negating x-values
    while ((p = getPoint(i)) != NULL)
    {
		multiplyMatrix( p, transformationMatrix );
		setPoint( i, p );
        i++;
	}
}

// Generates identity matrix with -1 in [0][0] element
void generateXPlaneReflectionMatrix() {
	resetMatrix();
	transformationMatrix[0][0] = -1;
}
