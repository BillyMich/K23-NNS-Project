#include "include/Graph.h"

Graph createGraph() {
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
Graph createGraphFromBinaryFile(const String filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Create an empty graph
    Graph* graph = createGraph();
    if (graph == NULL) {
        fclose(file);
        perror("Error creating graph");
        return NULL;
    }

    // Read and process data from the binary file
    while (!feof(file)) {
        char nodeName[256];
        int numNeighbors;
        double cost, timeCost;

        // Read node name
        //TODO:This might need to be taken of!
        if (fread(nodeName, sizeof(nodeName), 1, file) != 1) {
            if (feof(file)) {
                break;
            }
            perror("Error reading node name");
            freeGraph(graph);
            fclose(file);
            return NULL;
        }
        //TODO:We need to constact the dimensions before createNode!
        //we need a dimension create

        // Create the node
        Node node = createNode(nodeName);
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