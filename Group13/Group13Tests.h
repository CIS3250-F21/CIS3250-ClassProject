#ifndef GROUP13_TEST_H
#define GROUP13_TEST_H

const float FLOAT_MIN = -1175494351000000000000000000000000000.0;
const float FLOAT_MAX = 34028234600000000000000000000000000000.0;

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
