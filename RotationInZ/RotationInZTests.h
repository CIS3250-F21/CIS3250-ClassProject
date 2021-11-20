#ifndef ROTATION_Z_TESTS_H
#define ROTATION_Z_TESTS_H

#include <math.h>
#include <stdio.h>

#include "../main.h"
#include "RotationInZ.h"

void runRotationInZTests ();
void testValidPoints ();
void testAngleWithSqrt ();
void testAngleWithMinFloatValue ();
void testAngleWithMaxFloatValue ();
void testAnglesWithDecimalPlaces ();
void testAngleEqualtoZero ();

#endif
