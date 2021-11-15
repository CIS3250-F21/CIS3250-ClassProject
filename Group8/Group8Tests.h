#ifndef GROUP_8_TESTS_H
#define GROUP_8_TESTS_H

#include <math.h>
#include <stdio.h>

#include "../main.h"
#include "Group8.h"

void runGroup8Tests();
void testValidAngles (float expectedTransformationMatrix[4][4], float theta);
void testValidVectors (float expectedVector [4]);

#endif
