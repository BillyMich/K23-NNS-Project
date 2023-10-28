#include "../include/Graph.h"
#include <math.h>

Graph* initGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    if (graph == NULL)
        return NULL;
    
    graph->nodes = NULL;
    graph->numNodes = 0;
    return graph;
}

// Function to free the entire graph
void freeGraph(Graph* graph) {
    if (graph == NULL)
        return;
    for (int i = 0; i < graph->numNodes; i++) {
        freeNode(graph->nodes + i);
    }

    free(graph->nodes);
    free(graph);
}

//TODO:Need to check if this works!
Graph* createGraphFromBinaryFile(String filename, int dimensions) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Create an empty graph
    Graph* graph = initGraph();
    if (graph == NULL) {
        fclose(file);
        perror("Error creating graph");
        return NULL;
    }

    double coordinate;
    Node** headNode = &graph->nodes; 
    // Read and process data from the binary file
    while (!feof(file)) {
    
        // int numNeighbors;
        // double cost, timeCost;
        Dimension* headDimension = NULL;

        for (int i = 0; i < dimensions; i++){
            fread(&coordinate, sizeof(double), 1, file); // Read one double at a time
            // printf("%d --- %f\n", i, coordinate);
            addDimension(&headDimension, i, coordinate);
        }
             
        addNode(headNode, headDimension);
        //printDimensions(headDimension);
    }

    // graph->nodes=nodeHead;
    fclose(file);
    return graph;
}
