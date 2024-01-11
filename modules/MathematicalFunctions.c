#include "../include/MathematicalFunctions.h"

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
    
    double distance = 0.0;

    while (tempDimension1 != NULL && tempDimension2 != NULL) {
        
        distance += fabs(tempDimension1->value - tempDimension2->value);

        tempDimension1 = tempDimension1->next;
        tempDimension2 = tempDimension2->next;
    }
    
    return distance;
}


/// @brief 
/// @param head 
/// @return 

//isws boleyei node1, node2

double calculate_norm(Dimension* head) { 
    double norm = 0.0;

    while (head != NULL) {
        // printf("head->value-%f\n", head->value);
        //norm = x1*x1 + x2*x2 + ......
        norm += head->value*head->value;
        head = head->next;
    }
    // printf("norm-%f\n",norm);
    return norm;
}


/// @brief 
/// @param node1 
/// @param node2 
/// @return 

double euclidean_distance_improved(Node* node1, Node* node2){
    //x^2+y^2-2xy
    double norm1 = node1->norm;
    double norm2 = node2->norm;

    Dimension* tempDimension1 = node1->dimension;
    Dimension* tempDimension2 = node2->dimension;

    double mult = 0.0;

    while (tempDimension1 != NULL) {
        mult += tempDimension1->value*tempDimension2->value;
        tempDimension1 = tempDimension1->next;
        tempDimension2 = tempDimension2->next;
    }

    //printf("improved cost-%f\n",norm1+norm2-2.0*mult);
    return norm1+norm2-2.0*mult;
}

/// @brief This function decides with mathematical therym (formula ) we are going to use
///  and returns it cost
/// @param nodeDimension1 
/// @param nodeDimension2 
/// @param distance_function 
/// @return 
double distance(Node* node1 , Node* node2, String distance_function){
    double cost = 0.0;
    if(strcmp(distance_function, "euclidean") == 0) {
        cost = euclidean_distance(node1->dimension, node2->dimension);
    }
    else if(strcmp(distance_function, "manhattan") == 0) {
        cost = manhattan_distance(node1->dimension, node2->dimension);
    }
    else if(strcmp(distance_function, "improved") == 0) {
        cost = euclidean_distance_improved(node1, node2);
    }
    return cost;
}
