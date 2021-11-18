#include "xyzOrthographicProjectionTests.h"

//xyzOrthographicProjection clean test with checks the current points
void xyzOrthographicProjectionTest1()
{

    xyzOrthographicProjection();
 
    for (int i = 0 ; i < inputShape->numOfPoints ; i++)
    {
        if (getPoint(i)->element[2] != 0)
        {
            printf("Function xyzOrthographicProjection: Test 1 failed,\n");
            printf("Expected 0, Found %f\n", getPoint(i)->element[2]);
            printf("\n");
        }
    }
}

//xyzOrthographicProjection test when there is only one point
void xyzOrthographicProjectionTest2()
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

    xyzOrthographicProjection();
    if (getPoint(0)->element[2] != 0)
    {
        printf("Function xyzOrthographicProjection: Test 2 failed,\n");
        printf("Expected 0, Found %f\n", getPoint(0)->element[2]);
        printf("\n");
    }
    
}

// Test with a large amount of points (1000 points)
void xyzOrthographicProjectionTest3()
{
    // Free old test points
    freeTestPoints();

    // Create new inputShape struct with 1000 testPoints
    createNTestPoints(1000);

    xyzOrthographicProjection();
    for (int i = 0 ; i < inputShape->numOfPoints; i++)
    {
        if (getPoint(i)->element[2] != 0)
        {
            printf("Function xyzOrthographicProjection: Test 3 failed,\n");
            printf("Expected 0, Found %f", getPoint(i)->element[2]);
            printf("\n");
            return;
        }
    }
}

//Function for running all tests
void xyzOrthographicProjectionRunTests()
{
    xyzOrthographicProjectionTest1();
    xyzOrthographicProjectionTest2();
    xyzOrthographicProjectionTest3();
}
