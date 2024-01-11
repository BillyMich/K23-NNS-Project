#include "../include/Node.h"
#include "../include/MathematicalFunctions.h"

/// @brief Initialzation of a node
/// @return 
Node* initNode() {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    node->dimension = NULL;
    node->neighbors = NULL;
    node->reversedNeighbors = NULL;
    node->cost = NULL;
    node->next = NULL;
    node->MaxCostToInsert = -1;

    return node;
}

/// @brief Adds a node to list 
/// @param headNode 
/// @param headDimension 
void addNode(Node** headNode, Dimension* headDimension) {
    Node* newNode = initNode();
    newNode->dimension = headDimension;
    // printf("head->value-%f\n", headDimension->value);
    newNode->norm = calculate_norm(headDimension);

    if (*headNode == NULL) {
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
