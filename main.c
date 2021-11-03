#include "main.h"
//~~~~~~ Class Includes ~~~~~~//
#include "groupIncludes.h"
#include "groupTestIncludes.h"

int main(int argc, char** argv) {
    fileName = malloc(sizeof(char) * 10);
    strcpy(fileName, "shape.txt");

    if (argc == 2 && strcmp(argv[1], "-t") == 0) {
        runAllTests();
    }

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

float getYRotation() {
    return inputShape.rotation[1];
}

void setYRotation(float angle) {
    inputShape.rotation[1] = angle;
}

struct vector* getVector(int index) {
    if ((index < 0) || (index >= inputShape.numOfVectors) || inputShape.vectors == NULL) {
        return NULL;
    }

    return inputShape.vectors[index];
}

// check //
void setVector(int index, struct vector* newVector) {
    if (newVector == NULL) {
        return;
    }

    if ((index >= 0) && (index < inputShape.numOfVectors)) {
        inputShape.vectors[index] = newVector;
    }
}

void multiplyMatrix(struct vector* currVector, float** matrix) {
    // TODO
}

void runAllTests() {
    runTests();  // Group 7 tests
}
