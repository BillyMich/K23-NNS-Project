#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "common_types.h"
#include "Dimension.h"
#include "Neighbors.h"

typedef struct Node Node;

struct Node {
    Dimension* dimension;
    NodeNeighborsLinkedList* destinations;
    Node* nextNode;
};

// create a new node
Node* createNode(Dimension* dimension);

void freeNode(Node* node);
