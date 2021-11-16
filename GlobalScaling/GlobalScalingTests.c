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
    -calls globalscaling
    -checks each index in point to see if globalScaling has scaled proeprly 
    -if unsuccessful prints Global scaling: globalScalingCleanTest failed
*/
void globalScalingCleanTest(){
    struct point * testPoint = malloc(sizeof(struct point));
    for (int i = 0; i < 4; i++) {
        if(i == 0){
            testPoint->element[i] = (float)1;
            setPoint(i, testPoint);
        }
        if(i == 1){
            testPoint->element[i] = (float)2;
            setPoint(i, testPoint);
        }
        if(i == 2){
            testPoint->element[i] = (float)3;
            setPoint(i, testPoint);
        }
        if(i == 3){
            testPoint->element[i] = (float)1;
            setPoint(i, testPoint);
        }
        
    }
    setGlobalScale(1);
    globalScaling();
    int i = 0;
    
    while((testPoint = getPoint(i)) != NULL){
        if(i == 0){
            if(testPoint->element[i] != 1) {
                printf("\n");
                printf("Global scaling: globalScalingCleanTest failed\n");
                return;
            }
        }
        if(i == 1){
            if(testPoint->element[i] != 2) {
                printf("\n");
                printf("Global scaling: globalScalingCleanTest failed\n");
                return;
            }
        }
        if(i == 2){
            if(testPoint->element[i] != 3) {
                printf("\n");
                printf("Global scaling: globalScalingCleanTest failed\n");
                return;
            }
        }
        if(i == 3){
            if(testPoint->element[i] != 1) {
                printf("\n");
                printf("Global scaling: globalScalingCleanTest failed\n");
                return;
            }
        }
        i++;
    }

    free(testPoint->element);
    free(testPoint);
    resetMatrix();
}

/*
    -First dirty test
    -We set each point in the vector to a float value of [1,2,3,1]
    -set the global scale value to 0 
    -we call global scaling 
    -each point will now equal 0 and function has been broken([0, 0 ,0, 0])
*/
void globalScalingDirtyTest1(){
    struct point * testPoint = malloc(sizeof(struct point));
    for (int i = 0; i < 4; i++) {
        if(i == 0){
            testPoint->element[i] = (float)1;
            setPoint(i, testPoint);
        }
        if(i == 1){
            testPoint->element[i] = (float)2;
            setPoint(i, testPoint);
        }
        if(i == 2){
            testPoint->element[i] = (float)3;
            setPoint(i, testPoint);
        }
        if(i == 3){
            testPoint->element[i] = (float)1;
            setPoint(i, testPoint);
        }
        
    }
    setGlobalScale(0);
    globalScaling();
    int i = 0;
    while((testPoint = getPoint(i)) != NULL){
        if(i == 0){
            if(testPoint->element[i] != 1){
            return;
            }
        }
        else if(i == 1){
            if(testPoint->element[i] != 2) {
                return;
            }
        }
        else if(i == 2){
            if(testPoint->element[i] != 3) {
                return;
            }
        }
        else if(i == 3){
            if(testPoint->element[i] != 1) {
                return;
            }
        }
        i++;
    }

    printf("Global scaling: globalScalingDirtyTest1: failed\n");
    free(testPoint->element);
    free(testPoint);
    resetMatrix();
}


/*
    -Second dirty test
    -We set each point in the vector to an int
    -we call global scaling 
    -The point will be scaled but the values stored at each point will be different to whats it suppose to be([0,1,1,1])
    for example: 3/2 = 1.5 but sinces its an int, it will be stored as only 1 
*/
void globalScalingDirtyTest2(){
    struct point * testPoint = malloc(sizeof(struct point));
    for (int i = 0; i < 4; i++) {
        if(i == 0){
            testPoint->element[i] = (int)1;
            setPoint(i, testPoint);
        }
        if(i == 1){
            testPoint->element[i] = (int)2;
            setPoint(i, testPoint);
        }
        if(i == 2){
            testPoint->element[i] = (int)3;
            setPoint(i, testPoint);
        }
        if(i == 3){
            testPoint->element[i] = (int)1;
            setPoint(i, testPoint);
        }
        
    }
    int i = 0;
    setGlobalScale(2);
    globalScaling();
    while((testPoint = getPoint(i)) != NULL){
        if(i == 2){
            if(testPoint->element[i] == 1.5){
                printf("Global scaling: globalScalingDirtyTest2: failed\n");
                return;
            }
        }
        i++;
    }
    free(testPoint->element);
    free(testPoint);
    resetMatrix();
}

