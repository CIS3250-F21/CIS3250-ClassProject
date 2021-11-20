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

/* setPoint Testing */

// /* Dirty test, index is negative
// pass - return 1, setPoint sets the error point at index
// fail - return 0, setPoint does not set the error point at index 
// */  
// int testSetpointifIndexIsNeg() {
//     struct point *testpoint = malloc (sizeof (struct point)); 
//     int index = -1;
//     for (int i = 0; i < 4; i ++) {
//       testpoint->element[i] = (float)1;
//     }
//     setPoint(index, testpoint);

// 		if (testpoint == NULL) {
//       free (testpoint);
// 			return 1;
// 		}

//     free (testpoint);
//     return 0;
// }


// /* Dirty test, index is too big
// pass - return 1, setPoint sets the error point at index
// fail - return 0, setPoint does not set the error point at index 
// */   
// int testSetpointIndexIsnumOfPoints() {
//     struct point *testpoint =malloc(sizeof(struct point)) ; 
//     int index = inputShape->numOfPoints;
//     for (int i = 0; i < 4; i ++) {
//       testpoint->element[i] = (float)1;
//     }

//     setPoint(index, testpoint);
    
//     if (testpoint ==NULL) {
//         free(testpoint);
//         return 1;
//     }

//     free(testpoint);
//     return 0;
// }

// /* Dirty test, point is unintialized
// pass - return 1, setPoint sets the error point at index
// fail - return 0, setPoint does not set the error point at index 
// */  
// int testSetpointIfpointIsUninitialized() {
//     struct point *testpoint =malloc(sizeof(struct point)) ; 
//     int index = inputShape->numOfPoints -1;
        
//     setPoint(index, testpoint);
    
//     if (testpoint ==NULL) {
//         free(testpoint);
//         return 1;
//     }

//     free(testpoint);
//     return 0;
// }  

// /* Clean test
// pass - return 1, testpoint is set correctly
// fail - return 0, testpoint is not set correctly
// */
// int testSetpointIsDefinedAndIndexIsPositiveExNumofpoint() {
//     struct point testpoint;
// 	for (int i = 0; i < 4; i ++) {
// 		testpoint.element[i] = (float)1;
// 	} 

//   int testIndex = inputShape->numOfPoints -1;
//   setPoint(testIndex, &testpoint);
//   struct point *checkpoint = getPoint(testIndex);

//   for (int i = 0; i < 4; i++) {
//         if(checkpoint->element[i] != testpoint.element[i]) {
//             return 0; //failure
//         }
//     }   
//     return 1;
// }


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

// testing for generateXRotation

/*
  clean test for generateXRotationMatrix
  test generates rotaion matrix with a negative theta 
  the negative theta should not impact the test in any way as 
  sin and cos will be applied regardless of the negative 

  pass - return 1
  fail - return 0 if the transformation matrix is different then the matrix given
 */
// int testGenerateXRotationClean(){ 
//     struct point **expected = malloc(sizeof(struct point *) * 5);

//     // instantiating the expected result
//     for (int i = 0; i < 5; i++) {
//         expected[i] = malloc(sizeof(struct point));
//         for (int j = 0; j < 3; j++) {
//             expected[i]->element[j] = j + i;
//         }
//         expected[i]->element[3] = 1;
//     }

//     xRotation();

//     for (int i = 0; i < inputShape->numOfPoints; i++) {
//         for (int j = 0; j < 4; j++) {
//             if (expected[i]->element[j] != inputShape->points[i]->element[j]) {
//                 for (int i = 0; i < 5; i++) {
//                     free(expected[i]);
//                 }
//                 free(expected);
//                 return 0;
//             }
//         }
//     }

//     for (int i = 0; i < 5; i++) {
//         free(expected[i]);
//     }
// 	return 1;
// }

/*
  dirty test for generateXRotationMatrix
  test generates rotaion matrix with the parameter theta declared but unintialized

  pass - return 1
  fail - return 0 if the transformation matrix is different than checkMatrix
 */
