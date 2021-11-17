#include "GlobalScalingTests.h"
#include "GlobalScaling.h"

void runGlobalScalingTests(){
    makeTestPoint(0);
    globalScalingCleanTest();

    makeTestPoint(0);
    globalScalingDirtyTest1();

    // The program actually properly handles this case, maybe turn it into a clean test
    //makeTestPoint(0);
    //globalScalingDirtyTest2();

    makeTestPoint(0);
    globalScalingDirtyTest3();

    makeTestPoint(0);
    globalScalingDirtyTest4();

    // This test had the same implementation as test4, not sure why
    //makeTestPoint(0);
    //GlobalScalingDirtyTest5(); 
}

/*
    -First clean test
    -calls globalscaling
    -checks each index in point to see if globalScaling has scaled proeprly 
    -if unsuccessful prints Global scaling: globalScalingCleanTest failed
*/
void globalScalingCleanTest(){

    struct point* comparPoint;
    // Saves pointer to old address for freeing later
    struct point* oldPoint;

    // Creating test point
    struct point* newPoint = (struct point*) malloc( sizeof(struct point) );
    for(int i = 0; i <4; i++) {
        newPoint->element[i] = (float) (i + 1);
    }
    newPoint->element[3] = (float) 1;

    // Overwrites point at index 0
    oldPoint = getPoint(0);
    setPoint(0, newPoint);
    free( oldPoint );


    setGlobalScale(1);
    globalScaling();
    
    // this point should be the same as newPoint, as scale is 1
    comparPoint = getPoint(0);
    for( int i = 0; i < 4; i++) {
        if( i == 3 ) {
            if( comparPoint->element[i] == (float) 1 ) {
                continue;
            }
        }
        else if( comparPoint->element[i] == (float) (i + 1) ) {
            continue;
        }
        printf("\nGlobal scaling: globalScalingCleanTest failed.\n");
        break;
    }

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
    struct point * comparPoint;

    setGlobalScale(0);
    globalScaling();
 
    comparPoint = getPoint(0);
    for( int i = 0; i < 4; i++) {
        if( i == 3 ) {
            if( comparPoint->element[i] != 1 ) {
                continue;
            }
        }
        else if( comparPoint->element[i] != (float)(i + 1) ) {
            continue;
        }
        printf("\nGlobal scaling: globalScalingDirtyTest1 failed.\n");
        break;
    }

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
    struct point * comparPoint;

    setGlobalScale(2);
    globalScaling();

    comparPoint = getPoint(0);
    for( int i = 0; i < 4; i++) {
        if( i == 3 ) {
            if( comparPoint->element[i] != 1 ) {
                continue;
            }
        }
        else if( comparPoint->element[i] != (float)(i + 1)/2 ) {
            continue;
        }
        printf("\nGlobal scaling: globalScalingDirtyTest2 failed.\n");
        break;
    }

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
    struct point * comparPoint;

    setGlobalScale(1);
    globalScaling();
    
    comparPoint = getPoint(0);
    for( int i = 0; i < 4; i++) {
        comparPoint->element[i] *= 2;

        if( i == 3 ) {
            if( comparPoint->element[i] != 1 ) {
                continue;
            }
        }
        else if( comparPoint->element[i] != (float)(i + 1)/2 ) {
            continue;
        }
        printf("\nGlobal scaling: globalScalingDirtyTest3 failed.\n");
        break;
    }

    resetMatrix();
}

/*
    -Fourth dirty test 
    -we set each point in the vector to NULL
    -we call global scaling 
    -Each point will not be scaled as it was passed a null pointer to each point([])
*/
void globalScalingDirtyTest4(){
    struct point* comparPoint;

    setGlobalScale(1);
    globalScaling();
    
    comparPoint = getPoint(0);
    for( int i = 0; i < 4; i++) {
        comparPoint->element[i] *= 2;

        if( i == 3 ) {
            if( comparPoint->element[i] != 1 ) {
                continue;
            }
        }
        else if( comparPoint->element[i] != (float)(i + 1)/2 ) {
            continue;
        }
        printf("\nGlobal scaling: globalScalingDirtyTest4 failed.\n");
        break;
    }

    resetMatrix();
}

/*
    -Fifth dirty test
    -We pass in negitive numbers at each point in the vector 
    -we call global scaling 
    -The vectors points will all be negitive when its suppose to be positive([-1,-2,-3,-1])
*/
void globalScalingDirtyTest5(){
    struct point* comparPoint;

    setGlobalScale(1);
    globalScaling();
    
    comparPoint = getPoint(0);
    for( int i = 0; i < 4; i++) {
        comparPoint->element[i] *= 2;

        if( i == 3 ) {
            if( comparPoint->element[i] != 1 ) {
                continue;
            }
        }
        else if( comparPoint->element[i] != (float)(i + 1)/2 ) {
            continue;
        }
        printf("\nGlobal scaling: globalScalingDirtyTest4 failed.\n");
        break;
    }
    
    resetMatrix();
}

void makeTestPoint(int index) {
    // Saves pointer to old address for freeing later
    struct point* oldPoint;

    // Creating test point
    struct point* newPoint = (struct point*) malloc( sizeof(struct point) );
    for(int i = 0; i <4; i++) {
        newPoint->element[i] = (float) (i + 1);
    }
    newPoint->element[3] = (float) 1;

    // Overwrites point at index
    oldPoint = getPoint(index);
    setPoint(index, newPoint);
    free( oldPoint );
}
