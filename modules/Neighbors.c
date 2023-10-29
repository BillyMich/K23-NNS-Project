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
    
    // If the list is empty, set the new neighbor as the head
    if (*head == NULL) {
        printf("this is the first neighob of the node!\n");
        *head = newNeighbor;
    } else {
        NodeNeighborsLinkedList* temp = *head;
        while (temp->next != NULL) {
            printf("Just added a neighob in the node\n");
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