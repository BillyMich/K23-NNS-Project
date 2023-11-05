#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h>
#include "common_types.h"
#include "Dimension.h"
#include "Neighbors.h"

typedef struct Node Node;
typedef struct NodeNeighborsLinkedList NodeNeighborsLinkedList;

typedef struct Node {
    int nodeNameInt;
    Dimension* dimension;
    NodeNeighborsLinkedList* neighbors;
    NodeNeighborsLinkedList* reversedNeighbors;
    Node* next;
}Node;

Node* initNode();

void addNode(Node** headNode, Dimension* headDimension);

void freeNode(Node* node);

#endif 
