#include "../include/Graph.h"

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
    Node* current = graph->nodes;
    while (current != NULL) {
        Node* next = current->next;
        freeNode(current);
        current = next;
    }
    free(graph);
}


Graph* createGraphFromBinaryFile(String filename, int dimensions, int K, String distance_function) {
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

        if(flag == 0) {
            addNode(headNode, headDimension);
            graph->numNodes++;
        }

    }

    fclose(file);
    
    return graph;
}


void makeFile(String filename){
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }
    
    double coordinate[] = { 1.000000,   2.345678,   4.678923,   0.333333,
                            4.678923,   0.139767,   1.000000,   0.139767,
                            2.000000,   0.278025,   2.345678,   0.278025,
                            3.456789,   0.416209,   1.000000,   0.416209,
                            0.123456,   0.278025,   2.345678,   0.278025,
                            0.416209,   6.278025,   5.678923,   0.278025  };      
    fwrite(coordinate, sizeof(double)*24, 1, file); // Read one double at a time

}

