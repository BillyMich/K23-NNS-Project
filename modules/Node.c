#include "../include/Node.h"

//TODO:dimension need to be created before sending it here!
Node* createNode(Dimension* dimension) {
    Node* node = (Node*)malloc(sizeof(Node));
    if(node == NULL)
        return NULL;

    //Here we will add the dimensions
    node->dimension = dimension;
    node->destinations = NULL;
    node->next = NULL;

    return node;
}



void addNode(Node** head,Dimension* dimension) {
    Node* newNode = createNode(dimension);
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    newNode->next = *head;
    *head = newNode;
}



void  freeNode(Node* node) {
    if (node == NULL)
        return;
    NodeNeighborsLinkedList* current = node->destinations;
    while (current != NULL) {
        NodeNeighborsLinkedList* next = current->next;
        free(current);
        current = next;
    }
    free(node);
}
