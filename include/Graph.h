#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "common_types.h"
#include "Node.h"

typedef struct Graph Graph;

struct Graph{
    Node* nodes;
    int numNodes;
};

Graph* initGraph();

Graph* createGraphFromBinaryFile(String filename, int dimensions);

void freeGraph(Graph* graph);