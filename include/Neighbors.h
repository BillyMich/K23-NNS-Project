#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "common_types.h"
#include "Node.h"

typedef struct NodeNeighborsLinkedList NodeNeighborsLinkedList;

struct NodeNeighborsLinkedList {
    Node* dest;
    double cost;
    double time_cost;
    NodeNeighborsLinkedList* next;
};

// add a destination to a node
NodeNeighborsLinkedList* addDestination(Node* node, Node* dest, double cost, double time_cost);

void freeDestination(NodeNeighborsLinkedList* destination);
