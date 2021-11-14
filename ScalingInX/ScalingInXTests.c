#include "ScalingInXTests.h"
#include "ScalingInX.h"


void runScalingInXTests(){
    zeroTransformationTest();
    noTransformationTest();
    doubleTransformationTest();
    isScaleChanged();
    transformationTest();
    bool err = emptyMatrixSet();
    if (err == true){
        fprintf(stderr, "ERROR: Matrix is empty\n");
    }
}


//Testing Functions Below

//Checks for valid index to prevent overflow
//Expecting index to be withing range of the length of the shape
//Fails if index is not within the correct bounds (0 - length)
bool validIndex (int index) {
  if (index >= 0 || index < inputShape->numOfPoints) {
    return true;
  }

  printf("Error: Invalid index");
  return false;
}

// Function testing for null pointers
// Expecting the pointer to be initialized with a value that is not NULL
// Fails is the the pointer is equal to NULL
bool isNull (void *pointer) {
  if (pointer == NULL) {
    fprintf(stderr, "ERROR: Pointer vectors to NULL.\n");
    return true; // returns error value if null
  }

  return false;
}

// Function testing for get and set scale functions
// Gets current scale value and modifies it to new Scale, setting it. 
//If the old scale and the current scale (accessed with getXScale) are
//equal, there is an error.
bool isScaleChanged(){
  float scale = getXScale();
  float newScale = scale * -1.5;
  setXScale(newScale);

  //Testing equivalency with previous scale and current one
  if (scale == getXScale()){
    return false;
  }
  return true;
}

//Function tries to assign an empty matrix to the transformation matrix.
//returns false
bool emptyMatrixSet(){
  float ** garbageMatrix;

  //assigns memory to tmpMatrix but doesn't assign values
  float ** tmpMatrix = malloc(sizeof(float *) * 4);
  for (int i = 0; i < 4; i++) {
    tmpMatrix[i] = malloc(sizeof(float) * 4);
  }

  //Gets the empty matrix
  garbageMatrix = tmpMatrix;
  //loop through matrix
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 4; j++){
      //if the matrix is not made up of all zeros, there
      //are garbage values
      if (garbageMatrix[i][j] != 0){
        //Matrix will not work
        return false;
      }
    }
  }
  //Matrix will work
  return false;
}

// Tests if all modified vectors have a 1 as their fourth element
// Expecting all elements at index 3 for each point to have the value of 1
// Fails if an element as index 3 does not equal 1
bool isPointCorrect (float **vectors){
  struct point *temppoint;
  
  //Loop through all the vectors and assign to a temppoint
  for (int i = 0; i < inputShape -> numOfPoints; i++){
    temppoint = getPoint(i);

    //check if the fourth coordinate of temppoint is equal to 1.
    if (temppoint -> element[3] != 1) {
      fprintf(stderr, "ERROR: vectors[%d][3] doesn't equal 1.\n", i);
      return false;
    }
  }
  return true;
}

// Function testing for proper transformation
bool xAffected() {
  //If scale = 1, transformation matrix will not change vectors
  if(getXScale() == 1) {
    return false;
  }

  return true;
}


// In the event after transformation, checks if y and z coordinates are changed and if the x coordinate is changed with proper scaling
// Expecting transformation of x values with unchanged y and z values
// Fails if the y or z values do not match the y or z values prior to the transformation 
void transformationTest() {
  int numOfPoints = 6;
  struct point *points[numOfPoints];
  //Creates vectors array struct as well as a double pointer float to hold the temporary vectors
  float **tempvectors = malloc(sizeof(float *) * numOfPoints);

  //gets the vectors from 
  for (int i = 0; i < numOfPoints; i++) {
    points[i] = getPoint(i); //vectors
  }

  //Assigns the vectors gotten from the shape structure to the tempvectors
  for (int i = 0; i < inputShape->numOfPoints; i++) {
    tempvectors[i] = malloc(sizeof(float) * 4);
    for (int j = 0; j < 4; j++) {
      tempvectors[i][j] = points[i] -> element[j];
    }
  }

  //run function with vectors and matrix 
  setXScale(3.5);
  xScaling();

  //update vectors after transformation
  for (int i = 0; i < inputShape->numOfPoints; i++) {
    points[i] = getPoint(i);
  }

  //Makes sure scaling is not 1
  if (xAffected()) {
    //loop through each point
    for(int i = 0; i < inputShape->numOfPoints; i++){
      //if x values match despite scaling affecting it, it did not transform
      if(points[i] -> element[0] == tempvectors[i][0]){
          fprintf(stderr, "'TransformationTest' function failed:\n\telement at %d,0 is incorrect\n", i);
          return;
      }
      
      //if y and z values do not match after transforming only the x coordinates, it did not transform correctly
      for(int j = 1; j < 4; j++){
        //y or z values do not match after transformation
        if(points[i] -> element[j] != tempvectors[i][j]){
          printf("'TransformationTest' function failed:\n\telement at %d,%d is incorrect\n", i,j);
          return;
        }
      }
    }
  }

  //Free all coordinates, vectors, and tempvectors
  for (int i = 0; i < inputShape->numOfPoints; i++) {
    free(tempvectors[i]);
  }
  free(tempvectors);
  resetMatrix();
}

