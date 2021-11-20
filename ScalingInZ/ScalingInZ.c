#include "ScalingInZ.h"
#include <float.h>

void zScaling(){

  float pointScalingValue = getZScale();
  
    struct point* newPoint;
    int x = 0;

  while ((newPoint = getPoint(x)) != NULL)
  {
    float zValue;
    zValue = newPoint->element[2];
    zValue *= pointScalingValue;
    if(zValue >=FLT_MAX)
    {
      return;
    }
    newPoint->element[2] = zValue;
    setPoint(x, newPoint);
    x++; 
  }
  
  return;
}
