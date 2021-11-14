#include "zScaling.h"

void zScaling(){

  float vectorScalingValue = getZScale();
  
  for(int x = 0; x < inputShape->numOfVectors; x++){
    float zValue;

    struct point *newVector = getVector(x);

    if (!newVector){ //checks that there is a valid vector at the index location
        fprintf(stderr, "zScaling(): ERROR: No vector at given location\n");
        return;
    }
    else{
        zValue = newVector->element[2];
        zValue *= vectorScalingValue;
        newVector->element[2] = zValue;
        setVector(x, newVector);
        
    }
  }
  return;
}
