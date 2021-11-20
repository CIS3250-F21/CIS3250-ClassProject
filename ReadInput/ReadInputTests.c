#include "ReadInputTests.h"

void runReadInputTests(){
		
    if(ReadInputTest1("inputShapeFile.csv", "ReadInput/answers1.csv", "inputTransformation.txt")){
        printf("ReadInput Test 1 - Failed\n");
    }
}

// (CLEAN) Test #1 will compare all the given float values against the expected float values. We expect this test to pass.
int ReadInputTest1(char testFile[20], char answerFile[20], char inputfile2[20]) {
    readInput(testFile, inputfile2);
    FILE *fp = fopen(answerFile, "r");
    int lines = 0;
    char buf[50];
    float *test;
    float answers[4];
    for (int i = 0; fgets(buf, 50, fp); i++) {
				test = inputShape->points[i]->element;
        sscanf(buf, "%f,%f,%f,%f", &answers[0], &answers[1], &answers[2], &answers[3]);
        lines++;
        for (int j = 0; j < 4; j++) {
            if (test[j] != answers[j]) {
								fclose(fp);
                freeShape(inputShape);
                return 1;
            }
        }
    }
    fclose(fp);
    freeShape(inputShape);
    return 0;
}  // END OF TEST 1

void freeShape(struct shape *test) {
    if (!test) return;
    for (int i = 0; i < test->numOfPoints; i++) {
        if (test->points[i] != NULL) {
                free(test->points[i]);
        }
    }
    free(test->points);
    free(test);
}

void printShape(struct shape *test){
		for(int i = 0; i < test->numOfPoints; i++){
 				printf("%d: %f %f %f %f", i, test->points[i]->element[0], test->points[i]->element[1], test->points[i]->element[2], test->points[i]->element[3]);
		}
}
