#include "XYZOrthographicProjectionTests.h"

//XYZOrthographicProjection clean test that checks the current points. Fails if the 
//z column (third column of the matrix) has any point that is not equal to zero. Passes otherwise.
void XYZOrthographicProjectionTest1()
{

    XYZOrthographicProjection();
 
    for (int i = 0 ; i < inputShape->numOfPoints ; i++)
    {
        if (getPoint(i)->element[2] != 0)
        {
            printf("Function XYZOrthographicProjection: Test 1 failed,\n");
            printf("Expected 0, Found %f\n", getPoint(i)->element[2]);
            printf("\n");
        }
    }

    resetMatrix();
}

//XYZOrthographicProjection dirty test when there is only one point. Fails if the given
//single row of points does not have a zero in the third column. Passes otherwise.
void XYZOrthographicProjectionTest2()
{
    // Free old test points
    freeTestPoints();

    // Create new inputShape struct with 1000 testPoints
    createNTestPoints(1);
    
    // Save pointer to original point for freeing
    struct point * origPoint = getPoint(0);

    // Create new point for testing
    float testElements[4] = {823.2, 3.23, 90.41, 1};
    struct point * testPoint = malloc (sizeof(struct point));

    for (int i = 0 ; i < 4 ; i++)
    {
        testPoint->element[i] = testElements[i];
    }
    setPoint(0, testPoint);
    free( origPoint );

    XYZOrthographicProjection();
    if (getPoint(0)->element[2] != 0)
    {
        printf("Function XYZOrthographicProjection: Test 2 failed,\n");
        printf("Expected 0, Found %f\n", getPoint(0)->element[2]);
        printf("\n");
    }
    resetMatrix();
    
}

// XYZOrthographicProjection dirty test with a large amount of points (1000 points). Fails
// if any of the thousand points within the third column is not equal to zero. Passes otherwise. 
void XYZOrthographicProjectionTest3()
{
    // Free old test points
    freeTestPoints();

    // Create new inputShape struct with 1000 testPoints
    createNTestPoints(1000);

    XYZOrthographicProjection();
    for (int i = 0 ; i < inputShape->numOfPoints; i++)
    {
        if (getPoint(i)->element[2] != 0)
        {
            printf("Function XYZOrthographicProjection: Test 3 failed,\n");
            printf("Expected 0, Found %f", getPoint(i)->element[2]);
            printf("\n");
            return;
        }
    }

    resetMatrix();
}

//Function for running all tests
void XYZOrthographicProjectionRunTests()
{
    XYZOrthographicProjectionTest1();
    XYZOrthographicProjectionTest2();
    XYZOrthographicProjectionTest3();
}