// int testGenerateXRotationUninitializedTheta(){ 

// 	float *theta = malloc (sizeof (float)); //in radians

// 	float checkMatrix[4][4]={
// 		{1 , 0 , 0 , 0},
// 		{0 , cos(*theta) , (- (sin(*theta))) , 0},
// 		{0 , sin(*theta) , cos(*theta) , 0},
// 		{0 , 0 , 0 , 1}
// 	}; 

// 	generateXRotationMatrix(*theta);

// 	for (int i = 0; i < 4; i++) { //check if they host same values 
// 		for (int j = 0; j < 4; j++) {
// 			if(checkMatrix[i][j] != transformationMatrix[i][j]) {
			
// 				return 0; //failure
// 			}
// 		}
// 	}
//   return 1; //pass
// }

/*
  dirty test for generateXRotationMatrix
  test generates rotaion matrix with the transformMatrix being NULL

  pass - 1 is returned if testGenerateXRotationClean still passes
  fail - 0 is returned if testGenerateXRotationClean fails
 
int testGenerateXRotationWhenMatrixIsNULL(){

  void *nullValues = malloc(sizeof(float));

  transformationMatrix[0] = NULL;
  transformationMatrix[1] = nullValues;
  transformationMatrix[2] = nullValues;
  transformationMatrix[3] = nullValues;

	if (testGenerateXRotationClean()) {
		return 1;
	}
	else {
		
		return 0;
	}
}
*/

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

/* xRotation tests */


/* Dirty test shape uninitialized
pass - return 1, xRotate sets transformMatrix to all 0s to indicate error
fail - return 0, transformMatrix is not all 0s
*/
// int testXRotationMatrixWhenRotationIsNULL(){ 

// 	struct shape currShapeCpy = *inputShape;

// 	struct shape *testShape;
// 	testShape.points = currShapeCpy.points;

// 	inputShape = &testShape;

// 	int result = xRotation();

// 	if (result == -1) {
// 		return 1;
// 	}
// 	else {
// 		return 0;
// 	}
	
// 	shape = currShapeCpy;
// }


/* Dirty test input matrix only 3x4
pass - return 1, xRotate sets transformMatrix to all 0s to indicate error
fail - return 0, transformMatrix is not all 0s
*/
// int testXRotationInputMatrix3x4(){ 

// 	struct shape *currShapeCpy = malloc (sizeof (struct shape));

//   struct shape* FREEME = inputShape;

//   *currShapeCpy = *inputShape;

// 	struct shape *testShape = malloc (sizeof (struct shape));

// 	testShape->numOfPoints = 3;

// 	testShape->points = malloc (sizeof (struct point*) * 3);

//   for (int i = 0; i < 4; i ++) {
//     testShape->rotation[i] = inputShape->rotation[i];
//   }

// 	for (int i = 0; i < 3; i++) {
// 		testShape->points[i] = malloc (sizeof (struct point));
// 		for (int j = 0; j < 2; j++) {
// 			testShape->points[i]->element[j] = j;
// 		}
// 		testShape->points[i]->element[2] = 1;
// 	}

// 	inputShape = testShape;
// 	int result = xRotation();

// 	for (int i = 0; i < 3; i++) {
// 		free (testShape->points[i]);
// 	}

// 	free (testShape->points);
//   free (testShape);
//   free (FREEME);

//   inputShape = currShapeCpy;

// 	if (result == -1) {
// 		return 1;
// 	}
// 	else {
// 		return 0;
// 	}

// }


// /* Dirty test incorrect numOfPoints given
// pass - return 1, xRotate sets transformMatrix to all 0s to indicate error
// fail - return 0, transformMatrix is not all 0s
// */
// int testXRotationIncorrectnumOfPoints(){ 

// 	int currnumOfPoints = inputShape->numOfPoints;

// 	inputShape->numOfPoints++;

// 	int result = xRotation();
// 	inputShape->numOfPoints = currnumOfPoints;

