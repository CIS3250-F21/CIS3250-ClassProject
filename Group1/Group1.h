#ifndef GROUP_1_H
#define GROUP_1_H

#include "../main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

struct points{
	float vector[4];
};

struct shape{ // Declaration of shape structure.
	struct points* vectors;
	int numOfVectors;
	float scaling[4];
	float rotation[3];
	float translation[3];
	float shearing[3];
};

struct shape *readInput(char* fileName);
char test1(char [], char []);
int test2(char *, char *);
int test3(char *, char *);
int test4(char *, char *);
int test5(char []);
int test6(char [], char []);

#endif