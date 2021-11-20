#include "ShearInX.h"
#define SHEAR_FLOAT_MAX 34028234600000000000000000000000000000.0

void xShear() 
{
    if (inputShape == NULL) 
		{
        printErr("Fatal Error: Shape was a null pointer\n");
        return;
    } 
		else if (inputShape->points == NULL) 
		{
        printErr("Fatal Error: Shape was defined, but points was Null\n");
        return;
    }

    int i = 0;
    while (getPoint(i) != NULL) 
		{  
        if ((SHEAR_FLOAT_MAX / getYShear() < getPoint(i)->element[1]) || (SHEAR_FLOAT_MAX / getZShear() < getPoint(i)->element[2])) 
				{
            printErr("Magnitude Error: xShear() would have caused an value of infinity if excecuted. Aborted.\n");
            return;
        }

        i++;
    }

    struct point* temp;

		// Reset transformationMatrix and get required shear values from global shape structure
    resetMatrix();
		transformationMatrix[0][1] = getYShear();
		transformationMatrix[0][2] = getZShear();

    i = 0;
    while (getPoint(i) != NULL) 
		{
        temp = getPoint(i);

        if (temp->element[3] != 1) 
				{
            printErr("Warning: xShear() had to normalize it's own point!\n");
            temp->element[0] /= temp->element[3];
            temp->element[1] /= temp->element[3];
            temp->element[2] /= temp->element[3];
            temp->element[3] = 1.0;
        }

        multiplyMatrix(temp, transformationMatrix);
        // safeguard, shouldn't really be doing anything
        setPoint(i, temp);  
        i++;
    }

		// clean-up transformationMatrix
		resetMatrix();
}

void printErr(char* toPrint) 
{  // printf with test modifications
    if (errorFlag == -1) 
		{      // if an error is expected due to testing
        errorFlag = 1;
    } else {
        printf("%s", toPrint);
    }
}
