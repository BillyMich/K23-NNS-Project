/////////////////////////////////////////////////////////////////
//
//
// Unit tests for KNN improvements.
// 
//
//////////////////////////////////////////////////////////////////

#include "acutest.h"
#include "knn_improvments.h"
#include "knn.h"


void testLocalJoin() {
    
}


void testIncrementalSearch() {

    NodeNeighborsLinkedList node1 = {NULL, 1, 1, NULL};
    NodeNeighborsLinkedList node2 = {NULL, 2, 1, NULL};
    NodeNeighborsLinkedList node3 = {NULL, 3, 0, NULL};
    NodeNeighborsLinkedList node4 = {NULL, 4, 0, NULL}; 
    
    // Both flags are true
    int result1 = incrementalSearch(&node1, &node2);
    TEST_ASSERT(result1 == 1);  // local join allowed

    // One or both nodes not found
    int result2 = incrementalSearch(NULL, &node2);
    TEST_ASSERT(result2 == -1);  // nodes not found

    // Both flags are false
    int result3 = incrementalSearch(&node4, &node3);
    TEST_ASSERT(result3 == 0);  // local join not allowed
}


void testSampling() {
    // Create a list of neighbors
    Node node1 = {1, NULL, NULL, NULL, NULL};
    Node node2 = {2, NULL, NULL, NULL, NULL};
    Node node3 = {3, NULL, NULL, NULL, NULL};
    
    NodeNeighborsLinkedList neighbor1 = {&node1, 1.0, 1, NULL};
    NodeNeighborsLinkedList neighbor2 = {&node2, 2.0, 0, NULL};
    NodeNeighborsLinkedList neighbor3 = {&node3, 3.0, 1, NULL};

    // Create a linked list of neighbors
    neighbor1.next = &neighbor2;
    neighbor2.next = &neighbor3;

    // pK is equal to the number of neighbors with flag set to 1
    int pK1 = 2;
    NodeNeighborsLinkedList* result1 = sampling(&neighbor1, pK1);
    TEST_ASSERT(result1 != NULL);
    TEST_ASSERT(result1->node == &node1);
    TEST_ASSERT(result1->next != NULL);
    TEST_ASSERT(result1->next->node == &node3);
    TEST_ASSERT(result1->next->next == NULL);

    // pK is less than the number of neighbors with flag set to 1
    int pK2 = 1;
    NodeNeighborsLinkedList* result2 = sampling(&neighbor1, pK2);
    TEST_ASSERT(result2 != NULL);
    TEST_ASSERT(result2->node != NULL);
    TEST_ASSERT(result2->next == NULL);

    // Free the memory allocated for the linked lists
    freeNeighbors(result1);
    freeNeighbors(result2);

}


TEST_LIST = {
    {"testLocalJoin", testLocalJoin},
    {"testIncrementalSearch", testIncrementalSearch},
    {"testSampling", testSampling},
    {NULL, NULL}
};
