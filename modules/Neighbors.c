#include "../include/Neighbors.h"



void addNeighbor(Node** head, Node* nodeNeighbor, double cost, double time_cost) {
    NodeNeighborsLinkedList* newNeighbor = (NodeNeighborsLinkedList*)malloc(sizeof(NodeNeighborsLinkedList));
    if (newNeighbor == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    newNeighbor->node = nodeNeighbor;
    newNeighbor->cost = cost;
    newNeighbor->time_cost = time_cost;
    newNeighbor->next = NULL; //node->neighbors;

    (*head)->neighbors = newNeighbor;

    if ((*head)->neighbors == NULL) { // the first node to be made
        (*head)->neighbors = newNeighbor;
    }
    else { // 
        NodeNeighborsLinkedList* temp = (*head)->neighbors;
        while (temp->next!=NULL) {
            temp = temp->next;
        }
        temp->next = newNeighbor;
    }

}


void freeNeighbor(NodeNeighborsLinkedList* neighbor) {
    if (neighbor == NULL)
        return;
    freeNode(neighbor->node);
    free(neighbor);
}