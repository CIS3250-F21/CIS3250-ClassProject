#include "XYZOrthographicProjection.h"

void XYZOrthographicProjection() 
{
  int index;
  struct  point * tempPoint;

  generateXYZOrthographicProjectionMatrix();

  for ( index = 0; index < inputShape->numOfPoints; index++)
  {
    
    tempPoint = getPoint(index); //get vector from global matrix in inputShape
    multiplyMatrix(tempPoint, transformationMatrix); //rearrange that vector
    setPoint(index, tempPoint); //set it back inside inputShape
  }
}

void generateXYZOrthographicProjectionMatrix()
{
  resetMatrix();
  transformationMatrix[2][2] = 0;
}
