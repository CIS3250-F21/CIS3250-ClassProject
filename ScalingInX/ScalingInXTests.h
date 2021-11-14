#ifndef SCALINGINX_TESTS_H
#define SCALINGINX_TESTS_H

#include "../main.h"
#include <stdbool.h>

void runScalingInXTests(struct shape *shape);
void zeroTransformationTest();
void noTransformationTest();
void doubleTransformationTest();
bool isScaleChanged();
bool emptyMatrixSet();
void transformationTest();

#endif

