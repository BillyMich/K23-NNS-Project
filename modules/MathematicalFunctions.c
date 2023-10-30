#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include"Dimension.h"

double euclidean_distance(Dimension** nodeDimension1 , Dimension** nodeDimension2){

    Dimension* tempDimension1 = *nodeDimension1;
    Dimension* tempDimension2 = *nodeDimension2;

    double sum = 0.0;

    while (tempDimension1 != NULL)
    {
        // printf(" \n %f and this %f \n ", tempDimension1->value,tempDimension2->value );

        double dif =  tempDimension1->value - tempDimension2->value;
        // printf(" \n %f = diff ", dif );
        sum += dif * dif ;

        // printf(" \n %f = sum ", sum );
        tempDimension1 = tempDimension1->next;
        tempDimension2= tempDimension2->next;
    }
    double cost = sqrt(sum);
    // printf("\nthis is the distance between the nodes: %f\n", cost);
    return cost;
    
}