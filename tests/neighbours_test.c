/////////////////////////////////////////////////////////////////
//
//
// Unit tests for Neighbors.
// 
//
//////////////////////////////////////////////////////////////////

#include "acutest.h"	
#include "../include/Neighbors.h"
#include <stdio.h>

void testInitNeighbor() {
    Node* node = initNode();
    NodeNeighborsLinkedList* neighbor = initNeighbor(node, 1.2345);

    TEST_ASSERT(neighbor != NULL);
    TEST_ASSERT(neighbor->node == node);
    TEST_ASSERT(neighbor->cost == 1.2345);
    TEST_ASSERT(neighbor->next == NULL);

    freeNode(node);
    free(neighbor);
}

void testAddNeighbor() {

    Node* node1 = initNode();
    Node* node2 = initNode();
    Node* node3 = initNode();
    
    NodeNeighborsLinkedList* neighbors = NULL;

    addNeighbor(&neighbors, node1, 4.444);
    addNeighbor(&neighbors, node2, 3.333);
    addNeighbor(&neighbors, node3, 2.222);

    TEST_ASSERT(neighbors != NULL);
    TEST_ASSERT(neighbors->node == node3);
    TEST_ASSERT(neighbors->next != NULL);
    TEST_ASSERT(neighbors->next->node == node2);
    TEST_ASSERT(neighbors->next->next != NULL);
    TEST_ASSERT(neighbors->next->next->node == node1);

    freeNode(node1);
    freeNode(node2);
    freeNode(node3);
    freeNeighbors(neighbors);
}

void testDeleteLastNeighborNode() {
    Node *node1 = initNode();
    Node *node2 = initNode();
    Node* node3 = initNode();
    
    NodeNeighborsLinkedList *neighbors = NULL;

    addNeighbor(&neighbors, node1, 5.555);
    addNeighbor(&neighbors, node2, 3.333);
    addNeighbor(&neighbors, node3, 8.888);

    deleteLastNeighborNode(neighbors);
    TEST_ASSERT(neighbors != NULL);
    TEST_ASSERT(neighbors->node == node2);
    TEST_ASSERT(neighbors->next->node == node1);

    // Delete last neighbor when there are more than one neighbors
    deleteLastNeighborNode(neighbors);
    TEST_ASSERT(neighbors != NULL);
    TEST_ASSERT(neighbors->node == node2);
    TEST_ASSERT(neighbors->next == NULL);

    // Delete last neighbor when there is only one neighbor
    deleteLastNeighborNode(neighbors);
    TEST_ASSERT(neighbors == NULL);

    // Delete last neighbor when there are no neighbors (nothing should change)
    deleteLastNeighborNode(neighbors);
    TEST_ASSERT(neighbors == NULL);

    freeNode(node1);
    freeNode(node2);
    freeNode(node3);
    freeNeighbors(neighbors);
}


TEST_LIST = {
    {"testInitNeighbor", testInitNeighbor},
    {"testAddNeighbor", testAddNeighbor},
    {"testDeleteLastNeighborNode", testDeleteLastNeighborNode},
    {NULL, NULL}
};
