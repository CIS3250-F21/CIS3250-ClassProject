#include "main.h"
//~~~~~~ Class Includes ~~~~~~//
#include "Group1/Group1.h"
#include "Group10/Group10.h"
#include "Group11/Group11.h"
#include "Group12/Group12.h"
#include "Group13/Group13.h"
#include "Group14/Group14.h"
#include "Group15/Group15.h"
#include "Group16/Group16.h"
#include "Group17/Group17.h"
#include "Group2/Group2.h"
#include "Group3/Group3.h"
#include "Group4/Group4.h"
#include "Group5/Group5.h"
#include "Group6/Group6.h"
#include "Group7/Group7.h"
#include "Group8/Group8.h"
#include "Group9/Group9.h"

int main(int argc, char** argv) {
    fileName = malloc(sizeof(char) * 10);
    strcpy(fileName, "shape.txt");

    //~~~~~ Group 1 ~~~~~//
    inputShape = shapeInputs(fileName);

    //~~~~~ Group 2 ~~~~~//
    void globalScaling();

    //~~~~~ Group 3 ~~~~~//
    void xScaling();

    //~~~~~ Group 4 ~~~~~//
    void yScaling();

    //~~~~~ Group 5 ~~~~~//
    void zScaling();

    //~~~~~ Group 6 ~~~~~//
    void xRotation();

    //~~~~~ Group 7 ~~~~~//
    void yRotation();

    //~~~~~ Group 8 ~~~~~//
    void zRotation();

    //~~~~~ Group 9 ~~~~~//
    void xyzTranslation();

    //~~~~~ Group 10 ~~~~~//
    void xPlaneReflection();

    //~~~~~ Group 11 ~~~~~//
    void yPlaneReflection();

    //~~~~~ Group 12 ~~~~~//
    void zPlaneReflection();

    //~~~~~ Group 13 ~~~~~//
    void xShear();

    //~~~~~ Group 14 ~~~~~//
    void yShear();

    //~~~~~ Group 15 ~~~~~//
    void zShear();

    //~~~~~ Group 16 ~~~~~//
    void xyzOrthographicProjection();

    //~~~~~ Group 17 ~~~~~//
    int outputVector(struct vector * finalVector, char* filename);

    return 0;
}