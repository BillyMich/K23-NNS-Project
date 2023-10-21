#include <stdio.h>
#include "include/Graph.h"



int main(int argc, char *argv[])
{
    printf("This is a %dDimension graph!\n",typeOfDimension);

    graph = createGraphFromBinaryFile(argv[1]);

    printf("We created the graph!");


    freeGraph(graph);
    return 0;
}