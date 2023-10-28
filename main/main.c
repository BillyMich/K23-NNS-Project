#include <stdio.h>
#include "../include/Graph.h"
#include "../include/MathematicalFunctions.h"


int main(int argc, char *argv[])
{
    // printf("This is a %dDimension graph!\n",typeOfDimension);
    int dimensions = atoi(argv[2]);

    Graph* graph = createGraphFromBinaryFile(argv[1], dimensions);

    euclidean_distance(&graph->nodes->dimension,&graph->nodes->next->next->dimension);

    printf("\nWe created the graph!\n");
    
    freeGraph(graph);
    return 0;
}
