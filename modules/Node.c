#include "include/Graph.h"

//TODO:dimension need to be created before sending it here!
Node createNode(const String name, const Dimension dimension) {
    Node node = (Node)malloc(sizeof(Node));
    if(node == NULL)
        return NULL;
    node->name = (String)malloc(strlen(name) + 1);
    if (node->name == NULL) {
        free(node); // Clean up previously allocated memory
        return NULL; // Memory allocation failed
    }
    strcpy(node->name, name);

    //Here we will add the dimensions
    node->dimension = dimension;

    node->destinations = NULL;

    return node;
}


void  freeNode(Node node) {
    if (node == NULL)
        return;
    free(node->name);
    NodeNeighborsLinkedList current = node->destinations;
    while (current != NULL) {
        NodeNeighborsLinkedList next = current->next;
        free(current);
        current = next;
    }
    free(node);
}
