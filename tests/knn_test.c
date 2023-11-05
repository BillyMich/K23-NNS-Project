/////////////////////////////////////////////////////////////////
//
//
// Unit tests for KNN algorithm.
// 
//
//////////////////////////////////////////////////////////////////

#include "acutest.h"	
#include "knn.h"

void testKRandomNodes() {
    Graph* graphEuclidean = createGraphFromBinaryFile("../datasets/knn_test.bin", 2); // Assume 2 dimensions and 4 neighbors

    KRandomNodes(&graphEuclidean, 4, "euclidean");
    //1. check that the random neighbors are 4
    Node* nodes = graphEuclidean->nodes;
    int countNodes = 0;
    while (nodes != NULL) {
        NodeNeighborsLinkedList* neighbors = nodes->neighbors;
        int countNeighbors = 0;
        while (neighbors != NULL) {
            countNeighbors++;
            neighbors = neighbors->next;
        }
        TEST_ASSERT(countNeighbors == 4);
        countNodes++;
        nodes = nodes->next;
    }

    //2. check the reversed neighbors

    //check that the node itself is node includes
    //check that all the neighbors are different
    //check the costs


    // Graph* graphManhattan = createGraphFromBinaryFile("../datasets/knn-test.bin", 2); // Assume 2 dimensions and 4 neighbors

    // KRandomNodes(&graphManhattan, 4, "manhattan");
    //check that the random neighbors are 4
    //check the reversed neighbors
    //check that the node itself is node includes
    //check that all the neighbors are different
    //check the costs

    freeGraph(graphEuclidean);
    // freeGraph(graphManhattan);
}

TEST_LIST = {
    {"testKRandomNodes", testKRandomNodes},
    {NULL, NULL}
};