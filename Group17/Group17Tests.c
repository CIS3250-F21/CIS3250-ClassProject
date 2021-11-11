#include "Group17Tests.h"

void runGroup17Tests () {
    // store prev points
    struct point** oldPoints = inputShape->points;
    int oldNumOfPoints = inputShape->numOfPoints;

    // allocate space for temp points
    inputShape->points = malloc((sizeof(struct point*)) * 10);
    inputShape->numOfPoints = 0;

    FILE* fp;
    float x, y, z, s;
  
    // Clean Tests
  
    /* 
     * Test Case 1.1 - Passing valid point and filename
     *
     * Input:
     *  - Point: [2.0, 1.0, 3.0, 1.0] 
     *  - Filename: "output1.1.txt"
     *
     * Expected Outcome:
     *  - The function should return 1
     *  - A file "output1.1.txt" should be created which
     *    stores the X, Y, Z values of the point
     */

    // Initialize point with input values
    struct point testPoint = {
        .element = {2.0f, 1.0f, 3.0f, 1.0f}
    };

    // add point to shape
    inputShape->numOfPoints = 1;
    setPoint(0, &testPoint);

    // Call the outputPoints function with the input paramters
    if (outputPoints("output1.1.txt") != 1) {
        printf("[Test 1.1] Return value is not 1\n");
    }

    // Check if the file was created and test its values
    if ((fp = fopen("output1.1.txt", "r")) == NULL) {
        printf("[Test 1.1] File \"output1.1.txt\" does not exist\n");
    }
    else {
        // read values from file
        fscanf(fp, "%f %f %f %f", &x, &y, &z, &s);
        
        // Check if values match
        if (x != testPoint.element[0] || y != testPoint.element[1] || z != testPoint.element[2] || (s - 1.0f) > 0.001) {
            printf("[Test 1.1] Incorrect point values for test point\n");
        }
        
        fclose(fp);
    }

    // delete file 
    remove("output1.1.txt");

    // Dirty Tests

    /*
     * Test Case 2.1 - Outputting with no points in shape
     * Input:
     *  - Shape: []
     *  - Filename: "output2.1.txt"
     *
     * Expected Output:
     *  - This function returns 0 because the input shape does  
     *    not contain any values
     */

    inputShape->numOfPoints = 0;
    
    if (outputPoints("output2.1.txt") != 0) {
        printf("[Test 2.1] Return value is not 0\n");
    }

    // delete file if created
    remove("output2.1.txt");

    /*
     * Test Case 2.2 - Passing an NULL pointer as the filename
     *
     * Input:
     * - Point: [2.0, 1.0, 3.0, 1.0] 
     * - Filename: NULL;
     *
     * Expected Output:
     * - The function should return 0 since the filename is NULL
     */

    struct point testPoint2 = {
        .element = {2.0f, 1.0f, 3.0f, 1.0f}
    };

    // add point to shape
    inputShape->numOfPoints = 1;
    setPoint(0, &testPoint2);
    
    // call outputMatrix function with filename
    if (outputPoints(NULL) != 0) {
        printf("[Test 2.2] Return value is not 0\n");
    }
    
    /*
     * Test Case 2.3 - Passing an empty string as the filename
     *
     * Input:
     *  - Point: [2.0, 1.0, 3.0, 1.0] 
     *  - Filename: ""
     *
     * Expected Output:
     *  - The function should return 0 since the file is invalid
     */
    
    // call outputPoints function with empty string as filename
    if (outputPoints("") != 0) {
        printf("[Test 2.3] Return value is not 0\n");
    }

    /*
     * Test Case 2.4 - Outputing a NULL Point
     *
     * Input:
     *  - Point: NULL 
     *  - filename: "output2.4.txt"
     *
     * Expected Output:
     *  - The function should return 0
     */

    // add point to shape
    inputShape->numOfPoints = 1;
    inputShape->points[0] = NULL;

    // call function with input
    if (outputPoints("output2.4.txt") != 0) {
        printf("[Test 2.4] Return value was not 0\n");
    }
    
    // delete file if exists
    remove("output2.4.txt");

    /*
     * Test Case 2.5 - Outputting to a file multiple times
     *
     * Input:
     *  - Point 1: [255.0, 255.0, 255.0, 1.0] 
     *  - Point 2: [1.0, 2.0, 3.0, 1.0] 
     *  - Filename: "output2.5.txt"
     *
     * Expected Outcome:
     *  - A file "output2.5.txt" should be created which stores the 
     *    values of the last shape output.
     */  
    
    // initialize two matrices with different values
    struct point testPoint4 = {
        .element = {255.0f, 255.0f, 255.0f, 1.0f}
    };

    struct point testPoint5 = {
        .element = {1.0f, 2.0f, 3.0f, 1.0f}
    };

    struct point testPoint6 = {
        .element = {-255.0f, 0.0f, 121.0f, 1.0f}
    };

    struct point testPoint7 = {
        .element = {132.0f, 1.0f, -13.0f, 1.0f}
    };


    inputShape->numOfPoints = 2;
    setPoint(0, &testPoint4);
    setPoint(1, &testPoint5);

    // output first shape to file
    if (outputPoints("output2.5.txt") != 1) {
        printf("[Test 2.5] Failed to output points 4 and 5\n");
    }
    
    setPoint(0, &testPoint6);
    setPoint(1, &testPoint7);

    // output second shape to file
    if (outputPoints("output2.5.txt") != 1) {
        printf("[Test 2.5] Failed to output points 6 and 7\n");
    }

    // Check if the file was created and test its values
    if ((fp = fopen("output2.5.txt", "r")) == NULL) {
        printf("[Test 2.5] File \"output2.5.txt\" does not exist\n");
    }
    else {
        // read first point from file
        fscanf(fp, "%f %f %f %f", &x, &y, &z, &s);

        // Check if values match for test point 6
        if (
            x != testPoint6.element[0] || 
            y != testPoint6.element[1] || 
            z != testPoint6.element[2] || 
            (s - 1.0f) > 0.01
        ) {
            printf("[Test 2.5] Incorrect values for test point 6\n");
        }
        else {
            // read second point from file
            fscanf(fp, "%f %f %f %f", &x, &y, &z, &s);

            // check if values match for test point 7
            if (
                x != testPoint7.element[0] ||
                y != testPoint7.element[1] || 
                z != testPoint7.element[2] || 
                (s - 1.0f) > 0.01
            ) {
                printf("[Test 2.5] Incorrect values for test point 7\n");
            }
        }
    }
    
    fclose(fp);
    // delete file
    remove("output2.5.txt");

    // free temp points
    free(inputShape->points);

    // replace old points
    inputShape->points = oldPoints;
    inputShape->numOfPoints = oldNumOfPoints;
}
