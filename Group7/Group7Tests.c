//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//~~~~~~~~~~~~~ Group 7 ~~~~~~~~~~~~~~~//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//~~~~ Eric Morse (1141504)        ~~~~//
//~~~~ Cavaari Taylor (1159034)    ~~~~//
//~~~~ Andrew Linington (1060878)  ~~~~//
//~~~~ Syed Ahmed (1135518)        ~~~~//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

#include "Group7Tests.h"


// ~~~~~~~~~~~~~~~~~~~~~~~~ Tests ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
// ~~~~~~ Get Vector Tests ~~~~~~ //
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

int compareFloat (float x, float y, float acceptedDistance) {
    float difference = fabs(x - y);
    if (difference > acceptedDistance) {
        return 1;
    }
    return 0;
}




// Dirty Test
//Tests if Get Vector handles negative index values
int testGetVectorReturnsNullWhenIndexIsNeagtive () {
    return getVector(-1) == NULL;
}

// Dirty Test
// Tests When the value of the index exceeds the max length 
int testGetVectorReturnsNullWhenIndexIsGreaterThanLength () {
    return getVector(inputShape->numOfVectors) == NULL;
}

//Clean Test
// Tests when getting the value it matches the expected value
int testGetVectorReturnsMatchingVector () {
    struct vector * testVector = inputShape->vectors[0];
    return testVector == getVector(0); 
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
// ~~~~~~ Set Vector Tests ~~~~~~ //
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

// Clean Test
// Tests When a vector is added that the vector is stored in the global shape object
int testSetVectorIfVectorAddedAtIndex() {
    // create null ptr to vector
    struct vector *newVector = malloc(sizeof(struct vector));
    int index = 1;

    // fill vector
    for (int i = 0; i < 4; i ++) {
      newVector->vector[i] = (float)1;
    }
    
    // store current vector
    struct vector *tempVector = getVector(index);

    // set vector
    setVector(index, newVector);
    
    // check if new vector is added
    if (inputShape->vectors[1] == newVector) {
      free(newVector);

      // put original vector back
      setVector(index, tempVector);

      return 1;
    }

    // put original vector back
    inputShape->vectors[1] = tempVector;

    // free
    free(newVector);
    return 0;
}


// Dirty Test
// Tests when a vector is added out of range (negative) that code does not crash
int testSetVectorReturn0WhenIndexIsNegative() {
    // index and vector
    struct vector *newVector = malloc(sizeof(struct vector));
    int index = -1;
    
    // fill vector
    for (int i = 0; i < 4; i ++) {
      newVector->vector[i] = (float)1;
    }

    // store current vector
    // getVector(index);


    // set vector
    setVector(index, newVector);
    
    free(newVector);
    return 1;
}


// Dirty Test
// Tests when a vector is added out of range that code does not crash
int testSetVectorReturn0WhenIndexIsGreaterThenLength() {
    // index and vector
    struct vector *newVector = malloc(sizeof(struct vector));
    int index = inputShape->numOfVectors;
    
    // fill vector
    for (int i = 0; i < 4; i ++) {
      newVector->vector[i] = (float)1;
    }
    
    // set vector
    setVector(index, newVector);

    free(newVector);
    
    return 1;
    
}


// Dirty Test
// Tests whether setVector can handle a struct vector pointer pointing to null when passed in, or if it crashes.
int testSetVectorReturn0IfVectorIsNull() {
    // index and vector
    struct vector *newVector = NULL;
    int index = 1;
    
    // set vector
    setVector(index, newVector);
    
    return 1;
}




// getYRotation Tests
// will test if get y rotation works.
int testGetYRotation() {
  inputShape->rotation[1] = 10;
  
  if (getYRotation() == 10) {
    return 1;
  }
  
  return 0;
}

// setYRotation Tests
// will test if set y rotation works.
int testSetYRotationWhenAngleIsValid() {
  setYRotation(10);

  if (inputShape->rotation[1] == 10) {
    return 1;
  }

  return 0;
}


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
// ~~~~~~ generateYRotationMatrix Tests ~~~~~~ //
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //



// Will test generate Y rotation matrix when the matrix was null before running the func.
int testGenerateYRotationMatrixWhenTransformationMatrixIsNull() {
  float ** oldMatrix = transformationMatrix;
  float theta = 0;
  
  // set the matrix to null
  transformationMatrix = NULL;
  // test generate
  generateYRotationMatrix(theta);

  // set the matrix back
  transformationMatrix = oldMatrix;

  // return 1 because it didn't crash. yay!
  return 1;
}

// Will test generate y rotaion matrix when some of the elements are null before running the func.
int testGenerateYRotationMatrixWhenElementOfTransformationMatrixIsNull() {
  float oldMatrix[4][4];
  float theta = 0;
  
  // copy the matrix to save it for later
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      oldMatrix[i][j] = transformationMatrix[i][j];
    }
  }
  
  // preserve column 2 so we don't segfault later
  float * col2 = transformationMatrix[2];
  
  // set a column to null then test the program, the revert the column back
  transformationMatrix[2] = NULL;
  generateYRotationMatrix(theta);
  transformationMatrix[2] = col2;

  // loop through the matrices
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      // if something has changed, return 0
      if (transformationMatrix[i][j] != oldMatrix[i][j]) {
        return 0;
      }
    }
  }

  return 1;
}

