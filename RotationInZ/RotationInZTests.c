#include "RotationInZTests.h"

//Runs tests
void runRotationInZTests() {

    testAngleEqualtoZero ();
    testAnglesWithDecimalPlaces ();
    testAngleWithMaxFloatValue ();
    testAngleWithMinFloatValue ();
    testAngleWithSqrt ();
    testValidVectors ();

}

// Clean test
// Test rotation matrix with an angel equavalent to zero
void testAngleEqualtoZero () {
  
    float expectedMatrix[4][4] = {{cos(0), -sin(0), 0, 0}, {sin(0), cos(0), 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}}; 

    generateZRotationMatrix (0);

    for (int i = 0 ; i < 4 ; i++) {

        for (int j = 0 ; j < 4 ; j++) {

            if ((fabs (transformationMatrix[i][j] - expectedMatrix[i][j])) > 0.001) {

                printf ("Test rotation matrix with an angel equavalent to zero failed.\n");
            }
        }
    } 
}

// Clean Test
// Test rotation matrix with a decimal value
void testAnglesWithDecimalPlaces () {
  
    float expectedMatrix[4][4] = {{cos(790.28), -sin(790.28), 0, 0}, {sin(790.28), cos(790.28), 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}}; 

    generateZRotationMatrix (790.28);

    for (int i = 0 ; i < 4 ; i++) {

        for (int j = 0 ; j < 4 ; j++) {

            if ((fabs (transformationMatrix[i][j] - expectedMatrix[i][j])) > 0.001) {

                printf ("Test rotation matrix with a decimal value failed.\n");

            }
        }
    } 
}

// Dirty Test
// Test rotation matrix with the maximum float value
void testAngleWithMaxFloatValue () {
  
    float expectedMatrix[4][4] = {{cos(1.17549E39), -sin(1.17549E39), 0, 0}, {sin(1.17549E39), cos(1.17549E39), 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}}; 
    
    generateZRotationMatrix (1.17549E39);

    for (int i = 0 ; i < 4 ; i++) {

        for (int j = 0 ; j < 4 ; j++) {

            if ((fabs (transformationMatrix[i][j] - expectedMatrix[i][j])) > 0.001) {

                printf ("Test rotation matrix with the maximum float value failed.\n");

            }
        }
    } 
}

// Dirty Test
// Test rotation matrix with the minimum float value
void testAngleWithMinFloatValue () {
  
    float expectedMatrix[4][4] = {{cos(-1.17549E-39), -sin(-1.17549E-39), 0, 0}, {sin(-1.17549E-39), cos(-1.17549E-39), 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}}; 

    generateZRotationMatrix (-1.17549E-39);

    for (int i = 0 ; i < 4 ; i++) {

        for (int j = 0 ; j < 4 ; j++) {

            if ((fabs (transformationMatrix[i][j] - expectedMatrix[i][j])) > 0.001) {

                printf ("Test rotation matrix with the minimum float value failed.\n");

            }
        }
    } 
}

// Dirty Test
// Test rotation matrix with squarerooted angle
void testAngleWithSqrt () {
  
    float expectedMatrix[4][4] = {{cos(sqrt(99)), -sin(sqrt(99)), 0, 0}, {sin(sqrt(99)), cos(sqrt(99)), 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}}; 
    
    generateZRotationMatrix (sqrt(99));

    for (int i = 0 ; i < 4 ; i++) {

        for (int j = 0 ; j < 4 ; j++) {

            if ((fabs (transformationMatrix[i][j] - expectedMatrix[i][j])) > 0.001) {

                printf ("Test rotation matrix with squarerooted angle failed.\n");

            }
        }
    } 
}

// Clean test
// Test vector with valid values for rotation matrix angle
void testValidVectors () {

    float expectedVector[4] = {0.9999, 0.0008, 2, 1};

    setZRotation(3.14/2);

    zRotation ();

    for (int i = 0 ; i < 4 ; i++) {

        if ((fabs ((getPoint(0) -> element[i]) - expectedVector[i])) > 0.001) {

            printf ("Test vector with valid values for rotation matrix angle failed.\n");

            return;

        }

    }

}
