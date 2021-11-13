#include "xyzOrthographicProjection.h"

void xyzOrthographicProjection() 
{
  int index;
  struct * point tempPoint;
  int i, j; //begin setting the global tranformationMatrix's values all to 0
  for (i = 0; i < 4; i ++) 
  {
    for (j = 0; j < 4; j++)
    {
    transformationMatrix[i][j] = 0;
    }
  }
  transformationMatrix[0][0] = 1; // set the transformation matrix as an identity matrix
  transformationMatrix[1][1] = 1; // except for the third column, which will still be all zero's
  transformationMatrix[3][3] = 1;

  for ( index = 0; index < inputShape->numOfVectors; index++)
  {
    
    tempPoint = getPoint(index); //get vector from global matrix in inputShape
    multiplyMatrix(tempPoint, transformationMatrix); //rearrange that vector
    setPoint(index, tempPoint); //set it back inside inputShape
  }
}
