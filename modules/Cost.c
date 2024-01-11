#include "../include/Cost.h"

Cost* initCost(Node* name1, Node* name2, double dis_cost) {
    Cost* cost = (Cost*)malloc(sizeof(Cost));
    if (cost == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    cost->node1 = name1;
    cost->node2 = name2;
    cost->cost = dis_cost;
    cost->next = NULL;
   
    return cost;
}

void addCost(Cost** headCost, Node* node1, Node* node2, double cost) {
    Cost* newCost = initCost(node1, node2, cost);

    if (*headCost == NULL) {
        *headCost = newCost;
    }
    else { 
        Cost* temp = *headCost;
        while (temp->next!=NULL) {
            temp = temp->next;
        }
        temp->next = newCost;
    }
}

void freeCost(Cost* cost) {
    if (cost == NULL)
        return;

    while (cost != NULL ) {
        Cost* next = cost->next;
        free(cost);
        cost = next;
    }
}
