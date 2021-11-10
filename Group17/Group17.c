#include "Group17.h"

int outputVector(char* filename) {
    FILE* fp;
    struct point* point;

    // check if there are vectors to print
    if (inputShape->numOfPoints <= 0) {
        #ifdef DEBUG
            printf("ERROR no vectors to print\n");
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

    // output vectors to file
    for (int i = 0; i < inputShape->numOfPoints; i++) {
        point = getVector(i);

        if (point == NULL) {
            #ifdef DEBUG
                printf("ERROR null vector\n");
            #endif
            fclose(fp);
            return 0;
        }

        
        fprintf (
            fp, "%f %f %f %f\n", 
            point->element[0], point->element[1], 
            point->element[2], point->element[3]
        );
    }

    fclose(fp);
    return 1;
}
