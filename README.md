# CIS3250

This is the massive repository for all code for the class CIS3250 Fall Semester.

[Link To Document](https://docs.google.com/document/d/1p10rx8R_3oGFU1SiKOWELDZhxhAfR2k61Vg8fF_Rl34/edit?usp=sharing)

## Branches

**_NOTE: Only push/pull and work within your own branch_**<br>
When making a pull request please try and make it the final version of your code to help reduce the frequency of code review. Obviously if changes need to be made, feel free to do so. Once you submit a pull request one or multiple admins will look through it, and we may ask to setup a time to meet if we have any questions or would like to talk about your code.<br>

### Before you make a pull request

Please compile using "make" to make sure all of your functions and tests compile properly. Please also run a Valgrind check and make sure there are no memory leaks/uninitialized jumps. The command is below.

> valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./main inputShapeFile.csv inputTransformation.txt test.csv

## Group File

1. Put all of your group specific functions in your specific files. Change them from Group# to what you see fit.
2. We already have you getters and setters defined, please put your code inside of the functions, and **_do not_** change anything else inside of main.c or main.h.

## Tests

1. Your test functions can go in your testing files, inside your folder. Rename them from Group# to what you see fit.
2. Please name the function that runs all of your tests runFunctionNameTests(), where "FunctionName" is renamed based on the function's name.
3. If you have a test handler, rename it to functionNameTestHandler() (see previous for renaming).

## Naming Conventions

| Type         | Style          |
| ------------ | -------------- |
| Variables    | camelCase      |
| Functions    | UpperCamelCase |
| Globals      | CAPTITAL_CASE  |
| Curly Braces | New Line       |
| File Name    | UpperCamelCase |

## Changes:

1. Changed any mention of Vectors to Points
2. Changed transformation matrix to a static array
3. Changed ScalingInY to return an int (1 if successfully transforms, 0 if it fails any)
4. Added `reflection[3]` and `orthographic` to shape struct to house check variables (to see if theyre on or off)
5. Added getters & setters for X,Y,Z reflection & orthographic check variables

## Input/Output File Format

- The input and output files are in csv Format
  - The first line in the file is a header "X,Y,Z,L" which describes what each value in the subsequent lines represents.
  - Each remaining line contains a set of 4 values separated by commas representing the X, Y and Z values and
    the scalar of the point.

## How to Run

1. run `make`
2. run ./main with the following structure:
`./main <inputfile> <tranformationfile> <outputfile>`

## yScaling (ScalingInY.c) Functionality
Retrives the yScale value. Using a loop to cycle through the points, yScaling retrieves a point, multiplies the y value (index 1 of the point) by yScale, and stores the new value.

## globalScaling (GlobalScaling.c) Functionality
Retrives the global scale value. Using a loop to cycle through the points, globalScaling retrieves the 4th point multiplies it by the global scale value. If the fourth point is not equal to 1, then divide every point by the fourth point and store the new values.

