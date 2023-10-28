#ifndef DIMENSION_H
#define DIMENSION_H

typedef struct Dimension Dimension;


typedef struct Dimension{
    int dimensionValue;
    double value;
    Dimension* next;
}Dimension;

void printDimensions(Dimension *head);
void addDimension(Dimension** head, int dimValue, double val);
void freeDimensions(Dimension* dimension);
void freeDimensionLinkedList(Dimension* head);

#endif 