#include <stdio.h>
#include "include/Dimension.h"



int main(int argc, char *argv[])
{
//   printf("This is a %dDimension graph!\n",typeOfDimension);

//   graph = createGraphFromBinaryFile(argv[1]);

    Dimension* head = NULL;

    // Adding elements to the linked list
    addDimension(&head, 1, 3.14);
    addDimension(&head, 2, 2.71);
    addDimension(&head, 3, 1.618);
    printDimensions(head);
    printDimensions(head);

    printf("We created the graph!");


//   freeGraph(graph);
    return 0;
}