/*
    -Third dirty test
    -We set each point in the vector to a float value
    -we call global scaling
    -after the vector has been scaled we multiply each point by 2 
    -This will break it as each point will now contain a incorrect value([1,2,3,2])
*/
void globalScalingDirtyTest3(){
    struct point * testPoint = malloc(sizeof(struct point));
    for (int i = 0; i < 4; i++) {
        if(i == 0){
            testPoint->element[i] = (float)1;
            setPoint(i, testPoint);
        }
        if(i == 1){
            testPoint->element[i] = (float)2;
            setPoint(i, testPoint);
        }
        if(i == 2){
            testPoint->element[i] = (float)3;
            setPoint(i, testPoint);
        }
        if(i == 3){
            testPoint->element[i] = (float)1;
            setPoint(i, testPoint);
        }
        
    }
    int i = 0;
    setGlobalScale(1);
    globalScaling();
    
    while((testPoint = getPoint(i)) != NULL){
        testPoint->element[i] *= 2;

        if(i == 0){
            if(testPoint->element[i] != 1){
                return;
            }
        }
        else if(i == 1){
            if(testPoint->element[i] != 2) {
                return;
            }
        }
        else if(i == 2){
            if(testPoint->element[i] != 3) {
                return;
            }
        }
        else if(i == 3){
            if(testPoint->element[i] != 1) {
                return;
            }
        }
        i++;
    }
    free(testPoint->element);
    free(testPoint);
    resetMatrix();
}

/*
    -Fourth dirty test 
    -we set each point in the vector to NULL
    -we call global scaling 
    -Each point will not be scaled as it was passed a null pointer to each point([])
*/
void globalScalingDirtyTest4(){
    struct point * testPoint = malloc(sizeof(struct point));
    /*
    for (int i = 0; i < 4; i++) {
        if(i == 0){
            testPoint->element[i] = NULL;
            setPoint(i, testPoint);
        }
        if(i == 1){
            testPoint->element[i] = NULL;
            setPoint(i, testPoint);
        }
        if(i == 2){
            testPoint->element[i] = NULL;
            setPoint(i, testPoint);
        }
        if(i == 3){
            testPoint->element[i] = NULL;
            setPoint(i, testPoint);
        }
        
    }*/
    int i = 0;
    setGlobalScale(1);
    globalScaling();
    
    while((testPoint = getPoint(i)) != NULL){
        if(i == 0){
            if(testPoint->element[i] != 1){
                return;
            }
        }
        else if(i == 1){
            if(testPoint->element[i] != 2) {
                return;
            }
        }
        else if(i == 2){
            if(testPoint->element[i] != 3) {
                return;
            }
        }
        else if(i == 3){
            if(testPoint->element[i] != 1) {
                return;
            }
        }
        i++;
    }  
    free(testPoint->element);
    free(testPoint);
    resetMatrix();
}

/*
    -Fifth dirty test
    -We pass in negitive numbers at each point in the vector 
    -we call global scaling 
    -The vectors points will all be negitive when its suppose to be positive([-1,-2,-3,-1])
*/
void globalScalingDirtyTest5(){
    struct point * testPoint = malloc(sizeof(struct point));
    for (int i = 0; i < 4; i++) {
        if(i == 0){
            testPoint->element[i] = -1;
            setPoint(i, testPoint);
        }
        if(i == 1){
            testPoint->element[i] = -2;
            setPoint(i, testPoint);
        }
        if(i == 2){
            testPoint->element[i] = -3;
            setPoint(i, testPoint);
        }
        if(i == 3){
            testPoint->element[i] = -1;
            setPoint(i, testPoint);
        }
        
    }
    int i = 0;
    setGlobalScale(1);
    globalScaling();
    
    while((testPoint = getPoint(i)) != NULL){
        testPoint->element[i] *= 2;

        if(i == 0){
            if(testPoint->element[i] != 1){
                return;
            }
        }
        else if(i == 1){
            if(testPoint->element[i] != 2) {
                return;
            }
        }
        else if(i == 2){
            if(testPoint->element[i] != 3) {
                return;
            }
        }
        else if(i == 3){
            if(testPoint->element[i] != 1) {
                return;
            }
        }
        i++;
    }
    
    free(testPoint->element);
    free(testPoint);
    resetMatrix();
}
