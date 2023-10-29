#include "../include/Neighbors.h"

NodeNeighborsLinkedList* initNeighbor(Node* nodeNeighbor, double cost, double time_cost) {
    NodeNeighborsLinkedList* newNeighbor = (NodeNeighborsLinkedList*)malloc(sizeof(NodeNeighborsLinkedList));
    if (newNeighbor == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    newNeighbor->node = nodeNeighbor;
    newNeighbor->cost = cost;
    newNeighbor->time_cost = time_cost;
    newNeighbor->next = NULL; //node->neighbors;

    return newNeighbor;
}

void addNeighbor(NodeNeighborsLinkedList** head, Node* nodeNeighbor, double cost, double time_cost) {
    NodeNeighborsLinkedList* newNeighbor = initNeighbor(nodeNeighbor, cost, time_cost);

    NodeNeighborsLinkedList* temp = *head;
    while (temp != NULL) {
        printf("this is a new neighbor \n");
        temp = temp->next;
    }
    temp = newNeighbor;

}


void freeNeighbor(NodeNeighborsLinkedList* neighbor) {
    if (neighbor == NULL)
        return;
    freeNode(neighbor->node);
    free(neighbor);
}