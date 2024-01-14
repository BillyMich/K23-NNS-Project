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

double findAccurationResult(Graph* graph , Graph* graphRightResults,int neighbors);

double findAccurationResultSuperAccurate(Graph* graph , Graph* graphRightResults);


void freeGraph(Graph* graph);

void writeGraphToFile(Graph* graph, const char* filename);


/*-----for creating binary files-----*/
double randDouble(double min, double max, long long int i);

void createBinary(String filename);

#endif // GRAPH_H
