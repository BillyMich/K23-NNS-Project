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
    NodeNeighborsLinkedList* next;
}NodeNeighborsLinkedList;

NodeNeighborsLinkedList* initNeighbor(Node* dest, double cost);

void addNeighbor(NodeNeighborsLinkedList** head, Node* dest, double cost);

int deleteLastNeighborNode(NodeNeighborsLinkedList** head);

void deleteReverseNeighbor(Node** graph, int name, int nodeNameReverse);

void freeNeighbors(NodeNeighborsLinkedList* destination);

#endif 

