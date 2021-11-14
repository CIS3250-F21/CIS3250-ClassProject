#include "GlobalScalingTests.h"
#include "GlobalScaling.h"

void runGlobalScalingTests(){
    globalScalingCleanTest();

    globalScalingDirtyTest1();

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
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            transformationMatrix[i][j] = 1.0;
        }
    }
    printf("*************************Running clean test****************************");
    float check = 1.0;
    globalScaling();
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(transformationMatrix[i][j] != check){
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
void globalScalingDirtyTest1(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            transformationMatrix[i][j] = 1.0;
        }
    }
    printf("*************************Running first dirty test****************************");
    float check = 1.0;
    globalScaling();
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(transformationMatrix[i][j] != check){
                return;
            }
        }
    }
    resetMatrix();
}

/*
    -Second dirty test
    -We set the scaling value to an int 
    -We multiply the scaling value(int) with each index in the matrix(float)
    -The matrix will be filled with junk values at each index
    -it will print test successfully broke the code
*/
void globalScalingDirtyTest2(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            transformationMatrix[i][j] = 1;
        }
    }
    printf("*************************Running second dirty test****************************");
    float check = 1.0;
    int testInt = 2;
    setGlobalScale(testInt);
    globalScaling();
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(transformationMatrix[i][j] != check){
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
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            transformationMatrix[(int)i][(int)j] = 1;
        }
    }
    printf("*************************Running third dirty test****************************");
    float check = 1.0;
    int testInt = 2;
    setGlobalScale(testInt);
    globalScaling();
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(transformationMatrix[i][j] != check){
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
    for(int i = 0; i > 4; i++){
        for(int j = 0; j < 4; j++){
            transformationMatrix[i][j] = 1;
        }
    }
    printf("*************************Running fourth dirty test****************************");
    float check = 1.0;
    globalScaling();
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(transformationMatrix[i][j] != check){
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
    printf("*************************Running fifth dirty test****************************");
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 4; j++){
            transformationMatrix[i][j] = 1;
        }
    }
    float check = 1.0;
    globalScaling();
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(transformationMatrix[i][j] != check){
                return;
            }
        }
    }
    resetMatrix();
}
