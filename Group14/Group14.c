#include "Group14.h"
#include "main.h"

void yShear() {

// float yShearVal = inputShape->translation[1];
  
  //use get function to retrieve y shear value:

  float yShearVal = getYShear();

  int numOfVectors = 4;

  float xCoordinate = 0;
  float yCoordinate = 0;

  
  for(int i = 0; i < 4; i++)
  {
    xCoordinate = transformationMatrix[i];
    
    for (int j = 0; j <4; j++)
    {
      yCoordinate = transformationMatrix[i][j];
      //the matrix that is being edited
      transformationMatrix [i] [j] = yCoordinate + yShearVal * xCoordinate;
    }
    /*
    go through each coordinate for each point and apply:
    yCoorindate[i] = yCoorindate [i] + yShearVal * xcoordate[i]
    */
  
    printf("%f\n", vectors[i]);
  }

  return;
  
}
