#include "main.h"
//~~~~~~ Class Includes ~~~~~~//
#include "groupIncludes.h"
#include "groupTestIncludes.h"

int main(int argc, char** argv) {
    // Run tests if need be
    if (argc == 2 && strcmp(argv[1], "-t") == 0) {
        runAllTests();
    } else if (argc == 4) {
        char * inputFileName = argv[1];
        char * transformationFileName = argv[2]; 
        char * outputFileName = argv[3];
        
        //~~~~~ Reading file input ~~~~~//
        readInput(inputFileName, transformationFileName);

        //~~~~~ Global scaling ~~~~~//
        globalScaling();

        //~~~~~ Scaling in the x axis ~~~~~//
        xScaling();

        //~~~~~ Scaling in the y axis ~~~~~//
        yScaling();

        //~~~~~ Scaling in the z axis ~~~~~//
        zScaling();

        //~~~~~ Rotate in the x axis ~~~~~//
        xRotation();

        //~~~~~ Rotate in the x axis ~~~~~//
        yRotation();

        //~~~~~ Rotate in the x axis ~~~~~//
        zRotation();

        //~~~~~ Translation ~~~~~//
        XYZTranslation();

        //~~~~~ Reflection on the x plane ~~~~~//
        if( getXReflection() == 1 ) {
            ReflectionInXPlane();
        }

        //~~~~~ Reflection on the y plane ~~~~~//
        if( getYReflection() == 1 ) {
            yPlaneReflection();
        }

        //~~~~~ Reflection on the z plane ~~~~~//
        if( getZReflection() == 1) {
            ZPlaneReflection();
        }

        //~~~~~ x shearing ~~~~~//
        xShear();

        //~~~~~ y shearing ~~~~~//
        yShear();

        //~~~~~ z shearing ~~~~~//
        zShear();

        //~~~~~ Orthographic projection ~~~~~//
        if( getOrthographic() == 1 ) {
            XYZOrthographicProjection();
        }

        //~~~~~ Writing output file ~~~~~//
        outputPoints(outputFileName);


        // free all non null points
        for (int i = 0; i < inputShape->numOfPoints; i++) {
            if (inputShape->points[i] != NULL) {
                free(inputShape->points[i]);
            }
        }
        
        // free points array
        free(inputShape->points);

        // free shape
        free(inputShape);
    }
    else {
        fprintf(stderr, "Format %s <input file> <transformation file> <output file>\n", argv[0]);
        return 1;
    }
    return 0;
}

// ~~~~~~~~~~~~~~~~~ Getters ~~~~~~~~~~~~~~~~~~~ //

struct point* getPoint(int index) {
    // if the index is less then 0 or greater the the number of points, or the points are null
    if ((index < 0) || (index >= inputShape->numOfPoints) || inputShape->points == NULL) {
        // return null
        return NULL;
    }

    // otherwise return the point at the index
    return inputShape->points[index];
}

// ~~~~~~~~~~~~~~~~~ Getters for Individual Functions ~~~~~~~~~~~~~~~~~~~ //
float getGlobalScale() {
    return inputShape -> scaling[3];
}

float getXScale() {
    return inputShape -> scaling[0];
}

float getYScale() {
    return inputShape->scaling[1];
}

float getZScale() {
    return inputShape->scaling[2];
}

float getXRotation() {
    return inputShape->rotation[0];
}

float getYRotation() {
    return inputShape->rotation[1];
}

float getZRotation() {
    return inputShape->rotation[2];
}

float getXTranslation() {
    return inputShape->translation[0];
}

float getYTranslation() {
    return inputShape->translation[1];
}

float getZTranslation() {
    return inputShape->translation[2];
}

float getXReflection() {
    return inputShape->reflection[0];
}

float getYReflection() {
    return inputShape->reflection[1];
}

float getZReflection() {
    return inputShape->reflection[2];
}

float getXShear() {
    return inputShape->shearing[0];
}

float getYShear() {
    return inputShape->shearing[1];
}

float getZShear() {
    return inputShape->shearing[2];
}

float getOrthographic() {
    return inputShape->orthographic;
}

// ~~~~~~~~~~~~~~~~~ Setters ~~~~~~~~~~~~~~~~~~~ //
void setPoint(int index, struct point* newPoint) {
    // if the new point is null, don't set
    if (newPoint == NULL) {
        return;
    }

    // Otherwise if index is greater then 0 and is less then the number of points we have
    if ((index >= 0) && (index < inputShape->numOfPoints)) {
        // set the point at the index to the new point.
        inputShape->points[index] = newPoint;
    }
}

// ~~~~~~~~~~~~~~~~~ Setters for Individual Functions ~~~~~~~~~~~~~~~~~~~ //
void setGlobalScale(float newGlobalScale) {
    inputShape -> scaling[3] = newGlobalScale;
}

void setXScale(float newXScale) {
    inputShape -> scaling[0] = newXScale;
}

void setYScale(float newYScale) {
    inputShape->scaling[1] = newYScale;
}

