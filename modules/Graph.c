#include "../include/Graph.h"
#include "../include/MathematicalFunctions.h"
#include <math.h>
#include <time.h>

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

int isNumberUsed(int usedNumbers[], int count, int number, int numNode);
void KRandomNodes(Graph** graph, int K);

Graph* createGraphFromBinaryFile(String filename, int dimensions, int K) {
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

    KRandomNodes(&graph, K);
    
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

// --------------------- USUFULL FUNCTIONS --------------------- //

// Function to check if a number has been used before
int isNumberUsed(int usedNumbers[], int count, int number, int numNode) {
    for (int i = 0; i < count; i++) {
        if (usedNumbers[i] == number) {
            return 1; // Number is already used
        }
        if ( numNode == number ){
            return 1;
        }
    }
    return 0; // Number is not used
}

//TODO: make neighbors list
void KRandomNodes(Graph** graph, int K) {
    time_t t;
    srand((unsigned) time(&t));
    
    //TODO: make this if we need to check that case !!!!!!!
    // if(graph->numNodes < K){
    // }

    Node* currentNode = (*graph)->nodes;
    int numNodes = (*graph)->numNodes;

    for(int numNode = 0; numNode < numNodes; numNode++){
        // printf(" ---- Node number = %d\n", numNode);
        int usedNumbers[K];

        for (int i = 0; i < K; i++) {
            int randomNumber;
            do {
                randomNumber = rand() % numNodes;
            } while (isNumberUsed(usedNumbers, i, randomNumber, numNode));   // Check if the number has been used before

            usedNumbers[i] = randomNumber;
            // printf("%d\n", randomNumber);

            Node* neighborNode = (*graph)->nodes;

            for(int j = 0; j < randomNumber; j++){
                neighborNode = neighborNode->next;
            }

            double distance = euclidean_distance(&(currentNode->dimension), &(neighborNode->dimension));
            // printf("distance: %f\n", distance);
            addNeighbor(&(currentNode->neighbors), neighborNode, distance, 0.33);
        }
        currentNode = currentNode->next;
    }
}
