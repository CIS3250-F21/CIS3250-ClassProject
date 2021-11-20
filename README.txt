==========================================
Transforming Shapes Through Matrix Multiplication
==========================================

Description of functionality:

This project transforms a shape (which is expressed as a set of points) according to the parameters provided. 

https://docs.google.com/document/d/1p10rx8R_3oGFU1SiKOWELDZhxhAfR2k61Vg8fF_Rl34/edit


Instructions to run the file:

After using the make command, the following command should run the program,
./final inputShapeFile.csv inputTransformation.txt ouputShapeFile.csv

Format for Input and Output files:

inputShapeFile.csv and ouputShapeFile.csv:

Where each column of the file corresponds to the heading for its value ex. 

X,Y,Z,L
1.121,1.003,1.2,1.00
2,3,4,1
0,0,0,1
1,0,0,1
0,1,0,1
0,0,1,1

Where for the first point X = 1.121 Y = 1.003, Z = 1.2 and  L = 1.00 

inputTransformation.txt:

This is the configuration file that contains all the parameter values for all the functions. For example:

setGlobalScale=1
setXScale=1
setYScale=1
setZScale=1
setXRotation=0
setYRotation=0
setZRotation=0
setXTranslation=0
setYTranslation=0
setZTranslation=0
setXReflection=0
setYReflection=0
setZReflection=0
setXshear=0
setYshear=0
setZshear=0
setOrthographic=1

Where each corresponds to a transformation with the following limitations and functionality:

setGlobalScale

This value handles the scaling of all values inside of a point where the value passed in must be greater than zero.

setXScale
setYScale
setZScale

This value handles the scaling of each individual x y z coordinate individually to scale all the points.

setXRotation
setYRotation
setZRotation

This value handles the rotation of  points about each axis based on a supplied angle which is in degrees.

setXTranslation
setYTranslation
setZTranslation

This value handles the translation of  points in the x, y and z directions where there is no restrictions on these values.

setXReflection
setYReflection
setZReflection

These are boolean values that represent if the shape has to be flipped (1) or not (0) in the x, y and z direction.


setXshear
setYshear
setZshear

These values correspond to the x, y and z shears on a point where they will transform the function by squashing or pulling it in a direction.


setOrthographic

This is a  boolean value that represents if the shape has to be projected orthographically (1) or not (0).
