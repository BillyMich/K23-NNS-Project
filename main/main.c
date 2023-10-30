#include <stdio.h>
#include "../include/Graph.h"
#include "../include/MathematicalFunctions.h"


int main(int argc, char *argv[])
{
    // printf("This is a %dDimension graph!\n",typeOfDimension);
    int dimensions = atoi(argv[2]);
    int K = atoi(argv[3]);

    Graph* graph = createGraphFromBinaryFile(argv[1], dimensions, K);

    //Node* tempNode = graph->nodes;

    printf("We created the graph!\n");

    // while (tempNode != NULL) {
    //     Dimension* tempDime = tempNode->dimension;
    //     while (tempDime != NULL) {
    //     //    printf("Node %d dim: %d - %f\n", i, tempDime->dimensionValue, tempDime->value);
    //        tempDime = tempDime->next;
    //     } 

    //     NodeNeighborsLinkedList* tempNeighbor = tempNode->neighbors;
    //     int j = 0;
    //     while (tempNeighbor != NULL) {
    //         Dimension* tempDime2 = tempNeighbor->node->dimension;
    //         while (tempDime2 != NULL) {
    //             printf("Node %d, neig: %d, dim: %d - %f\n", i, j, tempDime2->dimensionValue, tempDime2->value);
                
    //             tempDime2 = tempDime2->next;
    //         } 
    //         j++;
    //         tempNeighbor = tempNeighbor->next;
    //     }
        
    //     tempNode = tempNode->next;
    //     i++;
    // }

    euclidean_distance(&graph->nodes->dimension,&graph->nodes->next->next->dimension);

    freeGraph(graph);
    // makeFile(argv[1]);
    return 0;
}
