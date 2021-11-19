#include "ReflectionInXPlane.h"
#include "../main.h"

void ReflectionInXPlane() {
    generateXPlaneReflectionMatrix();
    struct point* p;
    int i = 0;
    int overUnderFlow = 0;

    // Loop through each point negating x-values
    while ((p = getPoint(i)) != NULL)
    {
        for (int o = 0; o < 4; o ++) {
            if (p->element[o] < -FLT_MAX || p->element[o] > FLT_MAX) {
                overUnderFlow = 1;
                break;
            } else if ((p->element[o] < FLT_MIN && p->element[o] > 0) || (p->element[o] > -FLT_MIN && p->element[o] < 0)) {
                overUnderFlow = 1;
                break;
            }
        }
        if (overUnderFlow == 1) {
          break;
        }
        
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
