#include "ReadInput.h"
//include .h file for other groups functions then uncomment lower lines

/*
Group 1 - Group Implementation
Zacharias Cymbaluk 1121146
Devyendu Dutta 1018973
Valmik Dixon 1124060
Jesse Varkul 1139803
*/

struct shape *readInput(char *fileName, char *fileName2) {  // readInput manually creates an "expected" file read that would be what we expect from the "real function". Since the TDD is not expected to actually read the real text file, we do not get into file reading here.
    struct shape *newShape = malloc(sizeof(struct shape));
    FILE *fp = fopen(fileName, "r");
    FILE *fp2 = fopen(fileName2, "r");

    if (fp == NULL) {
        return NULL;
    }
    if (fp2 == NULL) {
        return NULL;
    }

    newShape->numOfPoints = 0;
    newShape->points = NULL;
    char line[40];
    struct point *points;
    int i = 0;
    fgets(line, 40, fp);

    do {
        points = malloc(sizeof(struct point));

        if (sscanf(line, "%f,%f,%f,%f", &(points->element[0]), &(points->element[1]), &(points->element[2]), &(points->element[3])) != 4) {
            free(points);
            continue;
        }

        //printf("Pass1\n");
        newShape->points = realloc(newShape->points, (sizeof(struct point *) * (i + 1)));
        //printf("Pass2\n");

        newShape->points[i] = points;

        newShape->numOfPoints = newShape->numOfPoints + 1;

        //printf("%f, %f, %f, %f\n", points->element[0], points->element[1], points->element[2], points->element[3]);

        i++;
    } while (fgets(line, 40, fp));

    //uncoment for other groups when .h file is included
    
	
	char line2[40];
	const char s[2] = "=";
	char *token;
	
	int functCallNums[10];
	i = 0;
	fgets(line2, 40, fp2);

	do{
		token = strtok(line2, s);
		token = strtok(NULL, s);
		//printf("token: %s\n", token);

		functCallNums[i] = atoi(token);
		//printf("functNum: %d\n", functCallNums[i]);

		i++;
	} while(fgets(line2, 40, fp2));


	setGlobalScale(functCallNums[0]);
	setXScale(functCallNums[1]);
  	setYScale(functCallNums[2]);
  	setZScale(functCallNums[3]);
  	setXRotation(functCallNums[4]);
  	setYRotation(functCallNums[5]);
  	setZRotation(functCallNums[6]);
  	setXTranslation(functCallNums[7]);
  	setYTranslation(functCallNums[8]);
  	setZTranslation(functCallNums[9]);
	

    fclose(fp);
    fclose(fp2);

    return newShape;
}
