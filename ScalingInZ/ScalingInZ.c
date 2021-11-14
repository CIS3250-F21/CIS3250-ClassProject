#include "ScalingInZ.h"

void zScaling(){

  float pointScalingValue = getZScale();
  
    struct point* newPoint;
    int x = 0;

  while ((newPoint = getPoint(x)) != NULL)
  {
    float zValue;
    zValue = newPoint->element[2];
    zValue *= pointScalingValue;
    newPoint->element[2] = zValue;
    setPoint(x, newPoint);
    x++; 
  }

  // if (!newPoint){ //checks that there is a valid point at the index location
  //     fprintf(stderr, "zScaling(): ERROR: No point at given location\n");
  //     return;
  // }
  
  return;
}
