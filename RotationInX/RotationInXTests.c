#include "RotationInXTests.h"
#include <float.h>

/* Set Function testing */

/* setXRotation Testing */
/* 
pass  - return 1, setXRotation sets testSetTheta correctly
fails - return 0, setXRotation does not set testSetTheta correctly
*/
int testSetXRotationWithValidTheta(){
  float testSetTheta = 19.89;
  setXRotation(testSetTheta);

  if(inputShape->rotation[0] == testSetTheta){
    return 1;
  }

  return 0;
}


/* 		Get Functions Testing		 	*/

/* getXRotation Testing */
/* 
pass  - return 1, getXRotation returns testSetTheta
fails - return 0, getXRotation returns another value 
*/
int testGetXRotation(){
  //set the inputShapes rotation [0] ->xrotation to the test theta
  float testGetTheta = 2.3;
  inputShape->rotation[0] = testGetTheta;
  //check if getXrotation returns the same value 
  if(getXRotation() == testGetTheta){
    return 1;
  }

  return 0;
}

/* getPoint Testing */
/* Dirty Test negative index
pass  - getPoint does not return 1 in the 4th value in point
fails - getPoint returns 1 in the 4th value in point
*/
int testGetpointNegativeIndex(){
  //get point of a negative index and set to null test 
	struct point *nulltest = getPoint(-1);
  //check if it is set to null
	if (nulltest == NULL) {
		return 1;
	}
  
	return 0;
}

/* Dirty Test index out of bounds
pass  - getPoint does not return 1 in the 4th value in point
fails - getPoint returns 1 in the 4th value in point 
*/
int testGetpointIndexIsnumOfPoints(){
  //construct nulltest 
  struct point *nullTest = getPoint(inputShape->numOfPoints);
  //see if nultest returns null at enry to getPoint function 
  if(nullTest == NULL){
    return 1;
  }
  
  return 0;
}

/* Clean test
pass  - getPoint does not return 1 in the 4th value in point
fails - getPoint returns 1 in the 4th value in point 
*/
int testGetpointClean(){
  int testIndex = inputShape->numOfPoints-1;
  //constuct test points and temp points 
  struct point *testpoint = malloc(sizeof(struct point));
  struct point *tempPoint = getPoint (testIndex);
  // loop through and set each element in the test point
	for (int i = 0; i < 4; i ++) {
		testpoint->element[i] = (float)1;
	}
  //set a point at index number of points -1 
  setPoint(inputShape->numOfPoints - 1, testpoint);
  //setting pointer the the get point of testIndex
  struct point *nulltest = getPoint(testIndex);
  
  free (tempPoint);

  //check if all values present are the same 
  for(int i=0; i<4;i++){
    if(nulltest->element[i] != testpoint->element[i]){
      return 0;
    }
  }
  return 1;
}



/*
  dirty test for generateXRotationMatrix
  test generates rotaion matrix with the theta being the highest possible float value +1

  pass - return 1 
  fail - return 0 if the transformation matrix is different then matrix given
 */ 
int testGenerateXRotationMatrixWhereThetaIsOverFloatMax(){ 

	float theta = FLT_MAX +1; //in radians

  // set the check matirx 
	float checkMatrix[4][4]={
		{1 , 0 , 0 , 0},
		{0 , cos(theta) , (- (sin(theta))) , 0},
		{0 , sin(theta) , cos(theta) , 0},
		{0 , 0 , 0 , 1}
	}; 

  //generate 
	generateXRotationMatrix(theta);

  //check if they host same values 
	for (int i = 0; i < 4; i++) { 
		for (int j = 0; j < 4; j++) {
			if(checkMatrix[i][j] != transformationMatrix[i][j]) {
				return 0; //failure
			}
		}
	}
  return 1; //pass
}



//run tests and print if issue arrises 
int runRotationInXTests() {

	int totalFail = 0;
																																												
	//if test failed print 																																					
	if(testGetXRotation()==0) {
		fprintf(stderr, "Get X rotation failed to get the correct theta\n");
		totalFail ++;
	}																																													
	
	//if test failed print 																																					
		if(testGetpointNegativeIndex()==0) {
		printf("Get point incorrectly gave a point using a negative index\n");
		totalFail ++;
	}																																								
	
  	//if test failed print 																																					
	if(testGetpointIndexIsnumOfPoints()==0) {
		fprintf(stderr,"Get point incorrectly gave a point using an out of bounds index\n");
		totalFail ++;
	}																																																	
	
	//if test failed print 																																					
	if(testGetpointClean()==0) {
		fprintf(stderr, "Get point returned incorrect value\n");
		totalFail ++;
	}																																																										
   
  //if test failed print 																																																																																																							
	if(testGenerateXRotationMatrixWhereThetaIsOverFloatMax()==0) {
     	fprintf(stderr, "incorrect computational input caused failure\n");
       totalFail ++;
  }																																
																																		
	return totalFail;
}
