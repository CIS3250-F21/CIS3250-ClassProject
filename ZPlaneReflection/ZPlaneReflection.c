#include "ZPlaneReflection.h"

void ZPlaneReflection() {
    // z plane reflection matrix
    if (!(inputShape == NULL)){
    //sets transformation matrix
			generateZPlaneReflectionMatrix();
      int index = 0;
      int overUnderFlow = 0;
        //multply points by matrix
      struct point* vect;
      while ((vect = getPoint(index)) != NULL) {
        vect = getPoint(index);
        
        for (int o = 0; o < 4; o ++) {
          if (vect->element[o] < -FLT_MAX || vect->element[o] > FLT_MAX) {
            overUnderFlow = 1;
            break;
          } else if ((vect->element[o] < FLT_MIN && vect->element[o] > 0) || (vect->element[o] > -FLT_MIN && vect->element[o] < 0)) {
            overUnderFlow = 1;
            break;
          }
        }
        if (overUnderFlow == 1) {
          break;
        }
        multiplyMatrix(vect, transformationMatrix);
        setPoint(index, vect);
        index++;
    }
  }
}
void generateZPlaneReflectionMatrix() {
    resetMatrix();
    transformationMatrix[2][2] = -1;
}
