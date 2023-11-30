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

Graph* createGraphFromBinaryFile(String filename, int dimensions);

double findAccurationResult(Graph* graph , Graph* graphRightResults);

double findAccurationResultSuperAccurate(Graph* graph , Graph* graphRightResults);


void freeGraph(Graph* graph);

void makeFile(String filename);

void writeGraphToFile(Graph* graph, const char* filename);

#endif // GRAPH_H
