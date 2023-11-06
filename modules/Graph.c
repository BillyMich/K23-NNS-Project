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
    if (graph == NULL) return;
    
    Node* current = graph->nodes;
    while (current != NULL) {
        Node* next = current->next;
        freeNode(current);
        current = next;
    }
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
        }

        if(flag == 0) {
            addNode(headNode, headDimension);
            graph->numNodes++;
        }
    }

    fclose(file);
    return graph;
}


double findAccurationResult(Graph* graph , Graph* graphRightResults){

    Node * tempNodeKNS = graph->nodes;
    Node * tempNodeRight = graphRightResults->nodes;
    double count = 0 ;
    double correct = 0;

    while (tempNodeKNS != NULL && tempNodeRight!= NULL  )
    {    
        NodeNeighborsLinkedList * tempNodeListKNS = tempNodeKNS->neighbors; 
        NodeNeighborsLinkedList * tempNodeListRight = tempNodeRight->neighbors;

        while (tempNodeListKNS != NULL && tempNodeListRight != NULL )
        {
            count++;
            if (tempNodeListKNS->node->nodeNameInt == tempNodeListRight->node->nodeNameInt) correct++;
            tempNodeListKNS = tempNodeListKNS->next;
            tempNodeListRight = tempNodeListRight->next;
        }
        
        tempNodeKNS = tempNodeKNS->next;
        tempNodeRight = tempNodeRight->next;
    }
    
    return  (correct / count )* 100;
}
