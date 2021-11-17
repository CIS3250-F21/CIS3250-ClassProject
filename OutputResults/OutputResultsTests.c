#include "OutputResultsTests.h"

void runOutputResultsTests () {
    // store prev points
    struct point** oldPoints = inputShape->points;
    int oldNumOfPoints = inputShape->numOfPoints;

    // allocate space for temp points
    inputShape->points = malloc((sizeof(struct point*)) * 10);
    inputShape->numOfPoints = 0;

    FILE* fp;
    float x, y, z;
    char buffer[BUFSIZ];
  
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
    inputShape->points[1] = NULL; // directly set end of array

    // Call the outputPoints function with the input paramters
    if (outputPoints("output1.1.txt") != 1) {
        fprintf(stderr, "[Test 17.1.1] Return value is not 1 (%s:%d)\n", __FILE__, __LINE__);
    }

    // Check if the file was created and test its values
    if ((fp = fopen("output1.1.txt", "r")) == NULL) {
        fprintf(stderr, "[Test 17.1.1] File \"output1.1.txt\" does not exist (%s:%d)\n", __FILE__, __LINE__);
    }
    else {
        // read header
        fgets(buffer, BUFSIZ, fp);
        // read values from file
        fscanf(fp, "%f,%f,%f", &x, &y, &z);
        
        // Check if values match
        if (x != testPoint.element[0] || y != testPoint.element[1] || z != testPoint.element[2]) {
            fprintf(stderr, "[Test 17.1.1] Incorrect point values for test point (%s:%d)\n", __FILE__, __LINE__);
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
     *  - This function returns 1
     *  - A file "output2.1.txt" should be created which contains no data
     */

    // remove testPoint 1
    inputShape->points[0] = NULL;
    inputShape->numOfPoints = 0;
    
    
    if (outputPoints("output2.1.txt") != 1) {
        fprintf(stderr, "[Test 17.2.1] Return value is not 1 (%s:%d)\n", __FILE__, __LINE__);
    }

    if ((fp = fopen("output2.1.txt", "r")) == NULL) {
        fprintf(stderr, "[Test 17.2.1] File \"output2.1.txt\" does not exist (%s:%d)\n", __FILE__, __LINE__);
    }
    else {
        // read the header
        fgets(buffer, BUFSIZ, fp);

        // check if the end of the file
        if (fgetc(fp) != EOF) {
            fprintf(stderr, "[Test 17.2.1] Expected empty file but file has data (%s:%d)\n", __FILE__, __LINE__);
        }

        fclose(fp);
    }

    // delete file if created
    remove("output2.1.txt");

    /*
     * Test Case 2.2 - Outputing with NULL between two points
     *
     * Input:
     *  - Points
            - Point 0: [32.0, -45.0, 0.0, 1.0]
            - Point 1: NULL
            - Point 2: [-255.0, 45.0, 100.0, 1.0]
     *  - filename: "output2.2.txt"
     *
     * Expected Output:
     *  - The function should return 1.
     *  - A file "output2.2.txt" should be generated which stores
     *    the X, Y, Z information for the first point only
     */

    // set number of points to 1
    inputShape->numOfPoints = 3;

    struct point testPoint2 = {
        .element = {32.0f -45.0f, 0.0f, 1.0f}
    };

    struct point testPoint3 = {
        .element = {-255.0f, 45.0f, 100.0f, 1.0f}
    };

    // add points to shape
    setPoint(0, &testPoint2);
    // point 1 is NULL from previous test
    setPoint(2, &testPoint3);

    // call function with input
    if (outputPoints("output2.2.txt") != 1) {
        fprintf(stderr, "[Test 17.2.2] Return value was not 1 (%s:%d)\n", __FILE__, __LINE__);
    }

    // open file
    if((fp = fopen("output2.2.txt", "r")) == NULL) {
        fprintf(stderr, "[Test 17.2.2] Error file \"output2.2.txt\" does not exist (%s:%d)\n", __FILE__, __LINE__);
    }
    else {
        // read header
        fgets(buffer, BUFSIZ, fp);

        // read first point
        if ((fscanf(fp,"%f,%f,%f\n", &x, &y, &z)) != 3) {
            fprintf(stderr, "[Test 17.2.2] Error reading points from file (%s:%d)\n", __FILE__, __LINE__);
        }
        else {
            // check if the points match testPoint2
            if (
                x != testPoint2.element[0] ||
                y != testPoint2.element[1] ||
                z != testPoint2.element[2]
            ) {
                fprintf(stderr, "[Test 17.2.2] Error points do not match test point 2 (%s:%d)\n", __FILE__, __LINE__);
            }

            // check if end of file
            if (!feof(fp)) {
                fprintf(stderr, "[Test 17.2.2] Error expected one point but found multiple (%s:%d)\n", __FILE__, __LINE__);
            }
        }

        fclose(fp);
    }

    // remove output2.2.txt if created
    remove("output2.2.txt");

    /*
     * Test Case 2.3 - Passing an NULL pointer as the filename
     *
     * Input:
     * - Point: [2.0, 1.0, 3.0, 1.0] 
     * - Filename: NULL;
     *
     * Expected Output:
     * - The function should return 0 since the filename is NULL
     */

    struct point testPoint4 = {
        .element = {2.0f, 1.0f, 3.0f, 1.0f}
    };

    // add point to shape
    inputShape->numOfPoints = 1;
    setPoint(0, &testPoint4);
    inputShape->points[1] = NULL; // directly set end of array
    
    // call outputMatrix function with filename
    if (outputPoints(NULL) != 0) {
        fprintf(stderr, "[Test 17.2.3] Return value is not 0 (%s:%d)\n", __FILE__, __LINE__);
    }
    
    
    /*
     * Test Case 2.4 - Passing an empty string as the filename
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
        fprintf(stderr, "[Test 17.2.4] Return value is not 0 (%s:%d)\n", __FILE__, __LINE__);
    }


    /*
     * Test Case 2.5 - Outputting to a file multiple times
     *
     * Input:
     *  - Points:
     *      - Point 1: [255.0, 255.0, 255.0, 1.0] 
     *      - Point 2: [1.0, 2.0, 3.0, 1.0] 
     *      - Point 3: [-255.0, 0.0, 121.0, 1.0]
     *      - Point 4: [132.0, 1.0, -13.0, 1.0]
     *  - Filename: "output2.5.txt"
     *
     * Expected Outcome:
     *  - A file "output2.5.txt" should be created which stores the 
     *    values of the last shape output.
     */  
    
    // initialize 4 points with different values
    struct point testPoint5 = {
        .element = {255.0f, 255.0f, 255.0f, 1.0f}
    };

    struct point testPoint6 = {
        .element = {1.0f, 2.0f, 3.0f, 1.0f}
    };

    struct point testPoint7 = {
        .element = {-255.0f, 0.0f, 121.0f, 1.0f}
    };

    struct point testPoint8 = {
        .element = {132.0f, 1.0f, -13.0f, 1.0f}
    };

    // add points 5 and 6 to the inputShape
    inputShape->numOfPoints = 2;
    inputShape->points[2] = NULL; // set end of array

    setPoint(0, &testPoint5);
    setPoint(1, &testPoint6);

    // output first shape to file
    if (outputPoints("output2.5.txt") != 1) {
        fprintf(stderr, "[Test 17.2.5] Failed to output points 5 and 6 (%s:%d)\n", __FILE__, __LINE__);
    }
    
    // replace points 5 and 6 with 7 and 8 respectively
    setPoint(0, &testPoint7);
    setPoint(1, &testPoint8);

    // output second shape to file
    if (outputPoints("output2.5.txt") != 1) {
        fprintf(stderr, "[Test 17.2.5] Failed to output points 7 and 8 (%s:%d)\n", __FILE__, __LINE__);
    }

    // Check if the file was created and test its values
    if ((fp = fopen("output2.5.txt", "r")) == NULL) {
        fprintf(stderr, "[Test 17.2.5] File \"output2.5.txt\" does not exist (%s:%d)\n", __FILE__, __LINE__);
    }
    else {
        // read header
        fgets(buffer, BUFSIZ, fp);

        // read first point from file
        if(fscanf(fp, "%f,%f,%f\n", &x, &y, &z) != 3) {
            fprintf(stderr, "[Test 17.2.5] Error reading values for test point 7 (%s:%d)\n", __FILE__, __LINE__);
        }
        else {
            // Check if values match for test point 7
            if (
                x != testPoint7.element[0] || 
                y != testPoint7.element[1] || 
                z != testPoint7.element[2]
            ) {
                fprintf(stderr, "[Test 17.2.5] Incorrect values for test point 7 (%s:%d)\n", __FILE__, __LINE__);
            }
        }

        // read second point from file
        if(fscanf(fp, "%f,%f,%f\n", &x, &y, &z) != 3) {
            fprintf(stderr, "[Test 17.2.5] Error reading values for test point 8 (%s:%d)\n", __FILE__, __LINE__);
        }
        else {
            // check if values match for test point 8
            if (
                x != testPoint8.element[0] ||
                y != testPoint8.element[1] || 
                z != testPoint8.element[2]
            ) {
                fprintf(stderr, "[Test 17.2.5] Incorrect values for test point 8 (%s:%d)\n", __FILE__, __LINE__);
            }
        }

        // check if only 2 points
        if (!feof(fp)) {
            fprintf(stderr, "[Test 17.2.5] Expected end of file (%s:%d)\n", __FILE__, __LINE__);
        }

        fclose(fp);
    }

    // delete file if created
    remove("output2.5.txt");

    // free temp points
    free(inputShape->points);

    // replace old points
    inputShape->points = oldPoints;
    inputShape->numOfPoints = oldNumOfPoints;
}
