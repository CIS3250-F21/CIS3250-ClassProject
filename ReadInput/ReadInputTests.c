#include "ReadInputTests.h"
void printShape(struct shape *test);

void runReadInputTests(){
    if(ReadInputTest1("inputShapeFile.csv", "ReadInput/answers1.csv", "inputTransformation.txt")){
        printf("ReadInput Test 1 - Failed\n");
    }
    if(ReadInputTest2("ReadInput/test2.csv", "inputShapeFile.csv", "inputTransformation.txt") == 1){
         printf("ReadInput Test 2 - Failed\n");
    }

    if(ReadInputTest3("ReadInput/test3.csv", "inputShapeFile.csv", "inputTransformation.txt") == 1){
        printf("ReadInput Test 3 - Failed\n");
    }

    if(ReadInputTest4("ReadInput/test4.csv", "inputShapeFile.csv", "inputTransformation.txt") == 1){
        printf("ReadInput Test 4 - Failed\n");
    }

    if(ReadInputTest5("incorrectFileName.csv", "inputTransformation.txt") == 1){
        printf("ReadInput Test 5 - Failed\n");
    }
}

// (CLEAN) Test #1 will compare all the given float values against the expected float values. We expect this test to pass.
char ReadInputTest1(char testFile[20], char answerFile[20], char inputfile2[20]) {
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
                return '1';
            }
        }
    }
    fclose(fp);
    freeShape(inputShape);
    return '0';
}  // END OF TEST 1

//Dirty test 1 - incorrect input format(characters found in the input file)
int ReadInputTest2(char *testFile, char *orgFile, char inputfile2[20]) {
    float *test, *answers;
    readInput(orgFile, inputfile2);
    struct shape *original = inputShape;
    readInput(testFile, inputfile2);  //Read the input file
    for (int i = 0; i < original->numOfPoints; i++) {
        test = original->points[i]->element;
        answers = inputShape->points[i]->element;
        for (int j = 0; j <= 3; j++) {
            if (test[j] != answers[j]) {  //Compare the data between the 2 files
                freeShape(original);
                freeShape(inputShape);
                return 1;
            }
        }
    }
    freeShape(original);
    freeShape(inputShape);
    return 0;
}  // END OF TEST 2

//Dirty test 2 - incorrect inputs format (more than 4 values on each line in the input file)
int ReadInputTest3(char *testFile, char *orgFile, char inputfile2[20]) {
    float *test, *answers;
    readInput(orgFile, inputfile2);
    struct shape *original = inputShape;
    readInput(testFile, inputfile2);  //Read the input file containing characters    
    for (int i = 0; i < original->numOfPoints; i++) {
        test = original->points[i]->element;
        answers = inputShape->points[i]->element;
        for (int j = 0; j <= 4; j++) {
            if (test[j] != answers[j]) {  //Compare the data between the 2 files
                freeShape(original);
                freeShape(inputShape);
                return 1;
            }
        }
    }
    freeShape(original);
    freeShape(inputShape);
    return 0;
}  // END OF TEST 3

//Dirty test 3 - incorrect inputs (incomplete matrix in the input file)
int ReadInputTest4(char *testFile, char *orgFile, char inputfile2[20]) {
    float *test, *answers;
    readInput(orgFile, inputfile2);
    struct shape *original = inputShape;
    readInput(testFile, inputfile2);  //Read the input file containing characters
    for (int i = 0; i < original->numOfPoints; i++) {
        test = original->points[i]->element;
        answers = inputShape->points[i]->element;
        for (int j = 0; j <= 4; j++) {
            if (test[j] != answers[j]) {  //Compare the data between the 2 files
                freeShape(original);
                freeShape(inputShape);
                return 1;
            }
        }
    }
    freeShape(original);
    freeShape(inputShape);
    return 0;
}  // END OF TEST 4

//Dirty test 4 - Incorrect file name passed, fails to read because filereader == NULL.
int ReadInputTest5(char answerFile[20], char inputfile2[20]) {
    readInput(answerFile, inputfile2);  //Call the function with an incorrect file name
		
    if (inputShape == NULL) {
        return 1;  // If file name not found, fail case.
    }
		
    freeShape(inputShape);
    return 0;  // Else, pass case.
}  // END OF TEST 5


void freeShape(struct shape *test) {
    if (!test) return;
    for (int i = 0; i < test->numOfPoints; i++) {
        free(test->points[i]);
				test->points[i] = NULL;
    }
    free(test->points);
		test->points = NULL;
    free(test);
		test = NULL;
}

void printShape(struct shape *test){
		for(int i = 0; i < test->numOfPoints; i++){
 				printf("%d: %f %f %f %f", i, test->points[i]->element[0], test->points[i]->element[1], test->points[i]->element[2], test->points[i]->element[3]);
		}
}
