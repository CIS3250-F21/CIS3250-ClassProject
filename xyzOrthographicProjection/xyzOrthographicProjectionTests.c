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
    
    float testElements[4] = {823.2, 3.23, 90.41, 1.0};
    struct point testPoints[1];
    struct point ** tempPoints = inputShape->points; //create a copy of the original points struct
    int tempNum = inputShape->numOfPoints; //create a copy of the original number of points

        for (int i = 0 ; i < 4 ; i++)
        {
            testPoints->element[i] = testElements[i];
        }

    inputShape->numOfPoints = 1;
    setPoint(0, &testPoints[0]);
    
    xyzOrthographicProjection();
  
        if (getPoint(0)->element[2] != 0)
        {
            printf("Function xyzOrthographicProjection: Test 2 failed,\n");
            printf("Expected 0, Found %f\n", getPoint(0)->element[2]);
            printf("\n");
        }

    inputShape->numOfPoints = tempNum; //restore the original number of points
    inputShape->points = tempPoints; //restore the original points struct
    free(tempPoints);
}

// Test with a large amount of points (1000 points)
void xyzOrthographicProjectionTest3()
{

    struct point * testPoints[1000];
    struct point ** tempPoints = inputShape->points; //create a copy of the original points struct
    int tempNum = inputShape->numOfPoints; //create a copy of the original number of points
    inputShape->numOfPoints = 1000;
  
    for (int i = 0 ; i < inputShape->numOfPoints ; i++)
    {

        for (int j = 0 ; j < 4 ; j++)
        {
            testPoints[i]->element[j] = (float)i;
        }

        setPoint(i, &testPoints[i]);
        
    }
    
    xyzOrthographicProjection();
    for (int l = 0 ; l < inputShape->numOfPoints; l++)
    {
        if (getPoint(l)->element[2] != 0)
        {
            printf("Function xyzOrthographicProjection: Test 3 failed,\n");
            printf("Expected 0, Found %f", getPoint(l)->element[2]);
            printf("\n");
            return;
        }
    }
    inputShape->numOfPoints = tempNum; //restore the original number of points
    inputShape->points = tempPoints; //restore the original points struct
    //free(tempPoints);
}

//Function for running all tests
void xyzOrthographicProjectionRunTests()
{
    xyzOrthographicProjectionTest1();
    xyzOrthographicProjectionTest2();
    xyzOrthographicProjectionTest3();
}