// Will test generate y rotaiton matrix with theta 0.
int testGenerateYRotationMatrixWhenAngleIs0() {
  float theta = 0;
  // generate the matrix
  generateYRotationMatrix(theta);
  // set the expected matrix
  float expectedMatrix[4][4] = {
    cos(theta), 0, sin(theta), 0, 
    0, 1, 0, 0,
    -sin(theta), 0, cos(theta), 0,
    0, 0, 0, 1 };
  
  // loop through the matrices
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      // is something doesn't match return 0
      if (expectedMatrix[i][j] != transformationMatrix[i][j]) {
        return 0;
      }
    }
  }

  return 1;
}

// Will test gnereate y rotaiton matrix when theta -10.
int testGenerateYRotationMatrixWhenAngleIsNegative(){
  float theta = -10;
  //generate the matrix
  generateYRotationMatrix(theta);

  // set the expected matrix
  float expectedMatrix[4][4] = {
    cos(theta), 0, sin(theta), 0, 
    0, 1, 0, 0,
    -sin(theta), 0, cos(theta), 0,
    0, 0, 0, 1 };
  
  // loop through the matrices
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      // if something isn't matching, return 0
      if (expectedMatrix[i][j] != transformationMatrix[i][j]) {
        return 0;
      }
    }
  }
  return 1;
}

// Will test gerneate y roataiton matrix with a positive angle, or 10.6 in this case.
int testGenerateYRotationMatrixWhenAngleIsPositiveGreaterThanTwoPi(){
  float theta = (2*3.14156942)*1.69;
  //generate the rotation matrix
  generateYRotationMatrix(theta);

  // set the expected matrix
  float expectedMatrix[4][4] = {
    cos(theta), 0, sin(theta), 0, 
    0, 1, 0, 0,
    -sin(theta), 0, cos(theta), 0,
    0, 0, 0, 1 };
  
  // loop through the matrices
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      // if something doesn't match return 0
      if (expectedMatrix[i][j] != transformationMatrix[i][j]) {
        return 0;
      }
    }
  }
  return 1;
}


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
// ~~~ Matrix Multiplication ~~~ //
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

// Dirty Test

// This tests check whether the function vector is NULL
int testMatrixMultiplicationWhenVectorIsNull(){
    struct vector * tempVector = NULL;
    
    multiplyMatrix(tempVector, transformationMatrix);

    return 1;
}

//Clean Test

// This function tests whether the vector is valid by looping through the //matrix
int testMatrixMultiplicationWhenVectorIsValid() {
    struct vector * tempVector = malloc(sizeof(struct vector));

    //set transform here
    float theta = 10;
		//loop through the matrix
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        transformationMatrix[i][j] = 0;
      } 
		}
		//set transformation matrix equal to identity matrix
    for( int i = 0; i < 4; i++) {
      transformationMatrix[i][i] = i;
    }
    
		//set tempVector to to point to current vector
    for(int i = 0; i < 4; i++ ) {
      tempVector->vector[i] = (float)1;
    }
    
		multiplyMatrix(tempVector, transformationMatrix);

		//loops through and free tempVector
    for(int i = 0; i < 4; i++) {
      if(tempVector->vector[i] != i) {
          free(tempVector);
          return 0;
      }
    }
  
    free(tempVector);
    return 1;
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
// ~~~~~~ YRotation Tests ~~~~~~ //
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //


