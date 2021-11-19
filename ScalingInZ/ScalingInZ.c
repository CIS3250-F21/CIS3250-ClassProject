#include "ScalingInZ.h"
#include <float.h>

void zScaling(){

  resetMatrix(); 

  transformationMatrix[2][2] = getZScale(); 
  
  struct point* newPoint;

  for (int x = 0; x < inputShape->numOfPoints; x++)
  {
    newPoint = getPoint(x); 
    if(newPoint == NULL)
    {
      return;
    }
    if (newPoint->element[2] >=FLT_MAX)
    {
      return; 
    }
    multiplyMatrix(newPoint, transformationMatrix);
    setPoint(x, newPoint); 
  }

  resetMatrix(); 
  
  return;
}
