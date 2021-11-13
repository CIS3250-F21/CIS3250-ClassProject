#include "OutputResults.h"

int outputPoints(char* filename) {
    FILE* fp;
    struct point* point;

    // check if there are points to print
    if (inputShape->numOfPoints <= 0) {
        #ifdef DEBUG
            printf("ERROR no points to print\n");
        #endif
        return 0;
    }

    // check for valid filename
    if (filename == NULL) {
        #ifdef DEBUG
            printf("ERROR null filename\n");
        #endif
        return 0;
    }
    
    // open file in write mode
    if ((fp = fopen(filename, "w")) == NULL) {
        #ifdef DEBUG
            printf("ERROR opening file\n");
        #endif
        return 0;
    }

    // output points to file
    for (int i = 0; i < inputShape->numOfPoints; i++) {
        point = getPoint(i);

        if (point == NULL) {
            #ifdef DEBUG
                printf("ERROR null point\n");
            #endif
            fclose(fp);
            return 0;
        }

        
        fprintf (
            fp, "%f %f %f\n", 
            point->element[0], point->element[1], point->element[2]
        );
    }

    fclose(fp);
    return 1;
}
