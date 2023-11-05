#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include "Dimension.h"
#include "common_types.h"
#include <string.h>

/// @brief Basic use of euclidian distance theorym the distance as cost
/// @param nodeDimension1 
/// @param nodeDimension2 
/// @return 
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

/// @brief Basic use of manhattan distance theorym to return the distance as cost
/// @param nodeDimension1 
/// @param nodeDimension2 
/// @return 
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

/// @brief This function decides with mathematical therym (formula ) we are going to use
///  and returns it cost
/// @param nodeDimension1 
/// @param nodeDimension2 
/// @param distance_function 
/// @return 
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
