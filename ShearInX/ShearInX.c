#include "ShearInX.h"
#define SHEAR_FLOAT_MAX 34028234600000000000000000000000000000.0

void xShear() {
    if (inputShape == NULL) {
        printErr("Fatal Error: Shape was a null pointer\n");
        return;
    } else if (inputShape->points == NULL) {
        printErr("Fatal Error: Shape was defined, but points was Null\n");
        return;
    }

    for (int i = 0; i < inputShape->numOfPoints; i++) {  // idk why this works on extremely small values but it also works for what you'd expect to need FLOAT_MIN instead
        if ((SHEAR_FLOAT_MAX / getYShear() < getPoint(i)->element[1]) || (SHEAR_FLOAT_MAX / getZShear() < getPoint(i)->element[2])) {
            printErr("Magnitude Error: xShear() would have caused an value of infinity if excecuted. Aborted.\n");
            return;
        }
    }

    struct point* temp;
    float matrix[4][4];
    /*matrix = malloc(sizeof(float*) * 4);
    for (int i = 0; i < 4; i++) {
        matrix[i] = malloc(sizeof(float) * 4);
    }*/

    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            if (x == 0 && y == 1) {
                matrix[x][y] = getYShear();
            } else if (x == 0 && y == 2) {
                matrix[x][y] = getZShear();
            } else if (x == y) {
                matrix[x][y] = 1;
            } else {
                matrix[x][y] = 0;
            }
        }
    }

    for (int i = 0; i < inputShape->numOfPoints; i++) {
        temp = getPoint(i);
        if (temp == NULL) {
            return;
        }
        if (temp->element[3] != 1) {
            printErr("Warning: xShear() had to normalize it's own point!\n");
            temp->element[0] = temp->element[0] / temp->element[3];
            temp->element[1] = temp->element[1] / temp->element[3];
            temp->element[2] = temp->element[2] / temp->element[3];
            temp->element[3] = 1.0;
        }
        multiplyMatrix(temp, matrix);
        //printpoint(&temp);
        setPoint(i, temp);
    }

    /*for (int i = 0; i < 4; i++) {
        free(matrix[i]);
    }
    free(matrix);*/
}

void printErr(char* toPrint) {  // printf with tstMode modifications
    if (tstFlag) {
        errorFlag = 1;
    } else {
        printf("%s", toPrint);
    }
}
