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

void testLocalJoinAllNull() {
    Node* node = NULL;
    String distance_function = NULL;
    int pK = 0;

    localJoin(&node, distance_function, pK);
    TEST_CHECK(node == NULL);
}

void testLocalJoin() {
    // Create a node with NULL neighbors
    Node* node = malloc(sizeof(Node));
    node->neighbors = NULL;
    node->reversedNeighbors = NULL;
    node->cost = NULL;

    // Call the localJoin function
    localJoin(&node, "euclidean", 5);

    // Assert that the neighbors remain NULL
    TEST_ASSERT(node->neighbors == NULL);
    TEST_ASSERT(node->reversedNeighbors == NULL);
    TEST_ASSERT(node->cost == NULL);

    // Clean up
    free(node);
}

void testLocalJoinOneNeighbor() {
    // Create a node with one neighbor
    Node* node = malloc(sizeof(Node));
    node->neighbors = initNeighbor(node, 1.0);
    node->reversedNeighbors = NULL;
    node->cost = NULL;

    // Set the flag of the neighbor to 1
    node->neighbors->flag = 1;

    // Call the localJoin function
    localJoin(&node, "euclidean", 1);

    // Clean up
    freeNeighbors(node->neighbors);
    free(node);
}


void testIncrementalSearchFailScenario() {
   
    NodeNeighborsLinkedList * neighbor1 = initNeighbor(NULL, 1.0);
    NodeNeighborsLinkedList * neighbor2 = initNeighbor(NULL, 2.0);
    neighbor1->flag = 0;
    neighbor2->flag = 0;
    TEST_ASSERT(incrementalSearch(neighbor1,neighbor2) == 0); //source's and neighbor's name are the different and neighbor's name not in the head but cost is higher

    freeNeighbors(neighbor1);
    freeNeighbors(neighbor2);
}

void testIncrementalSearchFailScenario2() {
   
    NodeNeighborsLinkedList * neighbor1 = initNeighbor(NULL, 1.0);
    NodeNeighborsLinkedList * neighbor2 = NULL;
    neighbor1->flag = 0;
    TEST_ASSERT(incrementalSearch(neighbor1,neighbor2) == 0); //source's and neighbor's name are the different and neighbor's name not in the head but cost is higher
    
    freeNeighbors(neighbor1);
}

void testIncrementalSearchFailScenario3() {
   
    NodeNeighborsLinkedList * neighbor1 = NULL;
    NodeNeighborsLinkedList * neighbor2 = NULL;
    TEST_ASSERT(incrementalSearch(neighbor1,neighbor2) == 0); //source's and neighbor's name are the different and neighbor's name not in the head but cost is higher

}

void testIncrementalSearchSucessScenario1() {
   
    NodeNeighborsLinkedList * neighbor1 = initNeighbor(NULL, 1.0);
    NodeNeighborsLinkedList * neighbor2 = initNeighbor(NULL, 2.0);
    neighbor1->flag = 1;
    neighbor2->flag = 0;
    TEST_ASSERT(incrementalSearch(neighbor1,neighbor2) == 1); //source's and neighbor's name are the different and neighbor's name not in the head but cost is higher

    freeNeighbors(neighbor1);
    freeNeighbors(neighbor2);
}

void testIncrementalSearchSucessScenario2() {
   
    NodeNeighborsLinkedList * neighbor1 = initNeighbor(NULL, 1.0);
    NodeNeighborsLinkedList * neighbor2 = initNeighbor(NULL, 2.0);
    neighbor1->flag = 1;
    neighbor2->flag = 1;
    TEST_ASSERT(incrementalSearch(neighbor1,neighbor2) == 1); //source's and neighbor's name are the different and neighbor's name not in the head but cost is higher

    freeNeighbors(neighbor1);
    freeNeighbors(neighbor2);
}

void testIncrementalSearchSucessScenario3() {
   
    NodeNeighborsLinkedList * neighbor1 = initNeighbor(NULL, 1.0);
    NodeNeighborsLinkedList * neighbor2 = initNeighbor(NULL, 2.0);
    neighbor1->flag = 0;
    neighbor2->flag = 1;
    TEST_ASSERT(incrementalSearch(neighbor1,neighbor2) == 1); //source's and neighbor's name are the different and neighbor's name not in the head but cost is higher

    freeNeighbors(neighbor1);
    freeNeighbors(neighbor2);
}


void testSampling() {
    // Create a linked list of neighbors
    NodeNeighborsLinkedList* neighbors = initNeighbor(NULL, 1.0);
    neighbors->flag = 1;
    neighbors->next = initNeighbor(NULL, 2.0);
    neighbors->next->flag = 0;
    neighbors->next->next = initNeighbor(NULL, 3.0);
    neighbors->next->next->flag = 1;
    neighbors->next->next->next = NULL;

    // Call the sampling function with pK = 2
    NodeNeighborsLinkedList* sampledNeighbors = sampling(neighbors, 2);

    // Assert that the sampled neighbors are correct
    TEST_ASSERT(sampledNeighbors != NULL);
    TEST_ASSERT(sampledNeighbors->node == neighbors->node);
    TEST_ASSERT(sampledNeighbors->cost == neighbors->cost);
    TEST_ASSERT(sampledNeighbors->next != NULL);
    TEST_ASSERT(sampledNeighbors->next->node == neighbors->next->next->node);
    TEST_ASSERT(sampledNeighbors->next->cost == neighbors->next->next->cost);
    TEST_ASSERT(sampledNeighbors->next->next == NULL);

    // Clean up
    freeNeighbors(neighbors);
    freeNeighbors(sampledNeighbors);
}



TEST_LIST = {
    {"testSampling",testSampling},
    {"testLocalJoinAllNull", testLocalJoinAllNull},
    {"testLocalJoin", testLocalJoin},
    {"testLocalJoinOneNeighbor", testLocalJoinOneNeighbor},
    {"testIncrementalSearchFailScenario", testIncrementalSearchFailScenario},
    {"testIncrementalSearchFailScenario2", testIncrementalSearchFailScenario2},
    {"testIncrementalSearchFailScenario3", testIncrementalSearchFailScenario3},
    {"testIncrementalSearchSucessScenario1", testIncrementalSearchSucessScenario1},
    {"testIncrementalSearchSucessScenario2", testIncrementalSearchSucessScenario2},
    {"testIncrementalSearchSucessScenario3", testIncrementalSearchSucessScenario3},
    {NULL, NULL}
};
