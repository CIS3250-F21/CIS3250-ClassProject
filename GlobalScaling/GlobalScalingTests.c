#include "GlobalScalingTests.h"
#include "GlobalScaling.h"

void runGlobalScalingTests(){
    makeTestPoint(0);
    checkIfScaledCorrectly();

    makeTestPoint(0);
    checkIfWithZero();

    makeTestPoint(0);
    checkIfScaledCorrectlyWithInts();

    makeTestPoint(0);
    checkVectorPoints();

    makeTestPoint(0);
    checkIfScaledWithNullPoints();

    makeTestPoint(0);
    checkIfScaledWithNegativeNumber();
}

/*
    -calls globalscaling
    -checks each index in point to see if globalScaling has scaled proeprly 
*/
void checkIfScaledCorrectly(){

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
        printf("\nGlobal scaling: checkIfVectorPointsWereScaledCorrectly failed.\n");
        break;
    }

    resetMatrix();
}

/*
    -We set each point in the vector to a float value of [1,2,3,1]
    -set the global scale value to 0 
    -we call global scaling 
    -each point will now equal 0 and each point will stay the same
*/
void checkIfWithZero(){
    struct point * comparPoint;

    setGlobalScale(0);
    globalScaling();
    comparPoint = getPoint(0);
    for( int i = 0; i < 4; i++) {
        comparPoint->element[i] *= 0;
        if( i == 3 ) {
            if( comparPoint->element[i] != 0 ) {
                printf("Global scaling: checkIfVectorPointsWereScaledCorrectlyWithZeroGlobalScaleValue failed.\n");
                continue;
            }
        }
        else if( comparPoint->element[i] == (float)(i + 1) ) {
            continue;
        }
        break;
    }
    resetMatrix();
}


/*
    -We set each point in the vector to an int
    -we call global scaling 
    -The points will be scaled according to the global scale value
*/
void checkIfScaledCorrectlyWithInts(){
    struct point * comparPoint;

    setGlobalScale(2);
    globalScaling();

    comparPoint = getPoint(0);
    for( int i = 0; i < 4; i++) {
        if( i == 3 ) {
            if( comparPoint->element[i] == 1 ) {
                continue;
            }
        }
        else if( comparPoint->element[i] == (float)(i + 1)/2 ) {
            continue;
        }
        printf("\nGlobal scaling: checkIfVectorPointsWereScaledCorrectlyWithInts failed.\n");
        break;
    }

    resetMatrix();
}

/*
    -we call global scaling
    -after the vector has been scaled we multiply each point by 2 
    -This will break it as each point will now contain a incorrect value
*/
void checkVectorPoints(){
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
        printf("\nGlobal scaling: checkIfVectorPointsWereScaledCorrectlyWhenVectorpointsWhereDoubled failed.\n");
        break;
    }

    resetMatrix();
}

/*
    -we set each point in the vector to NULL
    -we call global scaling 
    -Each point will not be scaled as it was passed a null pointer to each point
*/
void checkIfScaledWithNullPoints(){
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
        printf("\nGlobal scaling: checkIfVectorPointsWereScaledCorrectlyWhenPassedNullPointers failed.\n");
        break;
    }

    resetMatrix();
}

/*
    -We pass in negitive numbers at each point in the vector 
    -we call global scaling 
    -The vectors points will all be negitive but the the 4th point in the vector will stay as 1
*/
void checkIfScaledWithNegativeNumber(){
    struct point* comparPoint;

    setGlobalScale(-1);
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
        printf("\nGlobal scaling: checkIfVectorPointsWereScaledCorrectlyWithNegativeNumberGlobalScaleValue failed.\n");
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
