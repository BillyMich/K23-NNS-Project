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
   
}


TEST_LIST = {
    {"testLocalJoin", testLocalJoin},
    {"testIncrementalSearch", testIncrementalSearch},
    {"testSampling", testSampling},
    {NULL, NULL}
};
