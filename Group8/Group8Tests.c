#include "Group8Tests.h"

void runGroup8Tests() {

    /*

        Function calls to the testValidAngles function that test if the generateZRotationMatrix works as it should for valid input. 
        The first two calls to this test function are the 'clean' tests because they are expected values 
        well in the range of possible parameters.
        The next three are the 'dirty' tests because they test more unlikely inputs such as angles given in scientific notation. These are all still valid inputs.
        All of the tests should be successful because the generateZRotationMatrix should accept any real number as a valid angle.

        float expected is a local variable that represents the expected matrix that the generateZRotationMatrix function should produce
        It's values are hard coded since they are known before the tests are run 
        (except sin and cos calculations which are done by calling the appropriate function from the math.h library)
        All of the values of the expected transformation matrix should have a value of 0 besides:
            index[0][0] = cos (angle)
            index[0][1] = -sin (angle)
            index[1][0] = sin (angle)
            index[1][1] = cos (angle)
            index[2][2] = 1
            index[3][3] = 1

    */
    float expected[4][4];

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            expected [i][j] = 0;
        }
    }

    expected[2][2] = 1;
    expected[3][3] = 1;

    // Initializing the values of the expected matrix and then testing the generateZRotationMatrix using an angle in radians of 0
    expected[0][0] = cos (0);
    expected[0][1] = -sin (0);
    expected[1][0] = sin (0);
    expected[1][1] = cos (0);
    setZRotation (0);
    testValidAngles (expected, getZRotation ());

    // Initializing the values of the expected matrix and then testing the generateZRotationMatrix using an angle in radians of 790.28
    expected[0][0] = cos (790.28);
    expected[0][1] = -sin (790.28);
    expected[1][0] = sin (790.28);
    expected[1][1] = cos (790.28);
    setZRotation (790.28);
    testValidAngles (expected, getZRotation ());

    // Initializing the values of the expected matrix and then testing the generateZRotationMatrix using an angle in radians of 1.17549E39
    expected[0][0] = cos (1.17549E39);
    expected[0][1] = -sin (1.17549E39);
    expected[1][0] = sin (1.17549E39);
    expected[1][1] = cos (1.17549E39);
    setZRotation (1.17549E39);
    testValidAngles (expected, getZRotation ());

    // Initializing the values of the expected matrix and then testing the generateZRotationMatrix using an angle in radians of -1.17549E-39
    expected[0][0] = cos (-1.17549E-39);
    expected[0][1] = -sin (-1.17549E-39);
    expected[1][0] = sin (-1.17549E-39);
    expected[1][1] = cos (-1.17549E-39);
    setZRotation (-1.17549E-39);
    testValidAngles (expected, getZRotation ());

    // Initializing the values of the expected matrix and then testing the generateZRotationMatrix using an angle in radians of sqrt(99)
    expected[0][0] = cos (sqrt(99));
    expected[0][1] = -sin (sqrt(99));
    expected[1][0] = sin (sqrt(99));
    expected[1][1] = cos (sqrt(99));
    setZRotation (sqrt(99));
    testValidAngles (expected, getZRotation ());

    // Finished testing valid angles


    /*

        Function calls to the testValidVectors function that test if the zRotation works as it should for valid input. 
        The call to this test function is a 'clean' tests because they are expected values 
        well in the range of possible parameters.
        
    */


        // The value of the global vector is initialized to match the vector that is being tested by the zRotation function
        // If the function works properly, these values will change to match the expected vector
    setZRotation(3.14/2);

    struct point tempVector;
    tempVector.element[0] = 1;
    tempVector.element[1] = 4;
    tempVector.element[2] = 2;
    tempVector.element[3] = 1;

    setPoint(0, &tempVector);

    // Initializing the values of the expected vector and then testing the zRotation on the vector [1, 4, 2 , 1] and the angle 3.14/2
    // The expected vector after rotation should have values of {4, -1, 2, 1}
    float expectedVector[4] = {-4, 1.0032, 2, 1};
    testValidVectors (expectedVector);

    //Finished valid vectors testing
}




/*

                                                 TESTING VALID ANGLES FUNCTION
 This test function will test the generateZRotationMatrix function using valid (real number) angles. The resulting matrix will be compared  
 with another matirx (that has the expected matrix values). If both matrices match meaning the generateZRotationMatrix worked properly, 
 nothing happens. If the actual transformationMatrix is different from the expected matrix, an error message is printed.              
 This test function will be run by passing a wide range of floating point values (including the minimum and maximum range values of floats) 

*/

void testValidAngles (float expectedTransformationMatrix[4][4], float theta) {

    int header = 0;

    generateZRotationMatrix (theta);

    for (int i = 0 ; i < 4 ; i++) {

        for (int j = 0 ; j < 4 ; j++) {

            if ((fabs (transformationMatrix[i][j] - expectedTransformationMatrix[i][j])) > 0.001) {

                if (header == 0) {

                    printf ("\nFUNCTION generateZRotationMatrix: VALID ANGLES TEST FAILED - theta = %f", theta);
                    header = 1;

                }

                printf ("\nExpected index[%d][%d] = %f\nActual index[%d][%d] = %f\n", i, j, expectedTransformationMatrix[i][j], i, j, transformationMatrix[i][j]);
            }
        }
    }    
}


/*

                                                 TESTING VALID VECTORS FUNCTION
 This test function will test the zRotation function using valid (real numbers) vectors. The resulting vectors will be compared with 
 the expected vectors values. If both vectors match meaning the zRotation worked properly, nothing happens. If the actual vector is 
 different from the expected vector, an error message is printed. 

*/

void testValidVectors (float expectedVector [4]) {

    zRotation ();

    for (int i = 0 ; i < 4 ; i++) {

        if ((fabs ((getPoint(0) -> element[i]) - expectedVector[i])) > 0.001) {

            printf ("\nVALID VECTOR TEST FAILED:\nExpected index[%d] = %f\nActual index[%d] = %f\n", i, expectedVector[i], i, (getPoint(0)) -> element[i]);

        }
    }


}
