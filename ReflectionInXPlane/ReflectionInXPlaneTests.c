#include "ReflectionInXPlaneTests.h"
#include "ReflectionInXPlane.h"

/* 
 Tests if the x value was correctly flipped
 Returns 1 if successful, 0 otherwise
*/
int didXReflect( struct point * oldP, struct point * newP ) {
	if( oldP->element[0] == -newP->element[0]) {
		return 1;
	}
	else {
		fprintf( stderr, "old point x-value: %f, new point x-value: %f\n", oldP->element[0], newP->element[0] );
		fprintf( stderr, "Error: X value did not reflect correctly.\n" );
		return 0;
	}
}

/*
 Tests if the other values in the point are unchanged
 Returns 1 if successful, 0 otherwise
*/
int testOtherValuesUnchanged( struct point * oldP, struct point * newP ) {
	for( int i = 1; i < 4; i++ ) {
		if( oldP->element[i] != newP->element[i]) {
		    fprintf( stderr, "old point x-value: %f, new point x-value: %f\n", oldP->element[i], newP->element[i] );
		    fprintf( stderr, "Error: X Reflection modified additional values.\n" );
		    return 0;
		}
	}
	return 1;
}

/*
 Tests if the input given is empty
 Returns 0 if empty, 1 otherwise
*/
int testInputNotEmpty() {
	if ( inputShape->points == NULL ) {
		fprintf( stderr, "Error: input is empty.\n" );
		return 0;
	}
	return 1;
}

/*
 Tests if the transformation matrix is set to the correct values for reflection in X
 Returns 1 on success, 0 otherwise
*/
int testTransformationMatrix(){
	float expectedMatrix [4][4] = {{-1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
	for( int i=0; i<4; i++ ){
		for( int j=0; j<4; j++ ){
			if( expectedMatrix[i][j]!=transformationMatrix[i][j] ){
				fprintf( stderr, "Expected: %f, received %f\n", expectedMatrix[i][j], transformationMatrix[i][j] );
				fprintf( stderr, "Error: unexpected value in transformation matrix.\n" );
				return 0;
			}
		}
	}
	return 1;
}

/* 
 Tests if the point was correctly saved in the inputShape struct.
 Returns 1 on BOTH successes, 0 otherwise
*/
int testSetPoint( struct point * localPoint, int index ) {
	return( didXReflect(localPoint, getPoint(index)) && testOtherValuesUnchanged(localPoint, getPoint(index)) );
}

void runReflectionInXPlaneTests() {
	
    generateXPlaneReflectionMatrix();
    testTransformationMatrix();
	testInputNotEmpty();
    testReflectionInXPlane();

    resetMatrix();
}

/* 
 Tests if a point was multiplied successfully
 Returns 1 on if reflected successfully, 0 otherwise
*/
void testReflectionInXPlane() {
    struct point oldP, newP;

    generateXPlaneReflectionMatrix();

    // Initialize oldP with sample values and copy into newP
    oldP.element[0] = 1;
    oldP.element[1] = 2;
    oldP.element[2] = 3;
    oldP.element[3] = 1;
    newP = oldP;

    // Reflect newP and compare against oldP
    multiplyMatrix( &newP, transformationMatrix );
	didXReflect( &oldP, &newP );
	testOtherValuesUnchanged( &oldP, &newP ); 

    resetMatrix();
}
