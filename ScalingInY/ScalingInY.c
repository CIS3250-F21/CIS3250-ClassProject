#include "ScalingInY.h"

/*
 *  GROUP 4
 *  Ayden Panhuyzen   (1103150)
 *  Connor Schulz     (1103003)
 *  Jennifer Lithgow  (1134108)
 *  Sami Edaibis      (1133434)
 */

/* Modifies the y value of each element of the point list by multiplying the
 * current y value by the y scale value*/
int yScaling() {
    struct point *curPoint;      // Holds current point
    float yScale = getYScale();  // Y scale used to modify points

    // Iterate through each point in the point array and update the y value by
    // multiplying it by the yScale value.
    for (int curIndex = 0; curIndex < inputShape->numOfPoints; curIndex++) {
        curPoint = getPoint(curIndex);

        if (curPoint == NULL) {
            // point at this index is not initialised
            fprintf(stderr, "ERROR: Could not perform yScaling function as point at index %d was NULL.\n", curIndex);
            return 0;
        }

        curPoint->element[1] *= yScale;
        setPoint(curIndex, curPoint);
    }
    return 1;
}