void setZScale(float newZScale) {
    inputShape->scaling[2] = newZScale; 
}

void setXRotation(float newTheta) {
    inputShape->rotation[0] = newTheta;
}

void setYRotation(float angle) {
    inputShape->rotation[1] = angle;
}

void setZRotation(float newTheta) {
    inputShape->rotation[2] = newTheta;
}

void setXTranslation(float newXTranslation) {
    inputShape->translation[0] = newXTranslation;
}

void setYTranslation(float newYTranslation) {
    inputShape->translation[1] = newYTranslation;
}

void setZTranslation(float newZTranslation) {
    inputShape->translation[2] = newZTranslation;
}

void setXReflection(float newXReflection) {
    inputShape->reflection[0] = newXReflection;
}

void setYReflection(float newYReflection) {
    inputShape->reflection[1] = newYReflection;
}

void setZReflection(float newZReflection) {
    inputShape->reflection[2] = newZReflection;
}

void setXShear(float newXShear) {
    inputShape->shearing[0] = newXShear;
}

void setYShear(float newYShear) {
    inputShape->shearing[1] = newYShear;
}

void setZShear(float newZShear) {
    inputShape->shearing[2] = newZShear;
}

void setOrthographic(float newOrthographic) {
    inputShape->orthographic = newOrthographic;
}

void multiplyMatrix(struct point* currPoint, float matrix[4][4]) {
    // Error checking for NULL paramaters
    if (currPoint == NULL) {
        return;
    }

    struct point temp;

    // updating the points values
    for (int i = 0; i < 4; i++) {
        temp.element[i] = 0;
        for (int j = 0; j < 4; j++) {
            temp.element[i] += currPoint->element[j] * matrix[j][i];
        }
    }

    // storing new values into actual point
    for (int i = 0; i < 4; i++) {
        currPoint->element[i] = temp.element[i];
    }
}

//Reset transformation matrix to the identity matrix
void resetMatrix() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j) {
                transformationMatrix[i][j] = 1;
            }
            else {
                transformationMatrix[i][j] = 0;
            }
        }
    }
}
// Instantiates shape struct for testing
void createTestPoints() {
    createNTestPoints(5);
}

// Creates new inputShape with variable amt of testPoints
void createNTestPoints(int numOfPoints) {
    int i;

    inputShape = malloc(sizeof(struct shape));
    inputShape->numOfPoints = numOfPoints;
    inputShape->points = malloc(sizeof(struct point*) * numOfPoints);

    for (i = 0; i < numOfPoints; i++) {
        struct point* temp = malloc(sizeof(struct point));
        for (int j = 0; j < 3; j++) {
            temp->element[j] = j + i;
        }
        temp->element[3] = 1;
        inputShape->points[i] = temp;
    }
}

// Frees instantiated shape struct
void freeTestPoints() {
    int i;
    for (i = 0; i < inputShape->numOfPoints; i++) {
        free(inputShape->points[i]);
    }
    free(inputShape->points);
    free(inputShape);
}

void runAllTests() {
  
    /*Read Input Tests*/

    /* Global Scaling Tests */
    createTestPoints();
    runGlobalScalingTests();  
    freeTestPoints();
  
    /* Scaling in X Tests */
    createTestPoints();
    runScalingInXTests();
    freeTestPoints();

    /* Scaling in Y Tests */
    createTestPoints();
    runScalingInYTests();
    freeTestPoints();

    /* Scaling in Z Tests */
    createTestPoints();
    RunScalingInZTests();
    freeTestPoints();
  
    /* Rotation in X Tests */
    createTestPoints();
    setXRotation(0);
    runRotationInXTests(); 
    freeTestPoints();
  
    /* Rotation in Y Tests */
    createTestPoints();
    setYRotation(0);
    runRotationInYTests(); 
    freeTestPoints();
  
    /* Rotation in Z Tests */
    createTestPoints();
    runRotationInZTests ();
    freeTestPoints();
  
  
    /* X Plane Reflection Tests */
    createTestPoints();
    runReflectionInXPlaneTests();
    freeTestPoints();
  
    /* Y Plane Reflection Tests */
    createTestPoints();
    runYPlaneReflectionTests();
    freeTestPoints();

    /* Z Plane Reflection Tests */
    createTestPoints();
    ZPlaneReflectionTests();
    freeTestPoints();

    /* XYZ Translation Tests */
    createTestPoints();
    // runXYZTranslationTest();
    freeTestPoints();
  
    /* X Shear Tests */
    createTestPoints();
    runXShearTests();
    freeTestPoints();
  
    /* Y Shear Tests */
    createTestPoints();
    runYShearTests();
    freeTestPoints();

    /* Z Shear Tests */
    createTestPoints();
    runZShearTests();
    freeTestPoints();
    
    /* XYZ Orthographic Projection Tests */
    createTestPoints();
    XYZOrthographicProjectionRunTests();
    freeTestPoints();

    /* Output Results Tests */
    createTestPoints();
    runOutputResultsTests();
    freeTestPoints();

   

}
