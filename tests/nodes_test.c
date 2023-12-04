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
}

void testAddDestination() {
    Node *node1 = initNode();
    Node *node2 = initNode();
    addNeighbor(&(node1->neighbors), node2, 5.00);
    
    TEST_ASSERT(node2 != NULL);                          // Check if the destination is not NULL (it was added successfully)
    TEST_ASSERT(node1->neighbors->node == node2);        // Check if the destination points to node2
    TEST_ASSERT(node1->neighbors->cost == 5.0);          // Check the cost

    NodeNeighborsLinkedList *destinationNode2 = node1->neighbors;
    while (destinationNode2 != NULL){
        if (destinationNode2->node == node2)
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
}

void testAddNodeWithMultipleDimensions2() {
    Dimension *dimension1 = NULL;
    addDimension(&dimension1, 1, 20.0);
    addDimension(&dimension1, 2, 15.0);

    Node *headNode = NULL;
    addNode(&headNode, dimension1);

    TEST_ASSERT(headNode != NULL);
    TEST_ASSERT(headNode->dimension != NULL);
    TEST_ASSERT(headNode->dimension->dimensionValue == 1);
    TEST_ASSERT(headNode->dimension->value == 20.0);

    freeNode(headNode);
}


void testAddDestinationAndCheck() {
    Node *node1 = initNode();
    Node *node2 = initNode();
    addNeighbor(&(node1->neighbors), node2, 5.00);

    TEST_ASSERT(node2 != NULL);
    TEST_ASSERT(node1->neighbors != NULL);
    TEST_ASSERT(node1->neighbors->node == node2);
    TEST_ASSERT(node1->neighbors->cost == 5.0);

    freeNode(node1);
    freeNode(node2);
}

void testAddDestinationAndChec2() {
    Node *node1 = initNode();
    Node *node2 = initNode();
    addNeighbor(&(node1->neighbors), node2, 35.00);

    TEST_ASSERT(node2 != NULL);
    TEST_ASSERT(node1->neighbors != NULL);
    TEST_ASSERT(node1->neighbors->node == node2);
    TEST_ASSERT(node1->neighbors->cost == 35.0);

    freeNode(node1);
    freeNode(node2);
}

void testAddDestinationAndChec3() {
    Node *node1 = initNode();
    Node *node2 = initNode();
    addNeighbor(&(node1->neighbors), node2, 2.20);

    TEST_ASSERT(node2 != NULL);
    TEST_ASSERT(node1->neighbors != NULL);
    TEST_ASSERT(node1->neighbors->node == node2);
    TEST_ASSERT(node1->neighbors->cost == 2.20);

    freeNode(node1);
    freeNode(node2);
}




TEST_LIST = {
    {"testInitNode", testInitNode},
    {"testAddNode", testAddNode},
    {"testAddDestination", testAddDestination},
    {"testAddNodeWithMultipleDimensions", testAddNodeWithMultipleDimensions},
    {"testAddNodeWithMultipleDimensions2", testAddNodeWithMultipleDimensions2},
    {"testAddDestinationAndCheck", testAddDestinationAndCheck},
    {"testAddDestinationAndChec2", testAddDestinationAndChec2},
    {"testAddDestinationAndChec3", testAddDestinationAndChec3},
    {NULL, NULL}
};