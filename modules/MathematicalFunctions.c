#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include "Dimension.h"
#include "common_types.h"
#include <string.h>


double euclidean_distance(Dimension* nodeDimension1 , Dimension* nodeDimension2){

    Dimension* tempDimension1 = nodeDimension1;
    Dimension* tempDimension2 = nodeDimension2;

    double sum = 0.0;

    while (tempDimension1 != NULL)
    {
        double dif =  tempDimension1->value - tempDimension2->value;
        sum += dif * dif ;

        tempDimension1 = tempDimension1->next;
        tempDimension2 = tempDimension2->next;
    }
    double cost = sqrt(sum);
    
    return cost; 
}


double manhattan_distance(Dimension* nodeDimension1 , Dimension* nodeDimension2){
    
    Dimension* tempDimension1 = nodeDimension1;
    Dimension* tempDimension2 = nodeDimension2;
    
    double distance = 0;

    while (tempDimension1 != NULL && tempDimension2 != NULL) {
        
        distance += fabs(tempDimension1->value - tempDimension2->value);

        tempDimension1 = tempDimension1->next;
        tempDimension2 = tempDimension2->next;
    }
    
    return distance;
}


double distance(Dimension* nodeDimension1 , Dimension* nodeDimension2, String distance_function){
    double cost = 0.0;
    if(strcmp(distance_function, "euclidean") == 0){
        cost = euclidean_distance(nodeDimension1, nodeDimension2);
    }
    else if(strcmp(distance_function, "manhattan") == 0){
        cost = manhattan_distance(nodeDimension1, nodeDimension2);
    }
    return cost;
}
