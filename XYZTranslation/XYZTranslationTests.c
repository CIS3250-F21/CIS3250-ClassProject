#include "XYZTranslationTests.h"

//Test ensure proper function of xyzTranslation()
/*void cleanTest() {
  struct point **expected = malloc(sizeof(struct point *) * inputShape->numOfPoints);
  float x;
  float y;
  float z;

  for(int i = 0; i < inputShape->numOfPoints; i++) {
    for(int j = 0; j < 4; j++) {
      expected[i][j] = inputShape->points[i][j];
    }
  }

  x = getXTranslation();
  y = getYTranslation();
  z = getZTranslation();
  setXTranslation(0.0);
  setYTranslation(0.0);
  setZTranslation(0.0);
  xyzTranslation();
  setXTranslation(x);
  setYTranslation(y);
  setZTranslation(z);

  for(int i = 0; i < inputShape->numOfPoints; i++) {
    for(int j = 0; j < 4; j++) {
      if(expected[i]->element[j] != inputShape->points[i][j]) {
        printf("Clean Test Failed\n");
      }
    }
  }
  free(expected);
}*/

//Resulting matrix will be out of bounds unless multiplied by the points
void dirtyTestOne() {
  float x;
  float y;
  float z;

  x = getXTranslation();
  y = getYTranslation();
  z = getZTranslation();
  setXTranslation(FLT_MAX * 2);
  setYTranslation(FLT_MAX * 2);
  setZTranslation(FLT_MAX * 2);
  xyzTranslation();
  setXTranslation(x);
  setYTranslation(y);
  setZTranslation(z);
}

//Resulting matrix will be out of bounds unless multiplied by the points
void dirtyTestTwo() {
  float x;
  float y;
  float z;

  x = getXTranslation();
  y = getYTranslation();
  z = getZTranslation();
  setXTranslation(FLT_MIN * 2);
  setYTranslation(FLT_MIN * 2);
  setZTranslation(FLT_MIN * 2);
  xyzTranslation();
  setXTranslation(x);
  setYTranslation(y);
  setZTranslation(z);
}

//Testing an empty shape struct
void dirtyTestThree() {
    struct point **originalPoints = malloc(sizeof(struct point *) * inputShape->numOfPoints);

  for(int i = 0; i < inputShape->numOfPoints; i++) {
    for(int j = 0; j < 4; j++) {
      originalPoints[i][j] = inputShape->points[i][j];
    }
  }

  inputShape->points = NULL;
  xyzTranslation();

  if(inputShape->points != NULL) {
    printf("Failed dirty test 3. Should not have intialized anything\n");
  }

  for(int i = 0; i < inputShape->numOfPoints; i++) {
    for(int j = 0; j < 4; j++) {
      inputShape->points[i][j] = originalPoints[i][j];
    }
  }
  free(originalPoints);
}
