#include <stdio.h>
#include "../include/Graph.h"
#include "../include/MathematicalFunctions.h"
#include "../include/FindAllRightNeighborsAlgorithm.h"


int main(int argc, char *argv[])
{
    // printf("This is a %dDimension graph!\n",typeOfDimension);
    int dimensions = atoi(argv[2]);
    int K = atoi(argv[3]);

    Graph* graph = createGraphFromBinaryFile(argv[1], dimensions, K);

    //Node* tempNode = graph->nodes;

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

    //euclidean_distance(&graph->nodes->dimension,&graph->nodes->next->next->dimension);
    FindAllRightNeighbors(graph);
    freeGraph(graph);
    // makeFile(argv[1]);
    return 0;
}
