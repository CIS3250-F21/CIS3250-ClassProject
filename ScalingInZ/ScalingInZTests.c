#include "ScalingInZTests.h"
#include "ScalingInZ.h"
#include <float.h>
/* Clean Test */

/*
  The values in the matrix are compared before and after 
  they're scaled by the z scalar to check for accurracy and 
  overall correctness.
*/
/* Combination of test functions */ 

void correctScale()
{
  float val[] = {1.1,2.1,3.1,4.1,5.1};//5x5 matrix


//   float tempScale = getZScale(); 
  
  float zVals[inputShape->numOfPoints]; 

  /* Saving inital z values*/
  for (int x = 0; x < inputShape->numOfPoints; x++){
    struct point *newPoint = getPoint(x);
    zVals[x] = newPoint->element[2];
  }
  setZScale(2.0);//Setting only the z values for each point

  zScaling();// Scaling points 

  /* Comparing inital z values to newly scaled z values*/
  for (int y = 0; y < inputShape->numOfPoints; y++)
  {
	  struct point *newPoint = getPoint(y); 
      if (val[y]== newPoint->element[2])//If z value didn't scale
      {
        fprintf(stderr, "ERROR: Issue with Z values\n");
        return;
      }
  }
}

/* Dirty Tests */

/* 
  Tests the ability of the zScaling function in handling multiplication by 0.
  Upon successful completion, all z values should be set to 0 otherwise an error message 
  will follow.
*/
void zeroMulti(){

  float val[] = {1.1, -2.2, 3.3, -4.4, 5.5};//5x5 matrix

  //Setting only the z values for each point
  for (int z = 0; z < inputShape->numOfPoints; z++)
  {
    struct point *newPoint = getPoint(z);
    newPoint->element[2] = val[z];
    setPoint(z, newPoint);
  }

  setZScale(0);
  
  zScaling();

  /* Checking newly scaled z values*/
  for (int y = 0; y < inputShape->numOfPoints; y++)
  {
      struct point *newPoint = getPoint(y);
      if (newPoint->element[2] != 0)//+ve didn't turn -ve
      {
        fprintf(stderr, "ERROR: Improper scaling with Z scalar of 0\n\n");
        return; 
      }
  }

}
/*
  Test to see if zScaling can handle negative multipliers
  Previously negative floats should be positive and vice versa. 
*/
void negativeShapeScale()
{
  float val[] = {-1.1, 2.2, -3.3, 4.4, -5.5};//5x5 matrix

  for (int z = 0; z < inputShape->numOfPoints; z++)
  {
    struct point *newPoint = getPoint(z);
    newPoint->element[2] = val[z];
    setPoint(z, newPoint);
  }
    
  setZScale(-3.0);
  
  float f_precision = 0.00001; 
  zScaling();
  
    for (int y = 0; y < inputShape->numOfPoints; y++)
    {
		    struct point *newPoint = getPoint(y);

        if (val[y] * getZScale() - f_precision >= newPoint->element[2] && val[y] * -3.0 + getZScale() <= newPoint->element[2])
        {
          fprintf(stderr, "ERROR: Improper scaling of using a -ve scalar\n\n");
          return;
        }
    }
}


/*
  Test the function's ability to handle overflow. 
  Signed overflow should occur as a result of scaling by the max floating value. 
*/ 
void overflow()
{
  float zVals[inputShape->numOfPoints];
  for (int x = 0; x < inputShape->numOfPoints; x++){
    	zVals[x] = 1;
  }
  zVals[0] = FLT_MAX;

   //Setting the z value for the first point to 0
  struct point *newPoint = getPoint(0);
  newPoint->element[2] = zVals[0];
  setPoint(0, newPoint);

  setZScale(2.0);
  zScaling();//Scaling z values 

  newPoint = getPoint(0);
  
  if (newPoint->element[2] < 0)//max float should wrap around to -ve
  {
    fprintf(stderr, "ERROR: Overflow has occurred\n\n");
  }

}

/*
  Tests the function's ability to handle a NULL point.
  Flags an error if the function returns a valid point and did not have a segmentation fault.
*/
void nullPoint()
{
  float zVals[inputShape->numOfPoints];
  for (int x = 0; x < inputShape->numOfPoints; x++){
    zVals[x] = x;
  }

  //Setting only the z values for each point
  for (int z = 0; z < inputShape->numOfPoints; z++)
  {
    struct point *newPoint = getPoint(z);
    newPoint->element[2] = zVals[z];
    setPoint(z, newPoint);
  }

  setZScale(2.0);

  struct point *pointPtr = getPoint(0);

  inputShape->points[0] = NULL;//manually setting to null
  
  zScaling();//scaling z values

  struct point *newPoint = getPoint(0);
  if (newPoint){
    fprintf(stderr, "ERROR: Changes have been made to NULL point");
  }

  setPoint(0, pointPtr); //reset point pointer in inputShape
}

/*
  Test to observe function's ability to handle points outside
  of the expected bounds.
  The test should still be able to correctly handle the points
  that are inside the expected bounds. If the ZScaling() function
  returns and has successfully modified the points within bounds
  the test has passed.
*/
void incrementedPoint()
{
  float zVals[inputShape->numOfPoints];
  for (int x = 0; x < inputShape->numOfPoints; x++){
    zVals[x] = x;
  }

  //Setting only the z values for each point
  for (int z = 0; z < inputShape->numOfPoints; z++)
  {
    struct point *newPoint = getPoint(z);
    newPoint->element[2] = zVals[z];
    setPoint(z, newPoint);
  }

  setZScale(2);
  inputShape->points += 2;

  zScaling();

  struct point *newPoint = getPoint(0);
  if (newPoint->element[2] != 4){
    fprintf(stderr, "Function did not make changes to point \n\n");
  }
  inputShape->points -= 2; //reset point pointer
}
void runZScalingTests()
{
  
  /*Running Clean Test*/
  correctScale();

  /*Running Dirty Tests*/
  overflow();

  negativeShapeScale();

  zeroMulti();

  incrementedPoint();

  nullPoint();

}
