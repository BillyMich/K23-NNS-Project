#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include "common_types.h"
#include "Node.h"

typedef struct Graph Graph;

typedef struct Graph{
    Node* nodes;
    int numNodes;
}Graph;

Graph* initGraph();

Graph* createGraphFromBinaryFile(String filename, int dimensions, int K);

void freeGraph(Graph* graph);

void makeFile(String filename);

int isNumberUsed(int usedNumbers[], int count, int number, int numNode);

#endif // GRAPH_H
