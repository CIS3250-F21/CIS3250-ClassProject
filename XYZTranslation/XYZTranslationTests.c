#include "XYZTranslationTests.h"

// Run tests
void runXYZTranslationTests() {
  XYZTranslationLargeValueOutOfBounds();
  XYZTranslationSmallValueOutOfBounds();

}

// Resulting matrix will be out of bounds unless multiplied by the points and produce logical error caught by the program
void XYZTranslationLargeValueOutOfBounds() {
  float x;
  float y;
  float z;

  x = getXTranslation();
  y = getYTranslation();
  z = getZTranslation();

  setXTranslation(FLT_MAX * 2);
  setYTranslation(FLT_MAX * 2);
  setZTranslation(FLT_MAX * 2);

  XYZTranslation();
  setXTranslation(x);
  setYTranslation(y);
  setZTranslation(z);
}

// Resulting matrix will be out of bounds unless multiplied by the points and produce logical error caught by the program
void XYZTranslationSmallValueOutOfBounds() {
  float x;
  float y;
  float z;

  x = getXTranslation();
  y = getYTranslation();
  z = getZTranslation();

  setXTranslation(FLT_MIN * 2);
  setYTranslation(FLT_MIN * 2);
  setZTranslation(FLT_MIN * 2);
  XYZTranslation();
 
  setXTranslation(x);
  setYTranslation(y);
  setZTranslation(z);
}
