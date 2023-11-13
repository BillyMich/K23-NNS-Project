#include "../include/Neighbors.h"

/// @brief Initialazation of a node
/// @param nodeNeighbor 
/// @param cost 
/// @return 
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

/// @brief This is an add neightbor that adds them in coreect order
/// @param head 
/// @param nodeNeighbor 
/// @param cost 
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

/// @brief Deleted last node 
/// @param head 
void deleteLastNeighborNode(NodeNeighborsLinkedList** head) {
    NodeNeighborsLinkedList* current = *head;
    NodeNeighborsLinkedList* previous;

    if (current == NULL) return;
    //one neighbor
    if (current->next ==NULL) {
        *head = NULL;
        //free(current);
        return;
    }
    //more than one neighbor
    while (current->next != NULL) {
        if (current->next->next == NULL) {
            previous = current;
        }
        current = current->next;        
    }
    //free(current->next);
    current->next=NULL;
}


void freeNeighbors(NodeNeighborsLinkedList* neighbors) {
    
    while (neighbors != NULL) {
        NodeNeighborsLinkedList* next = neighbors->next;
        free(neighbors);
        neighbors = next;
    }
}
