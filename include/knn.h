#ifndef KNN_H
#define KNN_H

#include "Graph.h"

// Function to check if a number has been used before
int isNumberUsed(int usedNumbers[], int count, int number, int numNode);

//TODO: make neighbors list
void KRandomNodes(Graph** graph, int K);


#endif
