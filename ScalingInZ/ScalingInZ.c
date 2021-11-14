#include "ScalingInZ.h"

void zScaling(){

  float pointScalingValue = getZScale();
  
  for(int x = 0; x < inputShape->numOfPoints; x++){
    float zValue;

    struct point *newPoint = getPoint(x);

    if (!newPoint){ //checks that there is a valid point at the index location
        fprintf(stderr, "zScaling(): ERROR: No point at given location\n");
        return;
    }
    else{
        zValue = newPoint->element[2];
        zValue *= pointScalingValue;
        newPoint->element[2] = zValue;
        setPoint(x, newPoint);
        
    }
  }
  return;
}
