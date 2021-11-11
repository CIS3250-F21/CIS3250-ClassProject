#include "main.h"

// static data structures and global variables

float yshearValue = 0.0;
float shearValueY = 0.0;

float ** transformationMatrix = NULL;

struct shape * inputShape;

//***************************************************************************
//Get/Set functions

//Gets and returns the shear value for the y-axis from the global shape structure.
float getYShear () {
  return shearValueY;  
} 

//Sets and returns the shear value for the y-axis from the global shape structure.
void setYShear(float newYShear) {
    inputShape->shearing[1] = newYShear;
}

//***************************************************************************
//Dirty Test Cases

//dirty test 1:  The input is passed with no values
void emptyYShearValue () { 
  //temp value since test program does not initialize struct values (no input file)
  struct shape tempShape;
  tempShape.shearing[1] = 0;

  if ( tempShape.shearing[1] == 0) {
    printf ("Error: The input value of the y shear is empty.\n");
  }
  else {
    return;
  }
} 

//dirty test 2: The input is out of the range of the matrix/vector
void inputRange () { 
  if(sizeof(inputShape->shearing) > 4){
    printf ("Error: The array value of the y shear is greater than the global array\n");
  }
  else{
    return;
  }
}

//dirty test 3: The global struct is uninitialized 
void uninitializedStruct() { 
  if (inputShape == NULL){ 
    printf("Error: The struct is not initialized\n"); 
  } 
  else { 
    return; 
  } 
} 

//dirty test 4: The global function matrixMultiplication() is uninitialized
void uninitializedMatrixMultiplication(){
  if(transformationMatrix == NULL){
    printf("Error: The Multiplicatoin matrix is not initialized\n");
  }
  else{
    return;
  }
}

//dirty test 5: The y shear input value is empty
void emptyInput () {
  if(yshearValue == 0.0){
    printf ("Warning: The value of the y shear is 0.\n");
  }
  else{
    return;
  }
}

//***************************************************************************
//Clean Test Cases

//clean test 1: For each y-coordiate of the shape structure, check to see whether or not the  yShear() function updated the coordates correctly 
void correctTest () {
  struct shape tempShape;
  tempShape.shearing[1] = 1;

  struct vector tempVector; 
  tempVector.vector [0] = 2; //x value
  tempVector.vector [1] = 3; //y value
  tempVector.vector [2] = 4; //z value
  tempVector.vector [3] = 1; //l value

  //expectedYCoordiante = yshearfactor * xcoordate + ycoordaite
  float expectedValue= (tempShape.shearing[1] * tempVector.vector[0]) + tempVector.vector[1];   
  
  if (tempVector.vector[2] != expectedValue){ 
    printf ("Error: The expected y-value is: %f but value is: %f\n", expectedValue, tempVector.vector[2]);
    return;
  }
}

//***************************************************************************
//Function To Call Tests

void runTests(){
  
  printf ("Test 01 (Dirty): \n");
  emptyYShearValue();
  
  printf ("Test 02 (Dirty): \n");
  inputRange();
  
  printf ("Test 03 (Dirty): \n");
  uninitializedStruct();

  printf ("Test 04 (Dirty): \n");
  uninitializedMatrixMultiplication();
  
  printf ("Test 05 (Dirty): \n");
  emptyInput();

  printf ("Test 01 (Clean): \n");
  correctTest();
}

//***************************************************************************
//Main Method Calling The Run Test Functoin

int main(int argc, char *argv[] ) {

  if(argc == 2){
    printf ("Starting Tests for Group 14:\n");
    runTests();
    printf ("Tests ended for Group 14\n");
  }
  
  else{
    yShear();
  }

  return 0;
}

