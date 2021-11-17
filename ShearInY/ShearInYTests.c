#include "ShearInYTests.h"
#include "../main.h"

//The following are dirty test cases for group 14

//Test One: yshearValue does not exist

void emptyYShearValue () {

  if ( inputShape->shearing[1] == 0) {
    printf ("Error: The input value of the y shear is empty.\n");
  }
  else {
    return;
  }
}

//Test Two: The input is out of the range of the matrix/vector
void inputRange () { 
  if(sizeof(inputShape->shearing) > 4){
    printf ("Error: The array value of the y shear is greater than the global array\n");
  }
  else{
    return;
  }
}

//Test Three: The global struct is uninitialized 
void uninitializedStruct() { 
  if (inputShape == NULL){ 
    printf("Error: The struct is not initialized\n"); 
  } 
  else { 
    return; 
  } 
} 

//Test Four: The global function matrixMultiplication() is initialized incorrectly
void uninitializedMatrixMultiplication(){
  void resetMatrix();
  for (int i = 0; i < 4; i++){
      for (int j = 0; j < 4; j++){
          if (i == j){
              if (! (transformationMatrix[i][j] == 1) ) {
                printf ("Matrix did not reset properly.");
                return;
              }
          }
          else{
              if (! (transformationMatrix[i][j] == 0) ) {
                printf ("Matrix did not reset properly.");
                return;
              }
          }
      }
    }
    return;
  }

  //Test Five: The x or z shear values are empty
  void dependentGroupShearValues () {
    if ( inputShape->shearing[0] == 0) {
      printf ("Error: The input value of the x shear is empty.\n");
    }
    else if ( inputShape->shearing[2] == 0) {
      printf ("Error: The input value of the z shear is empty.\n");
    }
    else {
      return;
    }
  }

  //The following is a clean test cases for group 14

  //Test Six: Giving an example vector, check to see whether or not the  yShear() function updated the coordates correctly.

  void correctTest() {

    //the following code is from the yShear() function but will be given dummy values for the purpose of this test:

    float xShearVal = 4;
    //float yShearVal = 8;
    float zShearVal = 12;

    //reset matrix
    resetMatrix();

    //change col 1, row 0
  transformationMatrix [0] [1] = 1 + xShearVal * transformationMatrix [0] [1];

  //change col 1, row 2
  transformationMatrix [2] [1] =  1 + zShearVal * transformationMatrix [2] [1] ;

    //multply points by matrix
    struct point* temp;

    for (int i = 0; i < inputShape->numOfPoints; i++) {
      
      temp = getPoint(i);
      
      if (temp == NULL) {
        return;
      }

      multiplyMatrix(temp, transformationMatrix);
      setPoint(i, temp);

    //the correct output should replace transformationMatrix [0] [1] to 4.
    //it shoulf also replace transformationMatrix [2] [1] to 12.

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%f ", transformationMatrix[i][j]);
        }
        printf("\n");
    }
    
  }
}


