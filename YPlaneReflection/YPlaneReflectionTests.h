#ifndef Y_PLANE_REFLECTION_TESTS_H
#define Y_PLANE_REFLECTION_TESTS_H

#include "../main.h"

/* Test Functions */
int didYReflect( struct point * old, struct point * newV ); // Tests if x reflected correctly
int testOtherValuesUnchanged( struct point * old, struct point * newV ); // Tests if y,z,1 are unchanged
int testInputNotEmpty();   // Tests if the point list initialized
int testTransformationMatrix(); // Tests if the transformation matrix matches our pattern
void runYPlaneReflectionTests(); // Calls each test function
void testYPlaneReflection(); // Tests x plane reflection with sample value

#endif