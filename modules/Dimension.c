#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "../include/Dimension.h"

/// @brief Initializes a dimension
Dimension* initDimension() {
    Dimension* newDimension = (Dimension*)malloc(sizeof(Dimension));
    if (newDimension == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    newDimension->next = NULL;

    return newDimension;
}

/// @brief Adds a dimension to the list
/// @param head 
/// @param dimValue 
/// @param val 
void addDimension(Dimension** head, int dimValue, double val) {
    Dimension* newDimension = initDimension();
    newDimension->dimensionValue = dimValue;
    newDimension->value = val;
    if (*head == NULL) {
        *head = newDimension;
    }
    else {
        Dimension* temp = *head;
        while (temp->next!=NULL) {
            temp = temp->next;
        }
        temp->next = newDimension;
    }
}

/// @brief Prints the dimensions
void printDimensions(Dimension *head) {
    while (head != NULL) {
        printf("%f \n", head->value);
        head = head->next;
    }
}

/// @brief Free the dimensions
void freeDimensions(Dimension* dimensions) {
    while (dimensions != NULL) {
        Dimension* next = dimensions->next;
        free(dimensions);
        dimensions = next;
    }
}