// Testing a transformation with an x transformation factor of 0 for correct values
// Expecting the transformed vectors to have a x value (index of [0]) of 0 after the transformation
// Fails if the transformed vectors do not have x values (index of [0]) that are 0   
void zeroTransformationTest () {
  struct point *newPoint[4];

  //Assign a random values to the 4 vectors
  for (int i = 0; i < inputShape->numOfPoints; i++) {
    newPoint[i] = getPoint(i); // first 4 points
    for (int j = 0; j < 3; j++) {
      //puts random numbers in vectors 
      newPoint[i] -> element[j] = (float) (rand() % 100);
    }

    //Set the matrix and the vectors, assigning the last coordinate to one
    newPoint[i] -> element[3] = 1;
    setPoint (i, newPoint[i]);
  }

  setXScale(0);
  xScaling();

  for (int i = 0; i < inputShape->numOfPoints; i++) {
    newPoint[i] = getPoint(i);
    //Ensure that modified vectors x-value is equal to 0
    if (newPoint[i] -> element[0] != 0 ) {
      fprintf(stderr, "ERROR: Zero multiplication test failed: multiplying x value of point %d by 0 resulted in a non zero value\n", i);
      return;
    }
  }

  resetMatrix();
}

// Testing a transformation with an x transformation factor of 1 for correct values
// Expecting the transformed vectors to have the same x value (index of [0]) after the transformation
// Fails if the transformed vectors do not have x values (index of [0]) that are the same as the original vectors  
void noTransformationTest () {
  float **matrix = malloc(sizeof (float *) * 4);
  struct point *newPoint[4], *currentpoint;
  //Assign a 0 value to the number of vectors
  //initializeLength();

  //loop through the matrix
  for (int i = 0; i < 4; i++) {
    matrix[i] = malloc(sizeof(float) * 4);

    for (int j = 0; j < 4; j++) {
      //puts random numbers in vectors
      newPoint[i] -> element[j] = (float) (rand() % 100); 
    }
    //Set vectors (ensuring 1 is last coordinate)
    newPoint[i] -> element[3] = 1;
    setPoint (i, newPoint[i]);
  }
  
  setXScale(1);
  xScaling();

  //Assigns transformed vectors to currentpoint
  for (int i = 0; i < inputShape->numOfPoints; i++) {
    currentpoint = getPoint(i);

    //if the vectors before and transformations are not equal, there is an error
    if (newPoint[i] -> element[0] != currentpoint -> element[0]) {
      fprintf(stderr, "ERROR: No transformation test failed: X value of point %d multiplied by 1 gave a different result: %f.\n", i, currentpoint -> element[0]);
      return;
    }
  }

  resetMatrix();
}

// Testing a transformation with an x transformation factor of 2 for correct values
// Expecting the transformed vectors to have a double x value (index of [0]) after the transformation
// Fails if the transformed vectors do not have x values (index of [0]) that are double the original vectors  
void doubleTransformationTest () {
  float **matrix = malloc(sizeof (float *) * 4);
  struct point *newPoint[4], *currentpoint;
  //Assign a 0 value to the number of vectors
  //initializeLength();
  //loop through the matrix
  for (int i = 0; i < 4; i++) {
    matrix[i] = malloc(sizeof(float) * 4);

    for (int j = 0; j < 4; j++) {
      //puts random numbers in vectors
      newPoint[i] -> element[j] = (float) (rand() % 100); 
    }

    // Sets point and matrix
    // setMatrix(matrix);
    newPoint[i] -> element[3] = 1;
    setPoint (i, newPoint[i]);
  }
  
  //Transforms vectors by a factor of 2
  setXScale(2);
  xScaling();

  //Assigns transformed vectors to currentpoint
  for (int i = 0; i < inputShape->numOfPoints; i++) {
    currentpoint = getPoint(i);

    //if the modified point's x coordinate's are not halved, there is an error
    if (newPoint[i] -> element[0] != currentpoint -> element[0] * 0.5) {
      fprintf(stderr, "ERROR: Double transformation test failed: X value (%f) of point %d multiplied by 2 gave a wrong result: %f.\n", newPoint[i] -> element[0], i, currentpoint -> element[0]);
      return;
    }
  }

  resetMatrix();
}

