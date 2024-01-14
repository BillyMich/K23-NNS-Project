/////////////////////////////////////////////////////////////////
//
//
// Unit tests for projection trees
// 
//
//////////////////////////////////////////////////////////////////
#include "acutest.h"
#include "../include/projection_trees.h"

void testGenerateRandomProjection() {
    int dimension = 10;
    int* projection = generateRandomProjection(dimension);

    TEST_CHECK(projection != NULL);

    for (int i = 0; i < dimension; i++) {
        TEST_CHECK(projection[i] == 1 || projection[i] == -1);
    }

    free(projection);
}

void testComputeProjection() {
    Node node;
    Dimension dim1 = {1, 1.0, NULL};
    Dimension dim2 = {2, 2.0, NULL};
    Dimension dim3 = {3, 3.0, NULL};
    node.dimension = &dim1;
    dim1.next = &dim2;
    dim2.next = &dim3;

    // Create a projection vector
    int projection[3] = {2, -1, 3};

    double result = computeProjection(&node, projection);
    TEST_CHECK(result == 9.00);
}

void testAddData() {
    Node* headData = NULL;
    Node node1 = {1, 1.00, NULL, NULL, NULL};
    Node node2 = {2, 2.00, NULL, NULL, NULL};
    Node node3 = {3, 3.00, NULL, NULL, NULL};

    addData(&headData, &node1);
    addData(&headData, &node2);
    addData(&headData, &node3);

    // Check if the nodes are added in the correct order
    TEST_CHECK(headData != NULL);
    TEST_CHECK(headData->nodeNameInt == 1);
    TEST_CHECK(headData->next != NULL);
    TEST_CHECK(headData->next->nodeNameInt == 2);
    TEST_CHECK(headData->next->next != NULL);
    TEST_CHECK(headData->next->next->nodeNameInt == 3);

    Node* current = headData;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
}


TEST_LIST = {
    {"testGenerateRandomProjection", testGenerateRandomProjection},
    {"testComputeProjection", testComputeProjection},
    {"testAddData", testAddData},
    {NULL, NULL}
};
