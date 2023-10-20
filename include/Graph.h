#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "common_types.h"

typedef struct Node;
typedef struct NodeNeighborsLinkedList;
typedef struct Graph;

typedef struct Node {
    String name;
    NodeNeighborsLinkedList* destinations;
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

//We need to think a way to chouse 2D or 3D
//depending on the given graph 

typedef struct Destinations2D {
    double x;
    double y;
} Destinations2D;

typedef struct Destinations3D {
    double x;
    double y;
    double z;
} Destinations3D;

// create a new node
Node createNode(const String name);

void freeNode(Node node);

// add a destination to a node
NodeNeighborsLinkedList addDestination(Node node, Node dest, double cost, double time_cost);

void freeDestination(NodeNeighborsLinkedList destination);

Graph createGraph();

void freeGraph(Graph graph);