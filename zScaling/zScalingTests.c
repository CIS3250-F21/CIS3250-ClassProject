#include "Group5Tests.h"
#include "Group5.h"
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
  
  float zVals[inputShape->numOfVectors]; 

  /* Saving inital z values*/
  for (int x = 0; x < inputShape->numOfVectors; x++){
    struct point *newVector = getVector(x);
    zVals[x] = newVector->element[2];
  }
  setZScale(2.0);//Setting only the z values for each vector

  zScaling();// Scaling vectors 

  /* Comparing inital z values to newly scaled z values*/
  for (int y = 0; y < inputShape->numOfVectors; y++)
  {
	  struct point *newVector = getVector(y); 
      if (val[y]== newVector->element[2])//If z value didn't scale
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

  //Setting only the z values for each vector
  for (int z = 0; z < inputShape->numOfVectors; z++)
  {
    struct point *newVector = getVector(z);
    newVector->element[2] = val[z];
    setVector(z, newVector);
  }

  setZScale(0);
  
  zScaling();

  /* Checking newly scaled z values*/
  for (int y = 0; y < inputShape->numOfVectors; y++)
  {
      struct point *newVector = getVector(y);
      if (newVector->element[2] != 0)//+ve didn't turn -ve
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

  for (int z = 0; z < inputShape->numOfVectors; z++)
  {
    struct point *newVector = getVector(z);
    newVector->element[2] = val[z];
    setVector(z, newVector);
  }
    
  setZScale(-3.0);
  
  float f_precision = 0.00001; 
  zScaling();
  
    for (int y = 0; y < inputShape->numOfVectors; y++)
    {
		    struct point *newVector = getVector(y);

        if (val[y] * getZScale() - f_precision >= newVector->element[2] && val[y] * -3.0 + getZScale() <= newVector->element[2])
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
  float zVals[inputShape->numOfVectors];
  for (int x = 0; x < inputShape->numOfVectors; x++){
    	zVals[x] = 1;
  }
  zVals[0] = FLT_MAX;

   //Setting the z value for the first vector to 0
  struct point *newVector = getVector(0);
  newVector->element[2] = zVals[0];
  setVector(0, newVector);

  setZScale(2.0);
  zScaling();//Scaling z values 

  newVector = getVector(0);
  
  if (newVector->element[2] < 0)//max float should wrap around to -ve
  {
    fprintf(stderr, "ERROR: Overflow has occurred\n\n");
  }

}

/*
  Tests the function's ability to handle a NULL vector.
  Flags an error if the function returns a valid vector and did not have a segmentation fault.
*/
void nullVector()
{
  float zVals[inputShape->numOfVectors];
  for (int x = 0; x < inputShape->numOfVectors; x++){
    zVals[x] = x;
  }

  //Setting only the z values for each vector
  for (int z = 0; z < inputShape->numOfVectors; z++)
  {
    struct point *newVector = getVector(z);
    newVector->element[2] = zVals[z];
    setVector(z, newVector);
  }

  setZScale(2.0);

  struct point *vectorPtr = getVector(0);
  int index = 0; 

  inputShape->points[0] = NULL;//manually setting to null
  
  zScaling();//scaling z values

  struct point *newVector = getVector(0);
  if (newVector){
    fprintf(stderr, "ERROR: Changes have been made to NULL vector");
  }

  setVector(0, vectorPtr); //reset vector pointer in inputShape
}

/*
  Test to observe function's ability to handle vectors outside
  of the expected bounds.
  The test should still be able to correctly handle the vectors
  that are inside the expected bounds. If the ZScaling() function
  returns and has successfully modified the vectors within bounds
  the test has passed.
*/
void incrementedVector()
{
  float zVals[inputShape->numOfVectors];
  zVals[2] = 6;

  //Setting only the z values for each vector
  for (int z = 0; z < inputShape->numOfVectors; z++)
  {
    struct point *newVector = getVector(z);
    newVector->element[2] = zVals[z];
    setVector(z, newVector);
  }

  setZScale(2);
  inputShape->points += 2;

  zScaling();

  struct point *newVector = getVector(0);
  if (newVector->element[2] != 12){
    fprintf(stderr, "Function did not make changes to vector \n\n");
  }
  inputShape->points -= 2; //reset vector pointer
}
void runGroup5Tests()
{
  
  /*Running Clean Test*/
  printf("Running correctScale()\n");
  correctScale();

  /*Running Dirty Tests*/
   printf("Running overflow()\n");
   overflow();

   printf("Running negativeShapeScale()\n");
   negativeShapeScale();
   
   printf("Running zeroMulti()\n");
   zeroMulti();
   
   printf("Running incrementedVector()\n");
   incrementedVector();

   printf("Running nullVector()\n");
   nullVector();

}
