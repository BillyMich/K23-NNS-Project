#include "../include/Graph.h"
#include <math.h>

Graph* initGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    if (graph == NULL)
        return NULL;
    
    graph->nodes = NULL;
    graph->numNodes = 0;
    return graph;
}

// Function to free the entire graph
void freeGraph(Graph* graph) {
    if (graph == NULL)
        return;
    for (int i = 0; i < graph->numNodes; i++) {
        freeNode(graph->nodes + i);
    }

    free(graph->nodes);
    free(graph);
}

//TODO:Need to check if this works!
Graph* createGraphFromBinaryFile(String filename, int dimensions) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Create an empty graph
    Graph* graph = initGraph();
    if (graph == NULL) {
        fclose(file);
        perror("Error creating graph");
        return NULL;
    }

    char buffer[sizeof(double)];
    double coordinate;
    int i=0; //we dont need it-just to check the fread
    // Read and process data from the binary file
    while (!feof(file)) {
    
        int numNeighbors;
        double cost, timeCost;

        //TODO:We need to constact the dimensions before createNode!

        fread(&coordinate, sizeof(double), 1, file); // Read one double at a time
        // coordinate = atof(buffer); // string to double - another function: strtod 
        // check if really reads doubles
        printf("%d coordinate-%f \n", i++, coordinate);  
        
        //we need a dimension create to put the coordinates in 
         

        // Create the node
        // Node node = createNode();
        // if (node == NULL) {
        //     perror("Error creating node");
        //     freeGraph(graph);
        //     fclose(file);
        //     return NULL;
        // }
        // Add the node to the graph
    }


    fclose(file);
    return graph;
}

// int convert(long long n) {

//   int dec = 0, i = 0, rem;

//   while (n != 0) {
//     // get remainder of n divided by 10
//     rem = n % 10;
//     // divide n by 10
//     n /= 10;

//     // multiply rem by (2 ^ i)
//     // add the product to dec
//     dec += rem * pow(2, i);
//     // increment i
//     ++i;
//   }

//   return dec;
// }


// double bitstring_to_double(const char* p)
// {
//     unsigned long long x = 0;
//     for (; *p; ++p)
//     {
//         x = (x << 1) + (*p - '0');
//     }
//     double d;
//     memcpy(&d, &x, 8);
//     return d;
// }
