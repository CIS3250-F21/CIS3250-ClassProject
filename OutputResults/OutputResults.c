#include "OutputResults.h"

int outputPoints(char* filename) {
    FILE* fp;
    struct point* point;

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

    // output header
    fprintf(fp, "X,Y,Z\n");

    // output points to file
    int i = 0;
    point = getPoint(0);
    while (point != NULL) {
        fprintf (
            fp, "%f,%f,%f\n", 
            point->element[0], point->element[1], point->element[2]
        );
        point = getPoint(++i);
    }

    #ifdef DEBUG
        printf("Output %d points to %s\n", i, filename);
    #endif

    fclose(fp);
    return 1;
}
