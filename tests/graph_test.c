/////////////////////////////////////////////////////////////////
//
//
// Unit tests for Graph.
// 
//
//////////////////////////////////////////////////////////////////

#include "acutest.h"	
#include "Graph.h"

void testInitGraph() {
    Graph* graph = initGraph();
    TEST_ASSERT(graph != NULL);
    freeGraph(graph); 
}

void testAddNodeToGraph() {

    Dimension* dimension1 = NULL;
    addDimension(&dimension1, 1, 1.2345);
    addDimension(&dimension1, 2, 20.0);

    Dimension* dimension2 = NULL;
    addDimension(&dimension2, 3, 5.6789);
    addDimension(&dimension2, 4, 15.0);

    Node* node1 = initNode();
    node1->dimension = dimension1;

    Node* node2 = initNode();
    node2->dimension = dimension2;

    // Add destinations between nodes
    addNeighbor(&(node1->neighbors), node2, 5.0);
    addNeighbor(&(node2->neighbors), node1, 3.0);

    // Check the number of nodes in the graph
    // TEST_ASSERT(graph->numNodes == 2);


    TEST_ASSERT(node1->dimension != NULL);
    TEST_ASSERT(node2->dimension != NULL);

    TEST_ASSERT(node1->dimension->dimensionValue == 1);
    TEST_ASSERT(node1->dimension->value == 1.2345);
    TEST_ASSERT(node2->dimension->dimensionValue == 3);
    TEST_ASSERT(node2->dimension->value == 5.6789);

    TEST_ASSERT(node1->neighbors != NULL);
    TEST_ASSERT(node2->neighbors != NULL);

    TEST_ASSERT(node1->neighbors->cost == 5.0);
    TEST_ASSERT(node2->neighbors->cost == 3.0);

    freeNode(node1);
    freeNode(node2);


}

//TODO: make it work!!!!!!!!!!!!!!!!!!!1
void testCreateGraphFromBinaryFile() {
    Graph* graph = createGraphFromBinaryFile("../datasets/dummy.bin", 4); // Assume 4 dimensions

    TEST_ASSERT(graph != NULL);

    FILE* file = fopen("../datasets/dummy.bin", "rb");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

	double coordinates[16]; // Array to store expected coordinates
    int dimensions = 4;
    int i = 0;

    // Read coordinates from the file and store them in the array
    while (!feof(file) && i < dimensions) {
        for (int j = 0; j < dimensions; j++) {
            fread(&coordinates[i * dimensions + j], sizeof(double), 1, file);
        }
        i++;
    }
	fclose(file);
    
	Node* currentNode = graph->nodes;
    i = 0;

    while (currentNode != NULL) {

		TEST_ASSERT(currentNode->dimension != NULL);
        TEST_ASSERT(currentNode->dimension->dimensionValue == 0);
        TEST_ASSERT(currentNode->dimension->value == coordinates[i]); 

        currentNode = currentNode->next;
        i= i + 4;
    }
    TEST_ASSERT(currentNode == NULL);

    Node* tempNode = graph->nodes;
    i=0;
    int countDiam = 0;
    int numOfArray = 0;
    while (tempNode != NULL) {
        Dimension* tempDime = tempNode->dimension;
        while (tempDime != NULL) {
        //    printf("Node %d : dim: %d - %d --- val: %f - %f\n", i, tempDime->dimensionValue, countDiam, tempDime->value, coordinates[numOfArray]);
           
           TEST_ASSERT(tempDime->dimensionValue == countDiam);
           TEST_ASSERT(tempDime->value == coordinates[numOfArray]);
           
           tempDime = tempDime->next;
           countDiam++;
           numOfArray++;
        } 
        tempNode = tempNode->next;
        
        i++;
        countDiam = 0;
    }

	int numNodes = 0;
	Node* currentNode2 = graph->nodes;
	while (currentNode2 != NULL) {
    	numNodes++;
    	currentNode2 = currentNode2->next;
	}
	TEST_ASSERT(numNodes == 4);

    freeGraph(graph);
}

//TODO: FIX THE LEAKS
void testCreateGraphDimensions() {
    Graph* graph = createGraphFromBinaryFile("datasets/dummy2.bin", 4); // Assume 4 dimensions
    TEST_ASSERT(graph != NULL);

    double expectedCoordinates[] = {1.000000,   2.345678,   4.678923,   0.333333,
                                    4.678923,   0.139767,   1.000000,   0.139767,
                                    2.000000,   0.278025,   2.345678,   0.278025,
                                    3.456789,   0.416209,   1.000000,   0.416209,
                                    0.123456,   0.278025 ,  2.345678,   0.278025,
                                    0.416209,   6.278025,   5.678923,   0.278025};  

    int expectedDimValue = 0;
    int expectedCoordIndex = 0;

    Node* currentNode = graph->nodes;

    while (currentNode != NULL) {
        TEST_ASSERT(currentNode->dimension != NULL);
       
        // Check dimensions and coordinates for this node
        Dimension* tempDim = currentNode->dimension;
        while (tempDim != NULL) {
            // printf("%d --- %d\n", tempDim->dimensionValue, expectedDimValue);
            // TEST_ASSERT(currentNode->dimension->dimensionValue == expectedDimValue);
            TEST_ASSERT(tempDim->value == expectedCoordinates[expectedCoordIndex]);

            tempDim = tempDim->next;
            expectedCoordIndex++; 
            expectedDimValue++;

        }
        NodeNeighborsLinkedList* tempNeighbor = currentNode->neighbors;
        int j = 0;
        while (tempNeighbor != NULL) {
            Dimension* tempDime2 = tempNeighbor->node->dimension;
            TEST_ASSERT(tempNeighbor != NULL);
            while (tempDime2 != NULL) {
                // printf("Neig: %d, dim: %d - %f\n", j, tempDime2->dimensionValue, tempDime2->value);
                // TEST_ASSERT();
                tempDime2 = tempDime2->next;
            } 
            j++;
            tempNeighbor = tempNeighbor->next;
        }

        currentNode = currentNode->next;
        expectedDimValue = 0; 
    }
    TEST_ASSERT(currentNode == NULL);
    freeGraph(graph);
}


void testFindAccurationResult() {
    // Create the graph
    Graph* graph = initGraph();
    Graph* graphRightResults = initGraph(); // Define graphRightResults

    Dimension* dimension1 = NULL;
    // Add nodes and neighbors to the graph
    addNode(&graph->nodes, dimension1);
    addNode(&graph->nodes, dimension1);
    addNode(&graph->nodes, dimension1);

    graphRightResults->nodes = graph->nodes; // Copy the nodes to graphRightResults
    // Test the function
    double accuracy = findAccurationResult(graph, graphRightResults, 3);
    printf("Accuracy: %f\n", accuracy);
//    TEST_ASSERT(accuracy > 0.00); // All neighbors match
    // Clean up
    freeGraph(graph);
    freeGraph(graphRightResults);

}


TEST_LIST = {
    {"testInitGraph", testInitGraph},
    {"testAddNodeToGraph", testAddNodeToGraph},
    {"testCreateGraphDimensions", testCreateGraphDimensions},
   // {"testFindAccurationResult", testFindAccurationResult},
    // {"testCreateGraphFromBinaryFile", testCreateGraphFromBinaryFile},
    { NULL, NULL }
};