//Clean Test
//Tests all vectors in the shape strucure such that they are rotated by 0 radians around Y
int testYRotationWhenAngleIs0() {
  struct vector ** expected = malloc(sizeof(struct vector *) * 5);

  //instantiating the expected result
  for(int i = 0; i < 5; i++) {
    expected[i] = malloc(sizeof(struct vector));
    for(int j = 0; j < 3; j++) {
      expected[i]->vector[j] = j + i;
    }
    expected[i]->vector[3] = 1;
  }

  yRotation();

  for(int i = 0; i < inputShape->numOfVectors; i++) {
    for (int j = 0; j < 4; j++) {
        if(expected[i]->vector[j] != inputShape->vectors[i]->vector[j]) {
          for (int i = 0; i < 5; i++){
            free(expected[i]);
          }
          free(expected);
          return 0;
        }
    }
  }

  for (int i = 0; i < 5; i++){
    free(expected[i]);
  }
  free(expected);
  return 1;

}

//Dirty Test
//Tests all vectors in the shape strucure such that they are rotated by -PI/2 radians around Y properly for the negative angle
int testYRotationWhenAngleIsNegative() {
  struct vector ** expected = malloc(sizeof(struct vector *) * 5);
  inputShape->rotation[1]  = (-(0.5)*3.14159265359) ;

  //instantiating the expected result
   for(int i = 0; i < 5; i++) {
    expected[i] = malloc(sizeof(struct vector));
    expected[i]->vector[0] =  (i + 2) * -sin(inputShape->rotation[1]);
    expected[i]->vector[1] =  1 + i;
    expected[i]->vector[2] = (i) * sin(inputShape->rotation[1]);
    expected[i]->vector[3] = 1;
  }

  yRotation();

  //seing if the results match
  for(int i = 0; i < inputShape->numOfVectors; i++) {
    for (int j = 0; j < 4; j++) {
        if(compareFloat(expected[i]->vector[j],inputShape->vectors[i]->vector[j] , 0.000001)) {
          for (int i = 0; i < 5; i++){
            free(expected[i]);
          }
          free(expected);
          return 0;
        }
    }
  }

  for (int i = 0; i < 5; i++){
    free(expected[i]);
  }
  free(expected);
  return 1;
}

//Dirty Test
//Tests all vectors in the shape strucure such that they are rotated by (5 * PI)/2 radians around Y properly for the large angle
int testYRotationWhenAngleIsPositiveGreaterThanTwoPi() {
  struct vector ** expected = malloc(sizeof(struct vector *) * 5);
  inputShape->rotation[1]  = ((2.5)*3.14159265359) ;

  //instantiating the expected result
  for(int i = 0; i < 5; i++) {
    expected[i] = malloc(sizeof(struct vector));
    expected[i]->vector[0] =  (i + 2) * -sin(inputShape->rotation[1]);
    expected[i]->vector[1] =  1 + i;
    expected[i]->vector[2] = (i) * sin(inputShape->rotation[1]);
    expected[i]->vector[3] = 1;
  }

  yRotation();

  //seeing if the results match
  for(int i = 0; i < inputShape->numOfVectors; i++) {
    for (int j = 0; j < 4; j++) {
        if(compareFloat(expected[i]->vector[j],inputShape->vectors[i]->vector[j] , 0.000001)) {
          for (int i = 0; i < 5; i++){
            free(expected[i]);
          }
          free(expected);
          return 0;
        }
    }
  }

  for (int i = 0; i < 5; i++){
    free(expected[i]);
  }
  free(expected);
  return 1;
}

