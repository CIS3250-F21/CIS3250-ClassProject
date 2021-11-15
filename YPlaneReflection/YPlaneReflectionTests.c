#include "YPlaneReflectionTests.h"
#include "YPlaneReflection.h"

/* 
 Tests if the y value was correctly flipped
 Returns 1 if successful, 0 otherwise
*/
int didYReflect( struct point * oldPoint, struct point * newPoint ) {
	if( oldPoint->element[0] == -newPoint->element[0]) {
		return 1;
	}
	else {
		fprintf( stderr, "old point y-value: %f, new point y-value: %f\n", oldPoint->element[0], newPoint->element[0] );
		fprintf( stderr, "Error: Y value did not reflect correctly.\n" );
		return 0;
	}
}

/*
 Tests if the other values in the point are unchanged
 Returns 1 if successful, 0 otherwise
*/
int testOtherValuesUnchanged( struct point * oldPoint, struct point * newPoint ) {
	for( int i = 1; i < 4; i++ ) {
		if( oldPoint->element[i] != newPoint->element[i]) {
		    fprintf( stderr, "old point y-value: %f, new point y-value: %f\n", oldPoint->element[i], newPoint->element[i] );
		    fprintf( stderr, "Error: Y Reflection modified additional values.\n" );
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
 Tests if the transformation matrix is set to the correct values for reflection in y
 Returns 1 on success, 0 otherwise
*/
int testTransformationMatrix(){
	float expectedMatrix [4][4] = {{1,0,0,0},{0,-1,0,0},{0,0,1,0},{0,0,0,1}};
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
	return( didYReflect(localPoint, getPoint(index)) && testOtherValuesUnchanged(localPoint, getPoint(index)) );
}

void runYPlaneReflectionTests() {
    generateYPlaneReflectionMatrix();
    testTransformationMatrix();
	testInputNotEmpty();
    testYPlaneReflection();

    resetMatrix();
}

void testYPlaneReflection() {
    struct point oldPoint, newPoint;

    generateXPlaneReflectionMatrix();

    // Initialize oldPoint with sample values and copy into newPoint
    oldPoint.element[0] = 1;
    oldPoint.element[1] = 2;
    oldPoint.element[2] = 3;
    oldPoint.element[3] = 1;
    newPoint = oldPoint;

    // Reflect newPoint and compare against oldPoint
    multiplyMatrix( &newPoint, transformationMatrix );
	didXReflect( &oldPoint, &newPoint );
	testOtherValuesUnchanged( &oldPoint, &newPoint ); 

    resetMatrix();
}
