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
    double p = atof(argv[5]);
    double earlyTerminationParameter = atof(argv[6]);
    int D = atoi(argv[7]);
    int proccesId = atoi(argv[8]);
    int numProcesses = atoi(argv[9]);

    Graph* graph = createGraphFromBinaryFile(argv[1], dimensions);
    
    TreeNode* treeRoot = buildRandomProjectionTree(graph->nodes, dimensions, D, graph->numNodes);
        
    printf("\n----- Starting KNN algorithm -----\n");

    clock_t knn_start, knn_end;
    knn_start = clock();

    knn_improved_algorithm(&graph, treeRoot, K, distance_function, p, earlyTerminationParameter,numProcesses);
    // knn_algorithm(&graph, K, distance_function);

    knn_end = clock();
    printf("Time for KNN algorithm: %lf sec\n", (double)(knn_end - knn_start) / CLOCKS_PER_SEC);

    // Graph* graphRightResults = createGraphFromBinaryFile(argv[1], dimensions);
    // FindAllRightNeighbors(graphRightResults, distance_function,K);
    
    // double accurationRate = findAccurationResult(graph, graphRightResults,K);

    // printf("\n~ Acurate by %f %% ~\n", accurationRate);

    char originalStr[] = "Graph";  // Original string
    char newStr[100];
    sprintf(newStr, "txtfiles/%d%s-%lf-%f-%f-%d-%d.txt", 
    proccesId, originalStr,(double)(knn_end - knn_start) / CLOCKS_PER_SEC,p,earlyTerminationParameter,D,numProcesses);

    writeGraphToFile(graph, newStr);

    //writeGraphToFile(graphRightResults, newStr); 
    freeGraph(graph);
    //freeGraph(graphRightResults);
    freeTree(treeRoot);

    return 0;
}