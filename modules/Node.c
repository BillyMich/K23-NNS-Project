#include "../include/Node.h"

//TODO:dimension need to be created before sending it here!
Node* initNode() {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    //Here we will add the dimensions
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
        // printf("head node init\n");
        newNode->nodeNameInt = 0;
        *headNode = newNode;
    }
    else { // 
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

    freeDimensions(node->dimension);
    freeNeighbors(node->neighbors);
    freeNeighbors(node->reversedNeighbors);
    free(node);
}
