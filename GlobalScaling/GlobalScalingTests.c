#include "GlobalScalingTests.h"
#include "GlobalScaling.h"

void runGlobalScalingTests(){
    globalScalingCleanTest();

    // globalScalingDirtyTest1();

    globalScalingDirtyTest2();

    globalScalingDirtyTest3();

    globalScalingDirtyTest4();

    globalScalingDirtyTest5(); 
}

/*
    -First clean test
    -intializes each index of the matrix to the value of 1
    -calls globalscaling
    -checks each index if the correct value was entered at that index
    -if unsuccessful prints test failed
*/
void globalScalingCleanTest(){
    globalScaling();
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(i == j && transformationMatrix[i][j] != 1){
                printf("\n");
                printf("Global scaling: globalScalingCleanTest failed\n");
                return;
            }
            else if(i != j && transformationMatrix[i][j] != 0 ){
                printf("\n");
                printf("Global scaling: globalScalingCleanTest failed\n");
                return;
            }
        }
    }

    resetMatrix();
}

/*
    -First dirty test
    -We pass in a empty matrix to test how our function will perform with no matrix
    -it will print test successfully broke the code
*/
/* TODO This test wont work, as you resetMatrix() at the beginning of GlobalScaling.c
void globalScalingDirtyTest1(){
    resetMatrix();
    float check = 1.0;
    globalScaling();
    for(int i = 0; i < 3; i++){
        transformationMatrix[i][i] = 0.0;
    }
    for(int i = 0; i < 3; i++){
            if(transformationMatrix[i][i] == check){
                printf("Global scaling: globalScalingDirtyTest1 failed\n");
                return;
            }
    }
    resetMatrix();
}
*/

/*
    -Second dirty test
    -We set the scaling value to an int 
    -We multiply the scaling value(int) with each index in the matrix(float)
    -The matrix will be filled with junk values at each index
    -it will print test successfully broke the code
*/
void globalScalingDirtyTest2(){
    for(int i = 0; i < 3; i++){
        transformationMatrix[i][i] = 1;
    }
    float check = 1.0;
    int testInt = 2;
    setGlobalScale(testInt);
    //TODO modify one of the points to be <3,3,3,1> and scale it by 2
    //TODO set check to 1.5, but the point should be 1
    globalScaling();
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(transformationMatrix[i][j] == check){
                printf("Global scaling: globalScalingDirtyTest2 failed\n");
                return;
            }
        }
    }
    resetMatrix();
}

/*
    -Third dirty test
    -We set the matrix as an int 
    -We multiply the scaling value(float) with each index in the matrix(int)
    -The matrix will be filled with junk values at each index
    -it will print test successfully broke the code
*/
void globalScalingDirtyTest3(){

    float check = 1.0;
    globalScaling();
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            transformationMatrix[(int)i][(int)j] = 1;
        }
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(transformationMatrix[i][j] == check){
                printf("Global scaling: globalScalingDirtyTest3 failed\n");
                return;
            }
        }
    }
    resetMatrix();
}

/*
    -Fourth dirty test 
    -changing our for loop condition 
    -Example: i > 4 insted of i < 4
    -it will print test successfully broke the code
*/
void globalScalingDirtyTest4(){

    float check = 1.0;
    globalScaling();
    for(int i = 0; i > 3; i++){
        for(int j = 0; j < 3; j++){
            transformationMatrix[i][j] = 1;
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(transformationMatrix[i][j] == check){\
                printf("Global scaling: globalScalingDirtyTest4 failed\n");
                return;
            }
        }
    }
    resetMatrix();
}

/*
    -Fifth dirty test
    -In our for loop, we would iterate through a range that is greater than the bounds of the matrix.
    -Example, 7x4 instead of a 4x4
    -it will print test successfully broke the code
*/
void globalScalingDirtyTest5(){
    float check = 1.0;
    globalScaling();
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 3; j++){
            transformationMatrix[i][j] = 1;
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(transformationMatrix[i][j] == check){
                printf("Global scaling: globalScalingDirtyTest5 failed\n");
                return;
            }
        }
    }
    resetMatrix();
}
