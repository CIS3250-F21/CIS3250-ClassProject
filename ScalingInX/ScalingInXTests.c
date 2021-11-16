#include "ScalingInXTests.h"
#include "ScalingInX.h"


void runScalingInXTests(){
    zeroTransformationTest();
    noTransformationTest();
    doubleTransformationTest();
    isScaleChanged();
    transformationTest();
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
    fprintf(stderr, "ERROR: Pointer points to NULL.\n");
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

// Tests if all modified points have a 1 as their fourth element
// Expecting all elements at index 3 for each point to have the value of 1
// Fails if an element as index 3 does not equal 1
bool isPointCorrect (float **points){
  struct point *tempPoint;
  
  //Loop through all the points and assign to a tempPoint
  for (int i = 0; i < inputShape -> numOfPoints; i++){
    tempPoint = getPoint(i);

    //check if the fourth coordinate of tempPoint is equal to 1.
    if (tempPoint -> element[3] != 1) {
      fprintf(stderr, "ERROR: points[%d][3] doesn't equal 1.\n", i);
      return false;
    }
  }
  return true;
}

// Function testing for proper transformation
bool xAffected() {
  //If scale = 1, transformation matrix will not change points
  if(getXScale() == 1) {
    return false;
  }

  return true;
}


// In the event after transformation, checks if y and z coordinates are changed and if the x coordinate is changed with proper scaling
// Expecting transformation of x values with unchanged y and z values
// Fails if the y or z values do not match the y or z values prior to the transformation 
void transformationTest() {
  float newPoint[inputShape->numOfPoints][4]; 
  struct point *currentPoint;

  //Assigns the points gotten from the shape structure to the tempPoints
  for (int i = 0; i < inputShape->numOfPoints; i++) {
    currentPoint = getPoint(i);
    for (int j = 0; j < 4; j++) {
      newPoint[i][j] = currentPoint -> element[j];
    }
  }

  //run function with points and matrix 
  setXScale(3.5);
  xScaling();

  //Makes sure scaling is not 1
  if (xAffected()) {
    //loop through each point
    for(int i = 0; i < inputShape->numOfPoints; i++){
      currentPoint = getPoint(i);
      //if x values match despite scaling affecting it, it did not transform
      if(currentPoint -> element[0] == newPoint[i][0]){
          fprintf(stderr, "'TransformationTest' function failed:\n\telement at %d,0 is incorrect\n", i);
          return;
      }
      
      //if y and z values do not match after transforming only the x coordinates, it did not transform correctly
      for(int j = 1; j < 4; j++){
        //y or z values do not match after transformation
        if(currentPoint -> element[j] != newPoint[i][j]){
          printf("'TransformationTest' function failed:\n\telement at %d,%d is incorrect\n", i,j);
          return;
        }
      }
    }
  }

  resetMatrix();
}

// Testing a transformation with an x transformation factor of 0 for correct values
// Expecting the transformed points to have a x value (index of [0]) of 0 after the transformation
// Fails if the transformed points do not have x values (index of [0]) that are 0   
void zeroTransformationTest () {
  struct point *currentPoint;

  //Assign a random values to the 4 points
  for (int i = 0; i < inputShape->numOfPoints; i++) {
    currentPoint = getPoint(i); 
    for (int j = 0; j < 3; j++) {
      //puts random numbers in points 
      currentPoint -> element[j] = (float) (rand() % 100);
    }

    //Set the matrix and the points, assigning the last coordinate to one
    currentPoint -> element[3] = 1;
    setPoint (i, currentPoint);
  }

  setXScale(0);
  xScaling();

  for (int i = 0; i < inputShape->numOfPoints; i++) {
    currentPoint = getPoint(i);
    //Ensure that modified points x-value is equal to 0
    if (currentPoint -> element[0] != 0 ) {
      fprintf(stderr, "ERROR: Zero multiplication test failed: multiplying x value of point %d by 0 resulted in a non zero value\n", i);
      return;
    }
  }

  resetMatrix();
}

// Testing a transformation with an x transformation factor of 1 for correct values
// Expecting the transformed points to have the same x value (index of [0]) after the transformation
// Fails if the transformed points do not have x values (index of [0]) that are the same as the original points  
void noTransformationTest () {
  float newPoint[inputShape->numOfPoints][4]; 
  struct point *currentPoint;

  //loop through the points and set them to random values
  for (int i = 0; i < inputShape -> numOfPoints; i++) {
    currentPoint = getPoint(i);

    for (int j = 0; j < 3; j++) {
      //puts random numbers in points
      currentPoint -> element[j] = newPoint[i][j] = (float) (rand() % 100); 

    }
    //Set points (ensuring 1 is last coordinate)
    currentPoint -> element[3] = newPoint[i][3] = 1;
    setPoint (i, currentPoint);
  }
  
  setXScale(1);
  xScaling();

  //Assigns transformed points to currentPoint
  for (int i = 0; i < inputShape->numOfPoints; i++) {
    currentPoint = getPoint(i);

    //if the points before and transformations are not equal, there is an error
    if (newPoint[i][0] != currentPoint -> element[0]) {
      fprintf(stderr, "ERROR: No transformation test failed: X value of point %d multiplied by 1 gave a different result: %f.\n", i, currentPoint -> element[0]);
      return;
    }
  }

  resetMatrix();
}

// Testing a transformation with an x transformation factor of 2 for correct values
// Expecting the transformed points to have a double x value (index of [0]) after the transformation
// Fails if the transformed points do not have x values (index of [0]) that are double the original points  
void doubleTransformationTest () {
  float newPoint[inputShape->numOfPoints][4]; 
  struct point *currentPoint;
  //Assign a 0 value to the number of points

  //loop through the matrix
  for (int i = 0; i < inputShape->numOfPoints; i++) {
    currentPoint = getPoint(i);
    for (int j = 0; j < 3; j++) {
      //puts random numbers in points
      currentPoint -> element[j] = newPoint[i][j] = (float) (rand() % 100); 
    }
  
    currentPoint -> element[3] = newPoint[i][3] = 1;
    setPoint (i, currentPoint);
  }
  
  //Transforms points by a factor of 2
  setXScale(2);
  xScaling();

  //Assigns transformed points to currentPoint
  for (int i = 0; i < inputShape->numOfPoints; i++) {
    currentPoint = getPoint(i);

    //if the modified point's x coordinate's are not halved, there is an error
    if (currentPoint -> element[0] != (newPoint[i][0] * 2)) {
      fprintf(stderr, "ERROR: Double transformation test failed: X value (%f) of point %d multiplied by 2 gave a wrong result: %f.\n", newPoint[i][0], i, currentPoint -> element[0]);
      return;
    }
  }

  resetMatrix();
}

