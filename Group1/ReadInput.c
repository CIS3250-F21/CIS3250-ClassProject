
#include "ReadInput.h"
/*
Group 1 - Group Implementation
Zacharias Cymbaluk 1121146 
Devyendu Dutta 1018973 
Valmik Dixon 1124060 
Jesse Varkul 1139803
*/

struct shape* readInput (char* fileName){ // readInput manually creates an "expected" file read that would be what we expect from the "real function". Since the TDD is not expected to actually read the real text file, we do not get into file reading here.
	struct shape *newShape = malloc(sizeof(struct shape));
	FILE *fp = fopen(fileName, "r");
	if (fp == NULL){
	  return NULL;
	}
	char line[40];
	struct points *vectors = newShape->vectors;
	vectors = malloc(1);
	int i = 0;
	fgets(line, 40, fp);
	
	do{
		vectors = realloc(vectors, (sizeof(struct points) * (i + 1)));

		sscanf(line, "%f %f %f", &vectors[i].vector[0], &vectors[i].vector[1], &vectors[i].vector[2]);
		

		vectors[i].vector[3] = 1;
		
		newShape->numOfVectors = newShape->numOfVectors + 1;

		newShape->vectors = vectors;
	
		//printf("%f; %f, %f, %f \n", vectors[i].vector[0], vectors[i].vector[1], vectors[i].vector[2], vectors[i].vector[3]);
		
		i++;

	}while(fgets(line, 40, fp));
	
	fclose(fp);
	
	return newShape;
}