//Dirty Test
//Tests when a Null Matrix is found that nothing is changed for the vectors
int testYRotationHandlesNullMatrix() {
  float ** temp = transformationMatrix;
  transformationMatrix = NULL;
  struct vector ** expected = malloc(sizeof(struct vector *) * 5);
  inputShape->rotation[1] = 0;

  //instantiating the expected result
  for(int i = 0; i < 5; i++) {
    expected[i] = malloc(sizeof(struct vector));
    for(int j = 0; j < 3; j++) {
      expected[i]->vector[j] = j + i;
    }
    expected[i]->vector[3] = 1;
  }

  yRotation();

  transformationMatrix = temp;
  for(int i = 0; i < inputShape->numOfVectors; i++) {
    for (int j = 0; j < 4; j++) {
        if(compareFloat(expected[i]->vector[j],inputShape->vectors[i]->vector[j] , 0.000001)) {
          for (int i = 0; i < 5; i++){
            free(expected[i]);
          }
          free(expected);
          return 0;
        }
    }
  }

  for (int i = 0; i < 5; i++){
    free(expected[i]);
  }
  free(expected);
  return 1;
}

//Dirty Test
//Tests when a Null Element of a Matrix is found that nothing is changed for the vectors
int testYRotationHandlesNullElementOfMatrix() {
  float * temp = transformationMatrix[0];
  transformationMatrix[0] = NULL;
  struct vector ** expected = malloc(sizeof(struct vector *) * 5);
  inputShape->rotation[1] = 0;

  //instantiating the expected result
  for(int i = 0; i < 5; i++) {
    expected[i] = malloc(sizeof(struct vector));
    for(int j = 0; j < 3; j++) {
      expected[i]->vector[j] = j + i;
    }
    expected[i]->vector[3] = 1;
  }

  yRotation();

  transformationMatrix[0] = temp;
  for(int i = 0; i < inputShape->numOfVectors; i++) {
    for (int j = 0; j < 4; j++) {
        if(compareFloat(expected[i]->vector[j],inputShape->vectors[i]->vector[j] , 0.000001)) {
          for (int i = 0; i < 5; i++){
            free(expected[i]);
          }
          free(expected);
          return 0;
        }
    }
  }

  for (int i = 0; i < 5; i++){
    free(expected[i]);
  }
  free(expected);
  return 1;
}

//Dirty Test
//Tests when a Null Matrix is found that nothing is changed for the vectors after the Null
int testYRotationHandlesNullVector() {
  struct vector * temp = inputShape->vectors[1];
  inputShape->vectors[1] = NULL;
  struct vector ** expected = malloc(sizeof(struct vector *) * 5);
  inputShape->rotation[1]  = ((0.5 )*3.14159265359);

  //instantiating the expected result
  for(int i = 0; i < 5; i++) {
    expected[i] = malloc(sizeof(struct vector));
    for(int j = 0; j < 3; j++) {
      expected[i]->vector[j] = j + i;
    }
    expected[i]->vector[3] = 1;
  }
  //only alters the first one given a vector is NULL
  expected[0]->vector[0] = -2;
  expected[0]->vector[2] = 0;

  yRotation();

  inputShape->vectors[1] = temp;
  for(int i = 0; i < inputShape->numOfVectors; i++) {
    for (int j = 0; j < 4; j++) {
        if(compareFloat(expected[i]->vector[j],inputShape->vectors[i]->vector[j] , 0.000001)) {
          printf("%d %d %f %f\n", i,j, expected[i]->vector[j], inputShape->vectors[i]->vector[j] );
          for (int i = 0; i < 5; i++){
            free(expected[i]);
          }
          free(expected);
          return 0;
        }
    }
  }

  for (int i = 0; i < 5; i++){
    free(expected[i]);
  }
  free(expected);
  return 1;
}

//Dirty
//Tests when all vectors are Null that nothing changes foir the value
int testYRotationHandlesNullVectors() {
  struct vector ** temp = inputShape->vectors;
  inputShape->vectors = NULL;
  inputShape->rotation[1]  = ((0.5)*3.14159265359);

  yRotation();

  if(inputShape->vectors == NULL) {
    inputShape->vectors = temp;
    return 1;
  }
  inputShape->vectors = temp;
  return 0;
}


// ~~~~~~~~~~~~~~~~~~~~~~~~~ //
// ~~~~~~ Other Funcs ~~~~~~ //
// ~~~~~~~~~~~~~~~~~~~~~~~~~ //
void setup () {
  inputShape->numOfVectors = 5;
  inputShape->rotation[1] = 0;

  for(int i = 0; i < 5; i++ ) {
    for(int j = 0; j < 3; j++){
      inputShape->vectors[i]->vector[j] = j + i;
    } 
    inputShape->vectors[i]->vector[3] = 1;
  }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      transformationMatrix[i][j] = i + j;
    }
  }
}

