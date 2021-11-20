#include "XYZOrthographicProjection.h"

void XYZOrthographicProjection() 
{
  int index;
  struct  point * tempPoint; 

  generateXYZOrthographicProjectionMatrix();

  for ( index = 0; index < inputShape->numOfPoints; index++)
  {
    //get vector from global matrix in inputShape
    tempPoint = getPoint(index); 
    multiplyMatrix(tempPoint, transformationMatrix); 
    setPoint(index, tempPoint); //set it back inside inputShape
  }
}

void generateXYZOrthographicProjectionMatrix()
{
  resetMatrix(); //resets transformation matrix to identity matrix
  transformationMatrix[2][2] = 0; //set z column (third column of matrix) in identity matrix to zero. 

}
