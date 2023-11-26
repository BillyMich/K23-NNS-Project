#include <stdio.h>
#include <stdlib.h>
#include "../include/Graph.h"
#include "../include/FindAllRightNeighborsAlgorithm.h"
#include "../include/knn.h"
#include "../include/knn_improvments.h"
#include <time.h>

int main(int argc, char *argv[]) {

    int dimensions = atoi(argv[2]);
    int K = atoi(argv[3]);
    String distance_function = argv[4];

    // printf("Starting Creating Graph\n");

    Graph* graph = createGraphFromBinaryFile(argv[1], dimensions);
        
    printf("\n----- Starting KNN algorithm -----\n");

    // Measure real time for KNN algorithm
    clock_t knn_start, knn_end;
    knn_start = clock();

    knn_improved_algorithm(&graph, K, distance_function);
    // knn_algorithm(&graph, K, distance_function);

    knn_end = clock();
    printf("Time for KNN algorithm: %lf sec\n", (double)(knn_end - knn_start) / CLOCKS_PER_SEC);
    

    Graph* graphRightResults = createGraphFromBinaryFile(argv[1], dimensions);
    
    FindAllRightNeighbors(graphRightResults, distance_function);



    double accurationRate =findAccurationResult(graph , graphRightResults);
    printf("\n~ Acurate by %f %% ~\n",accurationRate);

    writeGraphToFile(graph, "Graph.txt"); 
    writeGraphToFile(graphRightResults, "GraphWithBrutal.txt"); 

    freeGraph(graph);
    freeGraph(graphRightResults);



    return 0;
}