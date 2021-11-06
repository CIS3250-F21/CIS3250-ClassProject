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
    } else {
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
    }
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
    // Error checking for NULL paramaters
    if (currVector == NULL || matrix == NULL) {
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (matrix[i] == NULL) return;
    }

    struct vector temp;

    // updating the vectors values
    for (int i = 0; i < 4; i++) {
        temp.vector[i] = 0;
        for (int j = 0; j < 4; j++) {
            temp.vector[i] += currVector->vector[j] * matrix[j][i];
        }
    }

    // storing new values into actual point
    for (int i = 0; i < 4; i++) {
        currVector->vector[i] = temp.vector[i];
    }
}

void runAllTests() {
    int i;
    inputShape.vectors = malloc(sizeof(struct vector*) * 5);

    for (i = 0; i < 5; i++) {
        struct vector* temp = malloc(sizeof(struct vector));
        for (int j = 0; j < 3; j++) {
            temp->vector[j] = j + i;
        }
        temp->vector[3] = 1;
        inputShape.vectors[i] = temp;
    }

    transformationMatrix = malloc(sizeof(float*) * 4);
    for (i = 0; i < 4; i++) {
        transformationMatrix[i] = malloc(sizeof(float) * 4);
    }

    runTests();  // Group 7 tests
}