// 	if (result == -1) {
// 		return 1;
// 	}
// 	else {
//   	return 0;
// 	}

// }


/* Clean Test
pass - return 1, transformMatrix is equal to expected result
fail - return 0, transformMatrix is not equal to expected result
*/
// int testXRotationClean() {

//   // allocating space for expected point
//   struct point ** expected = malloc(sizeof(struct point *) * 5);

//   //for loop that created expected and sets values 
//   for(int i = 0; i < 5; i++) {
//     expected[i] = malloc(sizeof(struct point));
//     for(int j = 0; j < 3; j++) {
//       expected[i]->element[j] = j + i;
//     }
//     expected[i]->element[3] = 1;
//   }

//   xRotation();

//   //for loop for setting expected 
//   for(int i = 0; i < inputShape->numOfPoints; i++) {
//     for (int j = 0; j < 4; j++) {
//         if(expected[i]->element[j] != inputShape->points[i]->element[j]) {
//           for (int i = 0; i < 5; i++){
//             free(expected[i]);
//           }
//           free(expected);
					
//           return 0;
//         }
//     }
//   }

//   //for loop to free 
//   for (int i = 0; i < 5; i++){

//     free(expected[i]);
//   }
//   free(expected);
//   return 1;
// } 

//run tests and print if issue arrises 
int runRotationInXTests() {

	int totalFail = 0;

  // if(testSetXRotationWithValidTheta() ==0) {
  //     fprintf(stderr, "Set X rotation failed to set the correct theta\n");
  //     totalFail ++;
  // }
		                                                        
	// if(testSetpointifIndexIsNeg() == 0) { 
  //   fprintf(stderr, "Set point failed to set error point\n"); 
  //   totalFail ++;
  // }					

	// if(testSetpointIndexIsnumOfPoints()==0) {
  //   fprintf(stderr, "Set point failed to set error point\n"); 
  //   totalFail ++;
  // }																										

  // if(testSetpointIfpointIsUninitialized()==0) {
  //   fprintf(stderr, "Set point failed to set error point\n"); 
  //   totalFail ++;
  // }	
																																														
	
  // if(testSetpointIsDefinedAndIndexIsPositiveExNumofpoint()==0) { 
  //   fprintf(stderr,"Incorrect computation of generate x rotation matrix\n");
  //   totalFail ++;
  // }	
																																												
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
	// if(testGenerateXRotationClean()==0) {
	// 	fprintf(stderr,"Incorrect computation of generate x rotation matrix\n");
	// 	totalFail ++;
	// }	
																																				
	

	// if(testGenerateXRotationUninitializedTheta()==0) {
  //      fprintf(stderr, "incorrect computational input caused failure\n");
  //      totalFail ++;
  // }																				
																																														
	
	// if(testGenerateXRotationWhenMatrixIsNULL()==0) {
  //      fprintf(stderr, "generateXRotationMatrix fails with NULL transformationMatrix\n");
  //      totalFail ++;
  // }	
   
  //if test failed print 																																																																																																							
	if(testGenerateXRotationMatrixWhereThetaIsOverFloatMax()==0) {
     	fprintf(stderr, "incorrect computational input caused failure\n");
       totalFail ++;
  }																																
													
  // if(testXRotationMatrixWhenRotationIsNULL()==0) {
  //    	fprintf(stderr, "null rotaion in rotaion matrix caused failure\n");
  //      totalFail ++;
  // }		
																																		
  // if(testXRotationInputMatrix3x4()==0) {
  //    	fprintf(stderr, "incorrect input matrix caused failure\n");
  //     totalFail++;
  // }

	// if(testXRotationIncorrectnumOfPoints()==0) {
  //    	fprintf(stderr, "incorrect number of points across the matrix caused failure\n");
  //      totalFail ++;
  // }																																				

  //if test failed print 																																					
// 	if(testXRotationClean()==0) {
//      	fprintf(stderr, "xRotation did not give expected output during clean test\n");
//        totalFail ++;
//   }																																
	return totalFail;
}
