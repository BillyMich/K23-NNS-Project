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
    if (*head == NULL || cost < (*head)->cost) {
        newNeighbor->next = *head;
        *head = newNeighbor;
    } else {
        NodeNeighborsLinkedList* current = *head;
        while (current->next != NULL && current->next->cost < cost) {
            current = current->next;
        }
        newNeighbor->next = current->next;
        current->next = newNeighbor;
    }
}



void freeNeighbors(NodeNeighborsLinkedList* neighbors) {
    while (neighbors != NULL) {
        NodeNeighborsLinkedList* next = neighbors->next;
        free(neighbors);
        neighbors = next;
    }
}
