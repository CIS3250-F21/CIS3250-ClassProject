#ifndef SHEAR_IN_Z_TESTS_H
#define SHEAR_IN_Z_TESTS_H

#include "../main.h"
#include <float.h>
#include "../RotationInY/RotationInYTests.h"


void runZShearTests();
void validTest();
void nullPointTest();
void minimumFloatShearValueTest();
void maximumFloatShearValueTest();
void uninitializedShapeStructTest();

#endif
