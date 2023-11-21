#ifndef COST_H
#define COST_H

typedef struct Cost Cost;

typedef struct Cost{
    int node1;
    int node2;
    double cost;
    Cost* next;
}Cost;

Cost* initCost();

void addCost(Cost* headCost, int node1, int node2, double cost);

void freeCost(Cost* cost);

#endif