void group7TestHandler(int (*test)(), char *testString) {

  //fixes any values that may have been changed from previous test
  setup();

  if (!test()) {
    printf("%s failed\n", testString);
  }
}

void runGroup7Tests () {
  // getVector Tests //
  
  //Dirty Tests
  group7TestHandler(testGetVectorReturnsNullWhenIndexIsNeagtive, "Test Get Vector Returns Null When Index Is Negative");

  group7TestHandler(testGetVectorReturnsNullWhenIndexIsGreaterThanLength, "Test Get Vector Returns Null When Index Is Greater Then Length");


  // Clean Tests
  group7TestHandler(testGetVectorReturnsMatchingVector, "Test Get Vector Returns Matching Vector ");


  // setVector Tests //

  // Dirty Tests 
  group7TestHandler(testSetVectorReturn0WhenIndexIsNegative, "Test Set Vector If Returns 0 When Index Negative.");

  group7TestHandler(testSetVectorReturn0WhenIndexIsGreaterThenLength, "Test Set Vector If Returns 0 When Index Greater Than Length.");

  group7TestHandler(testSetVectorReturn0IfVectorIsNull, "Test Set Vector If Returns 0 When Vector is Null");

  // Clean Tests
  group7TestHandler(testSetVectorIfVectorAddedAtIndex, "Test Set Vector If Vector Added At Index");


  // getYRotation Tests //
  
  group7TestHandler(testGetYRotation, "Test Get Y Rotation");

  //setYRotation Tests
  group7TestHandler(testSetYRotationWhenAngleIsValid, "Test Set Y Rotation When Angle Is valid");

  // generateYRotationMatrix tests
  group7TestHandler(testGenerateYRotationMatrixWhenTransformationMatrixIsNull, "Test Generate Y Rotation Matrix When Transformation Matrix is Null");
  
  group7TestHandler(testGenerateYRotationMatrixWhenElementOfTransformationMatrixIsNull, "Test Generate Y Rotation Matrix When Element Of Transformation Matrix Is Null");

  group7TestHandler(testGenerateYRotationMatrixWhenElementOfTransformationMatrixIsNull, "Test Generate Y Rotation Matrix When Element Of Transformation Matrix Is Null");

  group7TestHandler(testGenerateYRotationMatrixWhenAngleIs0, "Test Generate Y Rotation Matrix When Angle Is 0");

  group7TestHandler(testGenerateYRotationMatrixWhenAngleIsNegative, "Test Generate Y Rotation Matrix When Angle Is Negative");

  group7TestHandler(testGenerateYRotationMatrixWhenAngleIsPositiveGreaterThanTwoPi, "Test Generate Y Rotation Matrix When Angle Is Positive Greater Then Two Pi");


	// Matrix Multiplication Tests //
	
	// Dirty tests
	group7TestHandler(testMatrixMultiplicationWhenVectorIsNull, "Test Matrix Multiplication To Check For NULL Vector ");
	
	// Clean tests
	group7TestHandler(testMatrixMultiplicationWhenVectorIsValid, "Test Matrix Multiplication Vectors Are Valid ");

	// Dirty YRotation Tests
  group7TestHandler(testYRotationHandlesNullVectors, "Test Y Rotation Handles Null Vectors ");
  
  group7TestHandler(testYRotationHandlesNullVector, "Test Y Rotation Handles Null Vector ");
  
  group7TestHandler(testYRotationHandlesNullMatrix, "Test Y Rotation Handles Null Matrix ");
  
  group7TestHandler(testYRotationHandlesNullElementOfMatrix, "Test Y Rotation Handles Null Element Of Matrix ");
  
  group7TestHandler(testYRotationWhenAngleIsPositiveGreaterThanTwoPi, "Test Y Rotation When Angle Is Positive Greater Than Two Pi ");
  
  group7TestHandler(testYRotationWhenAngleIsNegative, "Test Y Rotation When Angle Is Negative ");
  
  // Clean YRotation Tests
  group7TestHandler(testYRotationWhenAngleIs0, "Test Y Rotation When Angle Is 0 ");

}
