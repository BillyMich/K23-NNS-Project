#include "include/Graph.h"

//TODO:dimension need to be created before sending it here!
Node createNode(const Dimension dimension) {
    Node node = (Node)malloc(sizeof(Node));
    if(node == NULL)
        return NULL;

    //Here we will add the dimensions
    node->dimension = dimension;
    node->destinations = NULL;
    node->nextNode = NULL;

    return node;
}


void  freeNode(Node node) {
    if (node == NULL)
        return;
    NodeNeighborsLinkedList current = node->destinations;
    while (current != NULL) {
        NodeNeighborsLinkedList next = current->next;
        free(current);
        current = next;
    }
    free(node);
}
