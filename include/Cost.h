#ifndef COST_H
#define COST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Cost Cost;

typedef struct Cost{
    int node1;
    int node2;
    double cost;
    Cost* next;
}Cost;

Cost* initCost(int name1, int name2, double dis_cost);

void addCost(Cost** headCost, int node1, int node2, double cost);

void freeCost(Cost* cost);

#endif