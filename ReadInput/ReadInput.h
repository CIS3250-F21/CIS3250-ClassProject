#ifndef GROUP_1_H
#define GROUP_1_H
#include "../main.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

struct point{
	float element[4];	
};

struct shape{ 					// Declaration of shape structure.
	struct point** points;	// Array of struct pointers
	int numOfPoints;		
	float scaling[4];
	float rotation[3];
	float translation[3];
	float shearing[3];
};

struct shape *readInput(char*, char*);

#endif