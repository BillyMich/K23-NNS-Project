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
    int flag;
    NodeNeighborsLinkedList* next;
    NodeNeighborsLinkedList* privious;
}NodeNeighborsLinkedList;

NodeNeighborsLinkedList* initNeighbor(Node* dest, double cost);

void addNeighbor(NodeNeighborsLinkedList** head, Node* dest, double cost);

Node* deleteLastNeighborNode(NodeNeighborsLinkedList** head);

void deleteReverseNeighbor(Node* temp , int nodeNameReverse);

void freeNeighbors(NodeNeighborsLinkedList* destination);

#endif 
