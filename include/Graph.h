#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "common_types.h"

typedef struct Node;
typedef struct NodeNeighborsLinkedList;
typedef struct Graph;

typedef struct Dimension{
    int level; 
    double value;
    Dimension nextDimension; //ERROR: unknown type name ‘Dimension’ - same below
} * Dimension;

typedef struct Node {
    Dimension dimension;
    NodeNeighborsLinkedList* destinations;
    Node nextNode;
} * Node;

typedef struct NodeNeighborsLinkedList {
    Node dest;
    double cost;
    double time_cost;
    NodeNeighborsLinkedList* next;
} * NodeNeighborsLinkedList;

typedef struct Graph{
    Node nodes;
    int numNodes;
} * Graph;



// create a new node
Node createNode(Dimension dimension);

void freeNode(Node node);

// add a destination to a node
NodeNeighborsLinkedList addDestination(Node node, Node dest, double cost, double time_cost);

void freeDestination(NodeNeighborsLinkedList destination);

Graph initGraph();

Graph createGraphFromBinaryFile(const String filename, int dimensions);

void freeGraph(Graph graph);