#ifndef NEIGHBORS_H
#define NEIGHBORS_H

#include <stdio.h>
#include <stdlib.h>
#include "common_types.h"
#include "Node.h"

typedef struct NodeNeighborsLinkedList NodeNeighborsLinkedList;
typedef struct Node Node;

typedef struct NodeNeighborsLinkedList {
    Node* node;
    double cost;
    double time_cost;
    NodeNeighborsLinkedList* next;
}NodeNeighborsLinkedList;

NodeNeighborsLinkedList* initNeighbor(Node* dest, double cost, double time_cost);

// add a destination to a node
void addNeighbor(NodeNeighborsLinkedList** head, Node* dest, double cost, double time_cost);

void freeNeighbors(NodeNeighborsLinkedList* destination);

#endif // NEIGHBORS_H

