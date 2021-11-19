#ifndef XSHEAR_TEST_H
#define XSHEAR_TEST_H

// Calls the tests
void runXShearTests();  

struct point** createXShearTestPoints();

void cleanTest(struct point** testPoints);
void testShapeNull();
void testPointsNull();
void testLargeShearValue(struct point** testPoints);
void testSmallShearValue(struct point** testPoints);
void testWrongMagnitude(struct point** testPoints);

void printPoint(struct point toPrint);
int testHelperCompare(struct point vec1, struct point vec2);

#endif

#ifndef XSHEAR_H
#include "ShearInX.h"
#endif
