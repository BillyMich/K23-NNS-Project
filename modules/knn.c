#include "../include/knn.h"
#include <time.h>
#include <string.h>

double** matrixNodes;


//knn algorithm
void knn_algorithm(Graph** graph, int K, String distance_function){
    
    matrixNodes = (double**)malloc((*graph)->numNodes*sizeof(double*));
    for(int i = 0; i < (*graph)->numNodes; i++){
        matrixNodes[i] = (double*)malloc((*graph)->numNodes*sizeof(double));
        for(int j = 0; j < (*graph)->numNodes; j++){
            matrixNodes[i][j] = -1.00;
        }
    }

    KRandomNodes(graph, K, distance_function);
    
    Node * tempNode = (*graph)->nodes;
    double countLevel=0;
    int changes = 10;
    
    for (int i = 0; i < 1; i++)
    {
        printf("Started level : %d\n",i);
        changes=0;
        while (tempNode !=NULL) {

            NodeNeighborsLinkedList* tempNodeNeighborList = tempNode->neighbors;
            while (tempNodeNeighborList != NULL) {
                changes +=checkNeighborofNeighbors(&tempNode, tempNodeNeighborList->node->neighbors, distance_function);
                changes +=checkNeighborofNeighbors(&tempNode, tempNodeNeighborList->node->reversedNeighbors, distance_function);
                tempNodeNeighborList = tempNodeNeighborList->next;
            }
            
            NodeNeighborsLinkedList* tempReversedNeighbors = tempNode->reversedNeighbors;
            while (tempReversedNeighbors != NULL) {
                changes +=checkNeighborofNeighbors(&tempNode, tempReversedNeighbors->node->neighbors, distance_function);
                changes +=checkNeighborofNeighbors(&tempNode, tempReversedNeighbors->node->reversedNeighbors, distance_function);
                tempReversedNeighbors = tempReversedNeighbors->next;
            }
            
            tempNode = tempNode->next;
            
            double percent  = (++countLevel/(double)(*graph)->numNodes) *100;
            printf("Finished %f %%\n",percent);
        }

        printf("-- this is count %d\n",changes);
        tempNode = (*graph)->nodes;
        countLevel=0;
    }

    for (int i = 0; i < (*graph)->numNodes; i++)
        free(matrixNodes[i]);
    free(matrixNodes);
    
}


int checkNeighborofNeighbors(Node** sourceNode, NodeNeighborsLinkedList* neighbor, String distance_function ){
    
    NodeNeighborsLinkedList* tempNeighbors = neighbor;
    int count = 0;
    while (tempNeighbors != NULL) {
        int neighborName = tempNeighbors->node->nodeNameInt;
        int sourceName = (*sourceNode)->nodeNameInt;

        if (check(neighborName, (*sourceNode)->neighbors, sourceName) == 0) {
            double cost = 0.0;
            if(matrixNodes[neighborName][sourceName] == -1.00){
                cost = distance((*sourceNode)->dimension, tempNeighbors->node->dimension, distance_function);
            }
            else{
                cost = matrixNodes[neighborName][sourceName];
            }
            addNeighbor(&(*sourceNode)->neighbors, tempNeighbors->node, cost);
            deleteLastNeighborNode((*sourceNode)->neighbors);
            count++;
        }
        tempNeighbors = tempNeighbors->next;
    }

    return count;
}


void KRandomNodes(Graph** graph, int K, String distance_function) {
    time_t t;
    srand((unsigned) time(&t));
    
    //TODO: make this if we need to check that case !!!!!!!
    // if(graph->numNodes < K){
    // }

    Node* currentNode = (*graph)->nodes;
    int numNodes = (*graph)->numNodes;

    for(int numNode = 0; numNode < numNodes; numNode++){
        // printf(" ---- Node number = %d\n", numNode);
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

            double cost = distance(currentNode->dimension, neighborNode->dimension, distance_function);
            
            matrixNodes[numNode][randomNumber] = cost;
            matrixNodes[randomNumber][numNode] = cost;
            
            addNeighbor(&(currentNode->neighbors), neighborNode, cost);
            addNeighbor(&(neighborNode->reversedNeighbors), currentNode, cost);
        }
        currentNode = currentNode->next;
    }
}


int isNumberUsed(int usedNumbers[], int count, int number, int numNode) {
    for (int i = 0; i < count; i++) {
        if (usedNumbers[i] == number) {
            return 1; // Number is already used
        }
        if ( numNode == number ){
            return 1;
        }
    }
    return 0; // Number is not used
}


// Check if the node is already a neighbour of the source Node
int check(int neighborsNodeName, NodeNeighborsLinkedList* nodeNeighbors, int sourceNodeName) {

    // if neighbor's neigbors is the sourceNode stop
    if(neighborsNodeName == sourceNodeName){
        return 1;
    }

    NodeNeighborsLinkedList* tempNode = nodeNeighbors;
    while (tempNode != NULL) {
        if(neighborsNodeName == tempNode->node->nodeNameInt)
            return 1;
        tempNode = tempNode->next;
    }
    return 0;
}
