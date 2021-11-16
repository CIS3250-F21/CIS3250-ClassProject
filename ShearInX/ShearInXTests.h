#ifndef XSHEAR_TEST_H
#define XSHEAR_TEST_H

void runXShearTests();  // Calls the tests

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
