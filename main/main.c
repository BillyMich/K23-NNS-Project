#include <stdio.h>
#include "../include/Graph.h"
#include "../include/FindAllRightNeighborsAlgorithm.h"
#include "../include/knn.h"

#define NUM_THREADS 8 // You can adjust the number of threads based on your CPU's capabilities

int main(int argc, char *argv[]) {

    int dimensions = atoi(argv[2]);
    int K = atoi(argv[3]);
    String distance_function = argv[4];

    printf("Starting Creating Graph\n");
    Graph* graph = createGraphFromBinaryFile(argv[1], dimensions, K, distance_function);
    printf("Starting knn algorithm in  Graph\n");
    knn_algorithm(&graph, K, distance_function);

    printf("We created the graph!\n");


    Graph* graphRightResults = createGraphFromBinaryFile(argv[1], dimensions, K, distance_function);
    FindAllRightNeighbors(graphRightResults);
    
    double accurationRate =findAccurationResult(graph , graphRightResults);

    printf("This is acurate by %f %% \n",accurationRate);
    freeGraph(graph);
    freeGraph(graphRightResults);


    printf("Terminated succefully\n");
    return 0;
}
