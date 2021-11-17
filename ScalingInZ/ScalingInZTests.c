#include "ScalingInZTests.h"
#include "ScalingInZ.h"
#include <float.h>
#include <math.h>
/* Clean Test */

/*
  The values in the matrix are compared before and after 
  they're scaled by the z scalar to check for accurracy and 
  overall correctness.
  Test Pass -> All z Values are scaled by the appropriate z scalar
  Test Fail -> One or more z Values are not scaled by the appropriate z scalar
*/
/* Combination of test functions */ 

void CorrectScale()
{
  float zVals[] = {1.1,2.1,3.1,4.1,5.1};//Simulates the z values in a 5x5 vector
  
  /* setting only z values in each vector*/
  for (int z = 0; z < inputShape->numOfPoints; z++)
  {
    struct point *newPoint = getPoint(z);
    newPoint->element[2] = zVals[z];
    setPoint(z, newPoint);
  }
  setZScale(2.0);

  zScaling();// Scaling points 

  /* Comparing inital z values to newly scaled z values*/
  for (int y = 0; y < inputShape->numOfPoints; y++)
  {
	    struct point *newPoint = getPoint(y); 
      if (newPoint->element[2] == zVals[y])//If a z value didn't scale
      {
        fprintf(stderr, "ERROR: Issue with Z values\n");
        return;
      }
  }
}

/* Dirty Tests */

/* 
  Tests the ability of the zScaling function in handling multiplication by 0.
  Test Pass -> Each vector should have a z value of 0
  Test Fail -> Vector(s) have a z value other than 0
*/
void ZeroMulti(){

  float zVals[] = {1.1, -2.2, 3.3, -4.4, 5.5};//Simulates the z values in a 5x5 vector

  //Setting only the z values for each point
  for (int z = 0; z < inputShape->numOfPoints; z++)
  {
    struct point *newPoint = getPoint(z);
    newPoint->element[2] = zVals[z];
    setPoint(z, newPoint);
  }

  setZScale(0);
  
  zScaling();

  /* Checking newly scaled z values*/
  for (int y = 0; y < inputShape->numOfPoints; y++)
  {
      struct point *newPoint = getPoint(y);
      if (newPoint->element[2] != 0)
      {
        fprintf(stderr, "ERROR: Improper scaling with Z scalar of 0\n\n");
        return; 
      }
  }

}
/*
  Test to see if zScaling can handle negative multipliers
  Test Pass-> Previously negative z values should be now be positive + scaled and vice versa
  Test Fail-> Previously negative z values are still negative and/or are not scaled after scaling and vice versa
*/
void NegativeShapeScale()
{
  float zVals[] = {-1.1, 2.2, -3.3, 4.4, -5.5};//Simulates the z values in a 5x5 vector

  for (int z = 0; z < inputShape->numOfPoints; z++)
  {
    struct point *newPoint = getPoint(z);
    newPoint->element[2] = zVals[z];
    setPoint(z, newPoint);
  }
    
  setZScale(-3.0);
  
  float f_precision = 0.00001; 

  zScaling();
  
    for (int y = 0; y < inputShape->numOfPoints; y++)
    {
		    struct point *newPoint = getPoint(y);

        if (zVals[y] * getZScale() - f_precision >= newPoint->element[2] && zVals[y] * getZScale() + f_precision <= newPoint->element[2])
        {
          fprintf(stderr, "ERROR: Improper scaling using a -ve scalar\n\n");
          return;
        }
    }
}


/*
  Test the function's ability to handle float max value
  Test Pass -> Program catches the float maximum and doesn't scale it
  Test Fail -> Large value trying to be scaled isn't caught and is scaled leading to
               the infinity value is left being left within the vector structure
*/ 
void Overflow()
{
  float zVals[] = {FLT_MAX,2,3,4,5};//Simulates the z values in a 5x5 vector

  int infFlag = 0; 

  for (int z = 0; z < inputShape->numOfPoints; z++)
  {
    struct point *newPoint = getPoint(z);
    newPoint->element[2] = zVals[z];
    setPoint(z, newPoint);
  }

  setZScale(20);

  zScaling();//Scaling z values 

  for (int x = 0; x < inputShape->numOfPoints; x++)
  {
    struct point * newPoint = getPoint(x);
    if (newPoint->element[2] >= FLT_MAX)
    {
      infFlag = 1;
    }
  }
  if (infFlag!=1)
  {
    fprintf(stderr, "Error: Infinity not caught within the vector structure");
    return;
  }
}

/*
  Tests the function's ability to handle a NULL point.
  Test Pass -> Main function should flag an error indicating that program is trying to 
               scale a Null vector
  Test Fail -> Main Program tries to scale a null vector and causes a segmentation fault
*/
void NullPoint()
{
  float zVals[] = {1.0,2.0,3.0,4.0,5.0};//Simulates the z values in a 5x5 vector

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
  Tests the function's ability to handle a float scalar of 1
  Test Pass -> None of the scaled values are different from the pre-scaled values
  Test Fail -> Scaled z values differ from pre-scaled z values 
*/
void OneShapeScale()
{
  //initializing the vectors
  float zVals[] = {-1.1, 2.2, -3.3, 4.4, -5.5};//5x5 matrix

  //Setting only the z values for each point
  for (int z = 0; z < inputShape->numOfPoints; z++)
  {
    struct point *newPoint = getPoint(z);
    newPoint->element[2] = zVals[z];
    setPoint(z, newPoint);
  }

  setZScale(1.0);

  zScaling();

  for (int x = 0; x < inputShape->numOfPoints; x++)
  {
      struct point *newPoint = getPoint(x);

      //Directly comparing "scaled  z values" to originally set z values
      if (newPoint->element[2] != zVals[x])
      {
        fprintf(stderr, "Error: Z values scaled by value other than 1\n\n");
      }
  }

}
<<<<<<< HEAD
void RunScalingInZTests()
=======

void runZScalingTests()
>>>>>>> 024ee200a106550a3eb0b9bf32163541d103f107
{
  
  /*Running Clean Test*/
  CorrectScale();

  /*Running Dirty Tests*/
  Overflow();

  NegativeShapeScale();

  ZeroMulti();

<<<<<<< HEAD
  OneShapeScale();
=======
  //incrementedPoint();
>>>>>>> 024ee200a106550a3eb0b9bf32163541d103f107

  NullPoint();

}
