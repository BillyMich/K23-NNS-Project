#ifndef COST_H
#define COST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct Cost Cost;

typedef struct Cost{
    Node* node1;
    Node* node2;
    double cost;
    Cost* next;
}Cost;

Cost* initCost(Node* name1, Node* name2, double dis_cost);

void addCost(Cost** headCost,  Node* node1,  Node* node2, double cost);

void freeCost(Cost* cost);

#endif