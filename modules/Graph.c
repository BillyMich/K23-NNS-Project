#include "../include/Graph.h"
#include <math.h>

Graph* initGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    if (graph == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
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
    int flag = 0; // Flag for feof  

    // Read and process data from the binary file
    while (!feof(file)) {
        
        Dimension* headDimension = NULL;

        for (int i = 0; i < dimensions; i++){
            fread(&coordinate, sizeof(double), 1, file); // Read one double at a time
            if(feof(file)){
                flag = 1;
                break;
            }
            addDimension(&headDimension, i, coordinate);
            // printf("%d ---- %f\n", i, coordinate);
        }

        if(flag == 0)
            addNode(headNode, headDimension);

    }

    // graph->nodes=nodeHead;
    fclose(file);
    return graph;
}



void makeFile(String filename){
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }
    
    double coordinate[] = {1.000000,   0.000000,   1.000000,   0.000000,
                            1.000000,   0.139767,   1.000000,   0.139767,
                            1.000000,   0.278025,   1.000000,   0.278025,
                            1.000000,   0.416209,   1.000000,   0.416209};      
    fwrite(coordinate, sizeof(double)*16, 1, file); // Read one double at a time

}