#include "include/Graph.h"

Graph intiGraph() {
    Graph graph = (Graph)malloc(sizeof(Graph));
    if (graph == NULL)
        return NULL;
    
    graph->nodes = NULL;
    graph->numNodes = 0;
    return graph;
}

// Function to free the entire graph
void freeGraph(Graph graph) {
    if (graph == NULL)
        return;
    for (int i = 0; i < graph->numNodes; i++) {
        freeNode(graph->nodes + i);
    }

    free(graph->nodes);
    free(graph);
}

//TODO:Need to check if this works!
Graph createGraphFromBinaryFile(const String filename, int dimensions) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Create an empty graph
    Graph graph = initGraph();
    if (graph == NULL) {
        fclose(file);
        perror("Error creating graph");
        return NULL;
    }

    String buffer[256];
    // Read and process data from the binary file
    while (!feof(file)) {
    
        int numNeighbors;
        double cost, timeCost;

        // fread(buffer, );        
        
        //TODO:We need to constact the dimensions before createNode!
        //we need a dimension create

        // Create the node
        Node node = createNode();
        if (node == NULL) {
            perror("Error creating node");
            freeGraph(graph);
            fclose(file);
            return NULL;
        }
        // Add the node to the graph
    }


    fclose(file);
    return graph;
}