#include "xPlaneReflectionTests.h"
#include "xPlaneReflection.h"

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
		fprintf( stderr, "Error: X value did not reflect correctly. Exiting the program.\n" );
		exit(1);
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
		    fprintf( stderr, "Error: the values are changed. Exiting the program.\n" );
		    exit(1);
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
				fprintf( stderr, "Error: unexpected value. Exiting the program.\n" );
				exit(1);
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

void runXPlaneReflectionTests() {
	struct point * currPoint;
    generateXPlaneReflectionMatrix();
    testTransformationMatrix();
	testInputNotEmpty();
    testXPlaneReflection();

    resetMatrix();
}

void testXPlaneReflection() {
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
