#include <stdio.h>
#include "../include/Graph.h"
#include "../include/FindAllRightNeighborsAlgorithm.h"
#include "../include/knn.h"


int main(int argc, char *argv[]) {

    int dimensions = atoi(argv[2]);
    int K = atoi(argv[3]);
    String distance_function = argv[4];

    Graph* graph = createGraphFromBinaryFile(argv[1], dimensions, K, distance_function);
    knn_algorithm(&graph, K, distance_function);

    printf("We created the graph!\n");

    Node* tempNode = graph->nodes;
    int i=0;

    while (tempNode != NULL) {
        Dimension* tempDime = tempNode->dimension;
        while (tempDime != NULL) {
        //    printf("Node %d dim: %d - %f\n", i, tempDime->dimensionValue, tempDime->value);
           tempDime = tempDime->next;
        } 
        printf("---- Node %d ----\n", i);
        NodeNeighborsLinkedList* tempNeighbor = tempNode->neighbors;
        while (tempNeighbor != NULL) {
            printf("Neig: %d\n", tempNeighbor->node->nodeNameInt);
            // printf("---cost: %f---\n", tempNeighbor->cost);
            tempNeighbor = tempNeighbor->next;
        }

        NodeNeighborsLinkedList* tempReversedNeighbor = tempNode->reversedNeighbors;
        while (tempReversedNeighbor != NULL) {
            printf("Reversed neig: %d\n", tempReversedNeighbor->node->nodeNameInt);
            tempReversedNeighbor = tempReversedNeighbor->next;
        }

        tempNode = tempNode->next;
        i++;
    }

    FindAllRightNeighbors(graph);
    freeGraph(graph);

    // makeFile(argv[1]);
    return 0;
}
