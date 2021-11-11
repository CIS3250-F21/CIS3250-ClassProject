#ifndef GROUP13_TEST_H
#define GROUP13_TEST_H

int errorFlag;
int tstFlag;

int main(int argc, char* argv[]);  // Calls the tests

struct point* createTestpoints();

void cleanTest(struct point* testpoints);
void testShapeNull();
void testpointsNull();
void testLargeShearValue(struct point* testpoints);
void testSmallShearValue(struct point* testpoints);
void testWrongMagnitude(struct point* testpoints);

int testHelperCompare(struct point vec1, struct point vec2);

#endif

#ifndef GROUP_13_H
#define GROUP_13_H
#include 'Group13.h'
#endif
