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
    
    // Prints for the graph from KNN 

    // Node* node = &(*graph->nodes);
    // while(node != NULL){
    //     printf("Node: %d \n", node->nodeNameInt);
    //     if (node->neighbors != NULL) {
    //         printf("Neighbors of Node: \n");
    //         NodeNeighborsLinkedList* neighbors = node->neighbors;
    //         while (neighbors != NULL) {
    //             printf("%d --- with cost %f\n", neighbors->node->nodeNameInt, neighbors->cost);
    //             neighbors = neighbors->next;
    //         }
    //     }
        // if (node->reversedNeighbors != NULL) {
        //     printf("Reversed neighbors of Node: \n");
        //     NodeNeighborsLinkedList* reversedNeighbors = node->reversedNeighbors;
        //     while (reversedNeighbors != NULL) {
        //         printf("%d --- with cost %f\n", reversedNeighbors->node->nodeNameInt, reversedNeighbors->cost);
        //         reversedNeighbors = reversedNeighbors->next;
        //     }
        // }
    //     node = node->next;
    // }

    // printf("We created the graph!\n");

    Graph* graphRightResults = createGraphFromBinaryFile(argv[1], dimensions);
    
    FindAllRightNeighbors(graphRightResults);

    // prints the graph with the right results

    // Node* node2 = &(*graphRightResults->nodes);
    // while(node2 != NULL){
    //     printf("Node: %d \n", node2->nodeNameInt);
    //     if (node2->neighbors != NULL) {
    //         printf("Neighbors of Node: \n");
    //         NodeNeighborsLinkedList* neighbors = node2->neighbors;
    //         while (neighbors != NULL) {
    //             printf("%d --- with cost %f\n", neighbors->node->nodeNameInt, neighbors->cost);
    //             neighbors = neighbors->next;
    //         }
    //     }
    //     if (node2->reversedNeighbors != NULL) {
    //         printf("Reversed neighbors of Node: \n");
    //         NodeNeighborsLinkedList* reversedNeighbors = node2->reversedNeighbors;
    //         while (reversedNeighbors != NULL) {
    //             printf("%d --- with cost %f\n", reversedNeighbors->node->nodeNameInt, reversedNeighbors->cost);
    //             reversedNeighbors = reversedNeighbors->next;
    //         }
    //     }
    //     node2 = node2->next;
    // }


    double accurationRate =findAccurationResult(graph , graphRightResults);
    printf("\n~ Acurate by %f %% ~\n",accurationRate);
    

    freeGraph(graph);
    freeGraph(graphRightResults);

    return 0;
}