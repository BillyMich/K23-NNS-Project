#include "../include/knn.h"
#include <time.h>
#include <string.h>

double** matrixNodes;

/// @brief Here we make the K random nodes as the algorithm needs to run
/// @param graph 
/// @param K 
/// @param distance_function 
void KRandomNodes(Graph** graph, int K, String distance_function) {
    time_t t;
    srand((unsigned) time(&t));

    Node* currentNode = (*graph)->nodes;
    int numNodes = (*graph)->numNodes;
    printf("The Nodes are %d\n", numNodes);

    if(K > numNodes){
        fprintf(stderr, "Too many Neighbors. The Nodes are %d\n", numNodes);
        exit(EXIT_FAILURE);
    }
    for(int numNode = 0; numNode < numNodes; numNode++){
        int usedNumbers[K];

        for (int i = 0; i < K; i++) {

            int randomNumber;
            do {
                randomNumber = rand() % numNodes; 

            } while (isNumberUsed(usedNumbers, i, randomNumber, numNode));   // Check if the number has been used before
            usedNumbers[i] = randomNumber;

            Node* neighborNode = (*graph)->nodes;

            for(int j = 0; j < randomNumber; j++){
                neighborNode = neighborNode->next;
            }

            double cost = distance(currentNode, neighborNode, distance_function);
            
            addNeighbor(&(currentNode->neighbors), neighborNode, cost);
            addNeighbor(&(neighborNode->reversedNeighbors), currentNode, cost);
        }
        currentNode = currentNode->next;
    }
}

/// @brief Quick check to see if we can add
/// this node as a neightbor to another
/// @param usedNumbers 
/// @param count 
/// @param number 
/// @param numNode 
/// @return 
int isNumberUsed(int usedNumbers[], int count, int number, int numNode) {
    if ( numNode == number ){
        return 1;
    }
    for (int i = 0; i < count; i++) {
        if (usedNumbers[i] == number) {
            return 1;
        }
    }
    return 0;
}


/// @brief Check if the node is already a neighbour of the source Node
/// @param neighborsNodeName 
/// @param nodeNeighbors 
/// @param sourceNodeName 
/// @return 
int check(int neighborsNodeName, NodeNeighborsLinkedList* nodeNeighbors, Node* sourceNode, double cost) {


    if (sourceNode->MaxCostToInsert != -1) {
        if (cost >= sourceNode->MaxCostToInsert) {
            return 1;
        }
    }

    NodeNeighborsLinkedList* tempNode = nodeNeighbors;
    while (tempNode->next != NULL) {
        if(neighborsNodeName == tempNode->node->nodeNameInt)
            return 1;
        tempNode = tempNode->next;
    }

    if (cost >= tempNode->cost) {
        sourceNode->MaxCostToInsert = tempNode->cost;
        return 1;
    }else {
        sourceNode->MaxCostToInsert = tempNode->cost;
        return 0;
    }
    
    sourceNode->MaxCostToInsert = -1;
    return 0;
}
