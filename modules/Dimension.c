#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "../include/Dimension.h"

Dimension* initDimension() {
    Dimension* newDimension = (Dimension*)malloc(sizeof(Dimension));
    if (newDimension == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    newDimension->next = NULL;

    return newDimension;
}


void addDimension(Dimension** head, int dimValue, double val) {
    //1. make the dimension
    Dimension* newDimension = initDimension();
    //2. initialize dimension
    newDimension->dimensionValue = dimValue;
    newDimension->value = val;
    //3. put dimension at the correct place
    if (*head == NULL) { // the first node to be made
        // printf("first time\n");
        *head = newDimension;
    }
    else { // 
        Dimension* temp = *head;
        // printf("second time\n");
        while (temp->next!=NULL) {
            temp = temp->next;
        }
        temp->next = newDimension;
    }
}

void printDimensions(Dimension *head) {
    while (head != NULL) {
        printf("%f \n", head->value);
        head = head->next;
    }
}

void freeDimensions(Dimension* dimensions) {
    while (dimensions != NULL) {
        printf("hello\n");
        Dimension* next = dimensions->next;
        free(dimensions);
        dimensions = next;
    }
}
