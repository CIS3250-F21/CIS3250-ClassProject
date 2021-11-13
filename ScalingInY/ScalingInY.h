#ifndef Y_SCALING_H
#define Y_SCALING_H

#include "../main.h"

/*
 *  GROUP 4
 *  Ayden Panhuyzen   (1103150)
 *  Connor Schulz     (1103003)
 *  Jennifer Lithgow  (1134108)
 *  Sami Edaibis      (1133434)
 */

//==============================================================================
// Data Structures and Global Variables
//==============================================================================

/* Gets the Y scaling value */
float getYScale(void);

/* Sets the Y scaling value */
void setYScale(float newYScale);

/* Gets a point struct from a given index in the inputShape */
struct point * getPoint(int index);

/* Sets a point struct at a given index in the inputShape */
void setPoint(int index, struct point * newPoint);

//==============================================================================
//  Function to Test
//==============================================================================

/* Modifies the y value of each element of the point list by multiplying the
 * current y value by the y scale value*/
int yScaling(void);

//==============================================================================
//  Pre Test Cases
//==============================================================================

/* Tests that the getYScale function functions correctly*/
void testGetYScale(void);

/* Tests that the setYScale function functions correctly*/
void testSetYScale(void);

/* Tests that the getPoint function functions correctly*/
void testGetPoint(void);

/* Tests that the setPoint function functions correctly*/
void testSetPoint(void);

//==============================================================================
//  Post Test Cases
//==============================================================================

/*Helper functions*/

/* This function initializes the Y values for the first 5 vectors in the
 * vector array found in the 'vectors' field in inputShape. Values used (in
 * the order of array index) are 0, 1, -1, 100, -100 */
void initialisePoints(void);

/*Test functions*/

/* This test will attempt to run the yScaling function with an initialized scale
 * value but no initialized vectors. It is expected that the function will catch
 * the uninitialized value and return 0, indicating that the scale operation
 * could not be performed. */
void uninitialisedYPointTest(void);

/* This test will confirm that the yScaling function correctly computes and sets
 * the Y value for vectors when given a negative Y scale value. The expected
 * results for each of the Y vector values set in the initialiseVectors function
 * are 0, -22.0, 22.0, -2200.0, and 2200.0 respectively. */
void testNegativeScale(void);

/* This test will confirm that the yScaling function correctly computes and sets
 * the Y value for vectors when given a Y scale value of 0. The expected
 * results for all of the Y vector values set in the initialiseVectors function
 * are 0. */
void testZeroScale(void);

/* This test will confirm that the yScaling function correctly computes and sets
 * the Y value for vectors when given a positive Y scale value. The expected
 * results for each of the Y vector values set in the initialiseVectors function
 * are 0, 5, -5, 500, and -500 respectively. */
void testPositiveScale(void);

/* This test will confirm that the yScaling function correctly computes and sets
 * the Y value for vectors when given a fractional Y scale value. The expected
 * results for each of the Y vector values set in the initialiseVectors function
 * are 0, 0.5, -0.5, 50, and -50 respectively. */
void testFractionScale(void);

/* This function will run all the test cases defined above*/
void runAllScalingInYTests(void);

#endif
