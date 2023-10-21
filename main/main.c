#include <stdio.h>
#include "include/Graph.h"



int main(int argc, char *argv[])
{
    // printf("This is a %dDimension graph!\n",typeOfDimension);
    int dimensions = atoi(argv[2]);

    Graph graph = createGraphFromBinaryFile(argv[1], dimensions);

    printf("We created the graph!");


    freeGraph(graph);
    return 0;
}