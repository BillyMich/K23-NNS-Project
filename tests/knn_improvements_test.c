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


void testaddCost() {
   
}


TEST_LIST = {
    {"testLocalJoin", testLocalJoin},
    {"testIncrementalSearchFailScenario", testIncrementalSearchFailScenario},
    {"testIncrementalSearchFailScenario2", testIncrementalSearchFailScenario2},
    {"testIncrementalSearchFailScenario3", testIncrementalSearchFailScenario3},
    {"testIncrementalSearchSucessScenario1", testIncrementalSearchSucessScenario1},
    {"testIncrementalSearchSucessScenario2", testIncrementalSearchSucessScenario2},
    {"testIncrementalSearchSucessScenario3", testIncrementalSearchSucessScenario3},
    {NULL, NULL}
};
