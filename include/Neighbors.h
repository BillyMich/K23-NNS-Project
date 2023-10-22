#ifndef NEIGHBORS_H
#define NEIGHBORS_H

#include <stdio.h>
#include <stdlib.h>
#include "common_types.h"
#include "Node.h"

typedef struct NodeNeighborsLinkedList NodeNeighborsLinkedList;
typedef struct Node Node;

typedef struct NodeNeighborsLinkedList {
    Node* dest;
    double cost;
    double time_cost;
    NodeNeighborsLinkedList* next;
}NodeNeighborsLinkedList;

// add a destination to a node
NodeNeighborsLinkedList* addDestination(Node* node, Node* dest, double cost, double time_cost);

void freeDestination(NodeNeighborsLinkedList* destination);

#endif // NEIGHBORS_H

