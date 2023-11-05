#include "../include/Neighbors.h"


NodeNeighborsLinkedList* initNeighbor(Node* nodeNeighbor, double cost) {
    NodeNeighborsLinkedList* newNeighbor = (NodeNeighborsLinkedList*)malloc(sizeof(NodeNeighborsLinkedList));
    if (newNeighbor == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    newNeighbor->node = nodeNeighbor;
    newNeighbor->cost = cost;
    newNeighbor->next = NULL;

    return newNeighbor;
}


void addNeighbor(NodeNeighborsLinkedList** head, Node* nodeNeighbor, double cost) {
    NodeNeighborsLinkedList* newNeighbor = initNeighbor(nodeNeighbor, cost);
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


void deleteLastNeighborNode(NodeNeighborsLinkedList* head) {
    NodeNeighborsLinkedList* current = head;
    
    // If there is no neighbor or only one neighbor, there's nothing to delete
    if (current == NULL || current->next == NULL) return;

    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next->next);
    current->next->next = NULL;
}


void freeNeighbors(NodeNeighborsLinkedList* neighbors) {
    
    while (neighbors != NULL) {
        NodeNeighborsLinkedList* next = neighbors->next;
        free(neighbors);
        neighbors = next;
    }
}
