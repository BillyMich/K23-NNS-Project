#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "../include/Dimension.h"



void addDimension(Dimension** head, int dimValue, double val) {
    Dimension* newDimension = (Dimension*)malloc(sizeof(Dimension));
    if (newDimension == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    newDimension->dimensionValue = dimValue;
    newDimension->value = val;
    newDimension->next = *head;
    *head = newDimension;
}

void printDimensions(Dimension *pointer) {
  while (pointer != NULL) {
    printf("%f ", pointer->value);
    pointer = pointer->next;
  }
}