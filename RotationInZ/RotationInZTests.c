#include "RotationInZTests.h"

//Runs tests
void runRotationInZTests() {

    testAngleEqualtoZero ();
    testAnglesWithDecimalPlaces ();
    testAngleWithMaxFloatValue ();
    testAngleWithMinFloatValue ();
    testAngleWithSqrt ();
    testValidPoints ();

}

// Clean test
// Test rotation matrix with an angel equavalent to zero
void testAngleEqualtoZero () {
  
    // Initialize the expected matrix values so it can be used in comparison with the actual matrix
    float expectedMatrix[4][4] = {{cos(0), -sin(0), 0, 0}, {sin(0), cos(0), 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}}; 


    // Call the generateZRotationMatrix with an angle of 0 so the actual matrix can be generated
    // The for loops go through the points in both matrices and compares the value of each point (with a margin of erroe of 0.001 to account for floating point comparison)
    // If any of the values in the matrices are different, an error message is printed our indicating the test failed. I the test is successful, nothing further happens
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
  
    // Initialize the expected matrix values so it can be used in comparison with the actual matrix
    float expectedMatrix[4][4] = {{cos(790.28), -sin(790.28), 0, 0}, {sin(790.28), cos(790.28), 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}}; 

    // Call the generateZRotationMatrix with an angle of 790.28 so the actual matrix can be generated
    // The for loops go through the points in both matrices and compares the value of each point (with a margin of erroe of 0.001 to account for floating point comparison)
    // If any of the values in the matrices are different, an error message is printed our indicating the test failed. I the test is successful, nothing further happens
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
  
    // Initialize the expected matrix values so it can be used in comparison with the actual matrix
    float expectedMatrix[4][4] = {{cos(1.17549E39), -sin(1.17549E39), 0, 0}, {sin(1.17549E39), cos(1.17549E39), 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}}; 
    
    // Call the generateZRotationMatrix with an angle of 1.17549E39 so the actual matrix can be generated
    // The for loops go through the points in both matrices and compares the value of each point (with a margin of erroe of 0.001 to account for floating point comparison)
    // If any of the values in the matrices are different, an error message is printed our indicating the test failed. I the test is successful, nothing further happens
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
  
    // Initialize the expected matrix values so it can be used in comparison with the actual matrix
    float expectedMatrix[4][4] = {{cos(-1.17549E-39), -sin(-1.17549E-39), 0, 0}, {sin(-1.17549E-39), cos(-1.17549E-39), 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}}; 

    // Call the generateZRotationMatrix with an angle of -1.17549E-39 so the actual matrix can be generated
    // The for loops go through the points in both matrices and compares the value of each point (with a margin of erroe of 0.001 to account for floating point comparison)
    // If any of the values in the matrices are different, an error message is printed our indicating the test failed. I the test is successful, nothing further happens
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
  
    // Initialize the expected matrix values so it can be used in comparison with the actual matrix
    float expectedMatrix[4][4] = {{cos(sqrt(99)), -sin(sqrt(99)), 0, 0}, {sin(sqrt(99)), cos(sqrt(99)), 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}}; 
    
    // Call the generateZRotationMatrix with an angle of sqrt(99) so the actual matrix can be generated
    // The for loops go through the points in both matrices and compares the value of each point (with a margin of erroe of 0.001 to account for floating point comparison)
    // If any of the values in the matrices are different, an error message is printed our indicating the test failed. I the test is successful, nothing further happens
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
// Test point with valid values and an angle of rotation of 3.14/2
void testValidPoints () {

    // Initialize the expected point values so it can be used in comparison with the actual point
    float expectedPoint[4] = {0.9999, 0.0008, 2, 1};

    
    setZRotation(3.14/2);

    // Call the zRotation function so the points can be rotated with an angle of 3.14/2
    // The for loop goes through the elements in both points and compares the value of each element (with a margin of erroe of 0.001 to account for floating point comparison)
    // If any of the values in the points are different, an error message is printed our indicating the test failed. I the test is successful, nothing further happens
    zRotation ();

    for (int i = 0 ; i < 4 ; i++) {

        if ((fabs ((getPoint(0) -> element[i]) - expectedPoint[i])) > 0.001) {

            printf ("Test point with valid values for rotation matrix angle failed.\n");

            return;

        }

    }

}
