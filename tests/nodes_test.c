/////////////////////////////////////////////////////////////////
//
//
// Unit tests for Nodes.
//
//
//////////////////////////////////////////////////////////////////

#include "acutest.h"
#include "../include/Node.h"

void testInitNode() {
    Node *node = initNode();

    TEST_ASSERT(node != NULL);

    freeNode(node);
}

void testAddNode() {
    // Create some sample dimensions
    Dimension *dimension1 = NULL;
    addDimension(&dimension1, 1, 10.0);
    addDimension(&dimension1, 2, 20.0);

    Node *headNode = NULL;
    addNode(&headNode, dimension1);
    TEST_ASSERT(headNode != NULL);  // Check if the headNode is not NULL (a node was added)

    // Clean up
    freeNode(headNode);
    freeDimensions(dimension1);
}

void testAddDestination() {
    Node *node1 = initNode();
    Node *node2 = initNode();
    NodeNeighborsLinkedList *destination = addDestination(node1, node2, 5.0, 10.0);
    
    TEST_ASSERT(destination != NULL);                       // Check if the destination is not NULL (it was added successfully)
    TEST_ASSERT(node1->destinations->dest == node2);        // Check if the destination points to node2
    TEST_ASSERT(node1->destinations->cost == 5.0);          // Check the cost
    TEST_ASSERT(node1->destinations->time_cost == 10.0);    // Check time_cost

    NodeNeighborsLinkedList *destinationNode2 = node1->destinations;
    while (destinationNode2 != NULL){
        if (destinationNode2->dest == node2)
            break; // Found node2 as a destination
        destinationNode2 = destinationNode2->next;
    }
    TEST_ASSERT(destinationNode2 != NULL);      // Ensure that node2 is in the destination list

    freeNode(node1);
    freeNode(node2);
}

void testAddNodeWithMultipleDimensions() {
    Dimension *dimension1 = NULL;
    addDimension(&dimension1, 1, 10.0);
    addDimension(&dimension1, 2, 15.0);

    Node *headNode = NULL;
    addNode(&headNode, dimension1);

    TEST_ASSERT(headNode != NULL);
    TEST_ASSERT(headNode->dimension != NULL);
    TEST_ASSERT(headNode->dimension->dimensionValue == 1);
    TEST_ASSERT(headNode->dimension->value == 10.0);

    freeNode(headNode);
    freeDimensions(dimension1);
}

void testAddDestinationAndCheck() {
    Node *node1 = initNode();
    Node *node2 = initNode();
    NodeNeighborsLinkedList *destination = addDestination(node1, node2, 5.0, 10.0);

    TEST_ASSERT(destination != NULL);
    TEST_ASSERT(node1->destinations != NULL);
    TEST_ASSERT(node1->destinations->dest == node2);
    TEST_ASSERT(node1->destinations->cost == 5.0);
    TEST_ASSERT(node1->destinations->time_cost == 10.0);

    freeNode(node1);
    freeNode(node2);
}


TEST_LIST = {
    {"testInitNode", testInitNode},
    {"testAddNode", testAddNode},
    {"testAddDestination", testAddDestination},
    {"testAddNodeWithMultipleDimensions", testAddNodeWithMultipleDimensions},
    {"testAddDestinationAndCheck", testAddDestinationAndCheck},
    {NULL, NULL}
};