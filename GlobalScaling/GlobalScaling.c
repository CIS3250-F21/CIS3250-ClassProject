#include "GlobalScaling.h"

void globalScaling(){
    //reset the matrix 
    resetMatrix();
    float globalScaleValue = 1.0;
    //get the global scale value
    globalScaleValue = getGlobalScale();
    struct point* p;
    int i = 0;
    //set the global scale value to the most bottom right element in the transformation matrix
    transformationMatrix[3][3] = globalScaleValue;

    //check if the global scale value is 0
    if(globalScaleValue == 0){
        fprintf(stderr, "Global scale value is invalid\n");
        exit(EXIT_FAILURE);
    } 
    else if(globalScaleValue < 0){
        fprintf(stderr, "Global scale value is invalid\n");
        exit(EXIT_FAILURE);        
    }
    else {
         float fourthValue;
         //loop through all points until null
        while((p = getPoint(i)) != NULL){
            //multiply each point with the transformation matrix
            multiplyMatrix( p, transformationMatrix );

            fourthValue = p->element[3];
            //check if the fourth value in the vector is 1
            if( fourthValue  != 1) {
                //if not 1 then divide each element in the vector by the 4 th value in the vector
                for(int j = 3; j >= 0; j--) {
                    p->element[j] /= fourthValue;
                }
            }
            //set the points
            setPoint( i, p );
            i++;
        }
    }


    //reset the matrix after finishing with it
    resetMatrix();
}
