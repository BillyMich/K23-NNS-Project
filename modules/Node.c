#include "../include/Node.h"



Node* initNode() {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    node->dimension = NULL;//dimension;
    node->neighbors = NULL;
    node->reversedNeighbors = NULL;
    node->next = NULL;

    return node;
}


void addNode(Node** headNode, Dimension* headDimension) {
    //1. make the node
    Node* newNode = initNode();
    //2. initialize node
    newNode->dimension = headDimension;
    //3. put node at the correct place
    if (*headNode == NULL) { // the first node to be made
        newNode->nodeNameInt = 0;
        *headNode = newNode;
    }
    else { 
        Node* temp = *headNode;
        while (temp->next!=NULL) {
            temp = temp->next;
        }
        newNode->nodeNameInt = temp->nodeNameInt + 1;
        temp->next = newNode;
    }
}


void freeNode(Node* node) {
    if (node == NULL)
        return;

    freeNeighbors(node->neighbors);
    freeNeighbors(node->reversedNeighbors);
    freeDimensions(node->dimension);
    
    free(node);
}
