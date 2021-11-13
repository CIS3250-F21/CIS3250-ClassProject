#ifndef XSHEAR_TEST_H
#define XSHEAR_TEST_H

int errorFlag;
int tstFlag;

void runXShearTests();  // Calls the tests

struct point* createTestpoints();

void cleanTest(struct point* testpoints);
void testShapeNull();
void testPointsNull();
void testLargeShearValue(struct point* testpoints);
void testSmallShearValue(struct point* testpoints);
void testWrongMagnitude(struct point* testpoints);

int testHelperCompare(struct point vec1, struct point vec2);

#endif

#ifndef XSHEAR_H
#include "ShearInX.h"
#endif
