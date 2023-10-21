#include "include/Graph.h"


NodeNeighborsLinkedList addDestination(Node node, Node dest, double cost, double time_cost) {
    NodeNeighborsLinkedList newDestination = (NodeNeighborsLinkedList)malloc(sizeof(NodeNeighborsLinkedList));
    if (newDestination == NULL)
        return NULL;
    newDestination->dest = dest;
    newDestination->cost = cost;
    newDestination->time_cost = time_cost;
    newDestination->next = node->destinations;
    node->destinations = newDestination;
    return newDestination;
}

void freeDestination(NodeNeighborsLinkedList destination) {
    if (destination == NULL)
        return;
    freeNode(destination->dest);
    free(destination);
}