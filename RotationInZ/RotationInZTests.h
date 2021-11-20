#ifndef ROTATION_Z_TESTS_H
#define ROTATION_Z_TESTS_H

#include <math.h>
#include <stdio.h>

#include "../main.h"
#include "RotationInZ.h"

void runRotationInZTests ();
void testValidAngles (float expectedTransformationMatrix[4][4], float theta);
void testValidVectors (float expectedVector [4]);

#endif
