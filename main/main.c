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

    //TODO-- time calc
    Graph* graph = createGraphFromBinaryFile(argv[1], dimensions);
    
    //TODO-- time calc
    TreeNode* treeRoot = buildRandomProjectionTree(graph->nodes, dimensions, D, graph->numNodes);
        
    printf("\n----- Starting KNN algorithm -----\n");

    clock_t knn_start, knn_end;
    knn_start = clock();

    knn_improved_algorithm(&graph, treeRoot, K, distance_function, p, earlyTerminationParameter);
    // knn_algorithm(&graph, K, distance_function);

    knn_end = clock();
    printf("Time for KNN algorithm: %lf sec\n", (double)(knn_end - knn_start) / CLOCKS_PER_SEC);
    
    Graph* graphRightResults = createGraphFromBinaryFile(argv[1], dimensions);
    
    FindAllRightNeighbors(graphRightResults, distance_function);

    double accurationRate = findAccurationResult(graph, graphRightResults,K);
    double accurationSuperRate = findAccurationResultSuperAccurate(graph, graphRightResults);

    printf("\n~ Acurate by %f %% ~\n", accurationRate);
    printf("~ Acurate Supper  by %f %% ~\n", accurationSuperRate);

    writeGraphToFile(graph, "Graph.txt"); 
    writeGraphToFile(graphRightResults, "GraphWithBrutal.txt"); 

    freeGraph(graph);
    freeGraph(graphRightResults);

    freeTree(treeRoot);

    // createBinary("100000.bin");

    return 0;
}