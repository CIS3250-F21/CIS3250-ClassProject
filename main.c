#include "main.h"
//~~~~~~ Class Includes ~~~~~~//
#include "groupIncludes.h"
#include "groupTestIncludes.h"

int main(int argc, char** argv) {
    fileName = malloc(sizeof(char) * 10);
    strcpy(fileName, "shape.txt");

    // Run tests if need be
    if (argc == 2 && strcmp(argv[1], "-t") == 0) {
        runAllTests();
    } else if (argc == 2) {
    //else if (argc == 3) {
        //fileName = malloc(sizeof(char) * BUFSIZ);
        //strncpy(fileName, argv[1], BUFSIZ);
        
        outputFileName = malloc(sizeof(char) * BUFSIZ);
        strncpy(outputFileName, argv[1], BUFSIZ);

        //~~~~~ Group 1 ~~~~~//
        inputShape = readInput(fileName);

        // Instantiate Temporary Points //
        // FIXME: REMOVE AFTER GROUP 1 IMPLEMENTATION //
        inputShape->points = malloc(sizeof(struct point*) * 1);
        inputShape->numOfPoints = 1;

        struct point* temp = malloc(sizeof(struct point));
        
        temp->element[0] = 1.0f;
        temp->element[1] = 1.0f;
        temp->element[2] = 1.0f;
        temp->element[3] = 1.0f;

        setPoint(0, temp);

        //GROUP 1 WILL IMPLEMENT THIS
        setGlobalScale(1);
        setXScale(1);
        setYScale(1);
        setZScale(1);
        setXRotation(0);
        setYRotation(0);
        setZRotation(0);
        setXTranslation(0);
        setYTranslation(0);
        setZTranslation(0);
        setXShear(0);
        setYShear(0);
        setZShear(0);



        //~~~~~ Group 2 ~~~~~//
        globalScaling();

        //~~~~~ Group 3 ~~~~~//
        xScaling();

        //~~~~~ Group 4 ~~~~~//
        yScaling();

        //~~~~~ Group 5 ~~~~~//
        zScaling();

        //~~~~~ Group 6 ~~~~~//
        xRotation();

        //~~~~~ Group 7 ~~~~~//
        yRotation();

        //~~~~~ Group 8 ~~~~~//
        zRotation();

        //~~~~~ Group 9 ~~~~~//
        xyzTranslation();

        //~~~~~ Group 10 ~~~~~//
        xPlaneReflection();

        //~~~~~ Group 11 ~~~~~//
        yPlaneReflection();

        //~~~~~ Group 12 ~~~~~//
        ZPlaneReflection();

        //~~~~~ Group 13 ~~~~~//
        xShear();

        //~~~~~ Group 14 ~~~~~//
        yShear();

        //~~~~~ Group 15 ~~~~~//
        zShear();

        //~~~~~ Group 16 ~~~~~//
        xyzOrthographicProjection();

        //~~~~~ Group 17 ~~~~~//
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
        // fprintf(stderr, "Format %s <input file> <output file>", argv[0]);
        fprintf(stderr, "Format: %s <output file>\n", argv[0]);
        free(fileName);
        return 1;
    }
    free(outputFileName);
    free(fileName);
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

// ~~~~~~~~~~~~~~~~~ GROUP Getters Go HERE ~~~~~~~~~~~~~~~~~~~ //
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
    return 0;
}

float getYRotation() {
    return inputShape->rotation[1];
}

float getZRotation() {
    return 0;
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

float getXShear() {
    return inputShape->shearing[0];
}

float getYShear() {
    return inputShape->shearing[1];
}

float getZShear() {
    return inputShape->shearing[2];
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

// ~~~~~~~~~~~~~~~~~ GROUP Setters Go HERE ~~~~~~~~~~~~~~~~~~~ //
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
}

void setYRotation(float angle) {
    inputShape->rotation[1] = angle;
}

void setZRotation(float newTheta) {
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

void setXShear(float newXShear) {
    inputShape->shearing[0] = newXShear;
}

void setYShear(float newYShear) {
    inputShape->shearing[1] = newYShear;
}

void setZShear(float newZShear) {
    inputShape->shearing[2] = newZShear;
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
void resetMatrix(){
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if (i == j){
                transformationMatrix[i][j] = 1;
            }
            else{
                transformationMatrix[i][j] = 0;
            }
        }
    }
}

// Instantiates shape struct for testing
void createTestPoints() {
    int i;

    inputShape = malloc(sizeof(struct shape));
    inputShape->numOfPoints = 5;
    inputShape->points = malloc(sizeof(struct point*) * 5);

    for (i = 0; i < 5; i++) {
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
    for (i = 0; i < 5; i++) {
        free(inputShape->points[i]);
    }
    free(inputShape->points);
    free(inputShape);
}

void runAllTests() {
  
    
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
    runScalingInXTests();
    freeTestPoints();

    /* Scaling in Z Tests */
    createTestPoints();
    //runZScalingTests(); 
    freeTestPoints();
  
  
  
    /* Rotation in Y Tests */
    createTestPoints();
    setYRotation(0);
    runGroup7Tests();  
    freeTestPoints();
  
  
  
    /* X Plane Reflection Tests */
    createTestPoints();
    runXPlaneReflectionTests();
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
    //runYShearTests(); //still need to get a testrunner
    freeTestPoints();

    /* Output Results Tests */
    createTestPoints();
    runOutputResultsTests();
    freeTestPoints();


}
