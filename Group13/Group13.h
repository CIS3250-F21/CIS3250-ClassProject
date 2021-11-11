#ifndef GROUP_13_H
#define GROUP_13_H

// Must always be defined, but only used in test mode
int errorFlag;
int tstFlag;

const float FLOAT_MIN = -1175494351000000000000000000000000000.0;
const float FLOAT_MAX = 34028234600000000000000000000000000000.0;

#include "../main.h"

void printErr(char* toPrint);

void xShear();

#endif
