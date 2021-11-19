#include "ScalingInY.h"

/* yScaling modifies the y value of each element of the point list by multiplying the
 * current y value by the y scale value
 * Looking at transformation from https://www.tutorialspoint.com/computer_graphics/3d_transformation.htm:
 * Vector P = [x y z 1]
 * Scaling factor S = 
 *  | Sx 0  0  0 |
 *  | 0  Sy 0  0 |
 *  | 0  0  Sz 0 |
 *  | 0  0  0  1 |
 * P' = P.S
 * P' = [x.Sx  y.Sy  z.Sz  1]
 * In case of yScaling, x and z are not transformed (meaning Sx = Sz = 1)
 * P' = [x(1)  y.Sy  z(1)  1]
 * Since only y is modified by a variable value, yScaling transforms the matrix by focusing on
 * only the y value of the point
 */
void yScaling() {
    struct point *curPoint;      // Holds current point
    float yScale = getYScale();  // Y scale used to modify points

    // Iterate through each point in the point array and update the y value by
    // multiplying it by the yScale value.
    for (int curIndex = 0; curIndex < inputShape->numOfPoints; curIndex++) {
        curPoint = getPoint(curIndex);
        curPoint->element[1] *= yScale;
        // Set point back to transformed value
        setPoint(curIndex, curPoint);
    }
}
