#include "../include/Node.h"

//TODO:dimension need to be created before sending it here!
Node* initNode() {
    Node* node = (Node*)malloc(sizeof(Node));
    if(node == NULL)
        return NULL;

    //Here we will add the dimensions
    node->dimension = NULL;//dimension;
    node->destinations = NULL;
    node->next = NULL;

    return node;
}



void addNode(Node** headNode, Dimension* headDimension) {
    //1. make the node
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    //2. initialize node
    newNode->dimension = headDimension;
    newNode->next = NULL;
    newNode->destinations = NULL;
    //3. put node at the correct place
    if (*headNode == NULL) { // the first node to be made
        // printf("head node init\n");
        *headNode = newNode;
    }
    else { // 
        Node* temp = *headNode;
        while (temp->next!=NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
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
