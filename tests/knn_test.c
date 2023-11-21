/////////////////////////////////////////////////////////////////
//
//
// Unit tests for KNN algorithm.
// 
//
//////////////////////////////////////////////////////////////////

#include "acutest.h"	
#include "knn.h"


void testCheck(){
    Node* node1 = (Node*)malloc(sizeof(Node));
    node1->nodeNameInt = 1;
    Node* node2 = (Node*)malloc(sizeof(Node));
    node2->nodeNameInt = 2;
    NodeNeighborsLinkedList* head1 = (NodeNeighborsLinkedList*)malloc(sizeof(NodeNeighborsLinkedList));
    head1->node = node1;
    head1->cost = 1.0;
    NodeNeighborsLinkedList* head2 = (NodeNeighborsLinkedList*)malloc(sizeof(NodeNeighborsLinkedList));
    head2->node = node2;
    head2->cost = 2.0;

    head1->next = head2;
    head2->next = NULL;

    TEST_ASSERT(check(0, head1, 0, 1.5) == 1); //source's and neighbor's name are the same 
    TEST_ASSERT(check(1, head1, 0, 1.5) == 1); //neighbor's name already in the head
    TEST_ASSERT(check(2, head1, 2, 1.5) == 1); //source's and neighbor's name are the same and neighbor's name already in the head

    TEST_ASSERT(check(3, head1, 0, 2.5) == 1); //source's and neighbor's name are the different and neighbor's name not in the head but cost is higher
    TEST_ASSERT(check(3, head1, 0, 1.5) == 0); //source's and neighbor's name are the different and neighbor's name not in the head and cost is lower

    free(node1);
    free(node2);
    free(head1);
    free(head2);
}

void testIsNumberUsed() {
    int usedNumbers[] = {4, 10, 22, 13};
    TEST_ASSERT(isNumberUsed(usedNumbers, 4, 10, 7) == 1); //number is being already used
    TEST_ASSERT(isNumberUsed(usedNumbers, 4, 6, 6) == 1); //node number same with number but number isn't already used
    TEST_ASSERT(isNumberUsed(usedNumbers, 4, 13, 13) == 1); //both node number is same with number and number is being already used
    
    TEST_ASSERT(isNumberUsed(usedNumbers, 4, 55, 7) == 0); //number that is never been used before
}

void testKRandomNodes(Graph* graph) {

    Node* nodes = graph->nodes;
    int countNodes = 0;

    int nodeName;
    int neighborName;

    int nodesNeighbors[8][4];
    int i;

    while (nodes != NULL) {
        nodeName = nodes->nodeNameInt;

        NodeNeighborsLinkedList* neighbors = nodes->neighbors;
        int countNeighbors = 0;
        i = 0;
        while (neighbors != NULL) {
            neighborName = neighbors->node->nodeNameInt;
            TEST_ASSERT(nodeName != neighborName); //check that the node itself is not included

            nodesNeighbors[nodeName][i] = neighborName;
            i++;

            TEST_ASSERT(neighbors->cost > 0); //check the costs

            countNeighbors++;
            neighbors = neighbors->next;
        }
        TEST_ASSERT(countNeighbors == 4); //check that the random neighbors are 4

        countNodes++;
        nodes = nodes->next;
    }
    nodes = graph->nodes;
    
    int reversed_flag;
    int reversedNeighborName;
    while (nodes != NULL) {
        nodeName = nodes->nodeNameInt;

        NodeNeighborsLinkedList* reversedNeighbors = nodes->reversedNeighbors;
        while (reversedNeighbors != NULL) {
            reversed_flag = 0;
            reversedNeighborName = reversedNeighbors->node->nodeNameInt;
            for (int i = 0; i < 4; i++) {
                if (nodesNeighbors[reversedNeighborName][i] == nodeName) {
                    reversed_flag = 1;
                    break;
                }
            }

            TEST_ASSERT(reversed_flag == 1); //check the reversed neighbors

            reversedNeighbors = reversedNeighbors->next;
        }
        nodes = nodes->next;
    }

    for (int node = 0; node < 8; node++) {
        for (int neighbor = 0; neighbor < 4; neighbor++) {
            for (int i = neighbor+1 ; i < 4; i++) {
                TEST_ASSERT(nodesNeighbors[node][neighbor] != nodesNeighbors[node][i]); //check that all the neighbors are different
            }      
        }
    }

    freeGraph(graph);
}

void testKRandomNodesWithEuclidean() {
    Graph* graphEuclidean = createGraphFromBinaryFile("../datasets/knn_test.bin", 2); // Assume 2 dimensions
    KRandomNodes(&graphEuclidean, 4, "euclidean"); //4 neighbors
    testKRandomNodes(graphEuclidean);
}

void testKRandomNodesWithManhattan() {
    Graph* graphManhattan = createGraphFromBinaryFile("../datasets/knn_test.bin", 2); // Assume 2 dimensions
    KRandomNodes(&graphManhattan, 4, "manhattan"); //4 neighbors
    testKRandomNodes(graphManhattan);
}

TEST_LIST = {
    {"testCheck",testCheck},
    {"testIsNumberUsed", testIsNumberUsed},
    {"testKRandomNodesWithEuclidean", testKRandomNodesWithEuclidean},
    {"testKRandomNodesWithManhattan", testKRandomNodesWithManhattan},
    {NULL, NULL}
};
