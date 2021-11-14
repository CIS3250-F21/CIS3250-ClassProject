#include "ReadInputTests.h"

// (CLEAN) Test #1 will compare all the given float values against the expected float values. We expect this test to pass.
char test1(char testFile[20], char answerFile[20]){
	struct shape *input = readInput (testFile);
	FILE *fp = fopen(answerFile, "r");
	int lines = 0;
	char buf[30];
	float *test;
	float answers[3];
	for(int i = 0; fgets(buf, 30, fp); i++){
		test = input->vectors[i].vector;
		sscanf(buf, "%f %f %f", &answers[0], &answers[1], &answers[2]);
		lines++;
		for(int j = 0; j <3; j++){
			if(test[j] != answers[j]){
				fclose(fp);
				free(input->vectors);
				free(input);
				return 1;
			}
		}
	}
	fclose(fp);
	free(input->vectors);
	free(input);
	return 0;
}// END OF TEST 1

//Dirty test 1 - incorrect input format(characters found in the input file)
int test2(char *testFile, char *orgFile){
	float *test, *answers;
	struct shape *original = readInput(orgFile);		//Read the "correct" original input file 
	struct shape *testInput = readInput(testFile);	//Read the input file containing characters
	for(int i = 0; original->numOfVectors; i++){
		test = original->vectors[i].vector;
		answers = testInput->vectors[i].vector;
		for(int j = 0; j <= 3; j ++){
			if(test[j] != answers[j]){									//Compare the data between the 2 files 
				return 1;
			}	
		}
	}
	return 0;
}// END OF TEST 2

//Dirty test 2 - incorrect inputs format (more than 3 values on each line in the input file)
int test3(char *testFile, char *orgFile){
	float *test, *answers;
	struct shape *original = readInput(orgFile);		//Read the "correct" original input file 
	struct shape *testInput = readInput(testFile);	//Read from input file with more than 3 values on each line
	for(int i = 0; original->numOfVectors; i++){
		test = original->vectors[i].vector;
		answers = testInput->vectors[i].vector;
		for(int j = 0; j <= 3; j ++){
			if(test[j] != answers[j]){									//Compare the data between the 2 files 
				return 1;
			}	
		}
	}
	return 0;
}// END OF TEST 3

//Dirty test 3 - incorrect inputs (incomplete matrix in the input file)
int test4(char *testFile, char *orgFile){
	float *test, *answers;
	struct shape *original = readInput(orgFile);		//Read the "correct" original input file 
	struct shape *testInput = readInput(testFile);	//Read from "incomplete" input file
	for(int i = 0; original->numOfVectors; i++){
		test = original->vectors[i].vector;
		answers = testInput->vectors[i].vector;
		for(int j = 0; j <= 3; j ++){
			if(test[j] != answers[j]){									//Compare the data between the 2 files 
				return 1;
			}	
		}
	}
	return 0;
} // END OF TEST 4

//Dirty test 4 - Incorrect file name passed, fails to read because filereader == NULL.
int test5(char answerFile[20]){

	struct shape *original = readInput(answerFile);		//Call the function with an incorrect file name
	
	if (original == NULL){

	  return 1; // If file name not found, fail case.
	}	

	return 0; // Else, pass case.
}// END OF TEST 5

// Dirty Test 5 - Attempts to add all floats contained in both txt files and compare the values. (Index is wrong...)
int test6(char testFile[20], char answerFile[20]){

	float runningTotalExpected = 0;
	float runningTotalSecond = 0;

	struct shape *passedStruct = readInput(testFile);

	for(int i = 0; i < passedStruct->numOfVectors; i++){
		for(int j = 0; j <= 5; j++){
			runningTotalExpected += passedStruct->vectors[i].vector[j];
		} // variable j exceeds array index number of vectors within struct (should be '<5' instead of '<=5') (this is the error)
	}

		FILE *fp = fopen(answerFile, "r");
		
		int lines = 0;
		char buf[30];
		//float *test = 0;
		float answers[3];
		for(int i = 0; fgets(buf, 30, fp); i++){
		sscanf(buf, "%f %f %f", &answers[0], &answers[1], &answers[2]);
		runningTotalSecond += answers[0]; // 
		runningTotalSecond += answers[1]; // These three lines add all the float values into
		runningTotalSecond += answers[2]; // 
		lines++; 

		}

	if(runningTotalExpected != runningTotalSecond){ // Compares totals from addition. (Expected vs fileRead)
		return 1; // if not equal, fail case.
	}
		else{
			return 0; // if equal, pass case.
		}

} // END OF TEST 6
