#include "../include/knn.h"
#include <time.h>
#include <string.h>

double** matrixNodes;
static int changes;


/// @brief This is the base of the knn algorithm
/// @param graph 
/// @param K 
/// @param distance_function 
void knn_algorithm(Graph** graph, int K, String distance_function){

    KRandomNodes(graph, K, distance_function);
    
    Node * tempNode = (*graph)->nodes;
    // double countLevel=0;
    // int round = 0;
    
    // matrixNodes = (double**)malloc((*graph)->numNodes*sizeof(double*));
    // for(int i = 0; i < (*graph)->numNodes; i++){
    //     matrixNodes[i] = (double*)malloc((*graph)->numNodes*sizeof(double));
    //     for(int j = 0; j < (*graph)->numNodes; j++){
    //         matrixNodes[i][j] = -1.00;
    //     }
    // }
    
    do {
        changes = 0;
        // printf("%d\n", changes);
        // printf("Started level : %d\n",++round);
        while (tempNode !=NULL) {

            NodeNeighborsLinkedList* tempNodeNeighborList = tempNode->reversedNeighbors;
            while (tempNodeNeighborList != NULL) {
                checkNeighborofNeighbors(graph, &tempNode, tempNodeNeighborList->node->reversedNeighbors, distance_function);
                checkNeighborofNeighbors(graph, &tempNode, tempNodeNeighborList->node->neighbors, distance_function);
                tempNodeNeighborList = tempNodeNeighborList->next;
            }
            
            NodeNeighborsLinkedList* tempReversedNeighbors = tempNode->neighbors;
            while (tempReversedNeighbors != NULL) {
                checkNeighborofNeighbors(graph, &tempNode, tempReversedNeighbors->node->neighbors, distance_function);
                checkNeighborofNeighbors(graph, &tempNode, tempReversedNeighbors->node->reversedNeighbors, distance_function);
                tempReversedNeighbors = tempReversedNeighbors->next;
            }
            
            tempNode = tempNode->next;
            
            // double percent  = (++countLevel/(double)(*graph)->numNodes) *100;
            // printf("Finished %f %%\n",percent);
        }

        // printf("-- this is count %d of round %d\n",changes,round);
        tempNode = (*graph)->nodes;
        // countLevel=0;
        // printf("%d\n", changes);
    } while (changes>0);

    for (int i = 0; i < (*graph)->numNodes; i++)
        free(matrixNodes[i]);
    free(matrixNodes);
    
}

/// @brief Here we add the neightbors and we cant how many
/// where succesfully added and we count them so we can use that data
/// for coculations
/// @param sourceNode 
/// @param neighbor 
/// @param distance_function 
/// @return 
void checkNeighborofNeighbors(Graph** graph, Node** sourceNode, NodeNeighborsLinkedList* neighbor, String distance_function ){
    
    NodeNeighborsLinkedList* tempNeighbors = neighbor;

    while (tempNeighbors != NULL) {
        int neighborName = tempNeighbors->node->nodeNameInt;
        int sourceName = (*sourceNode)->nodeNameInt;

        double cost = 0.0;
        if(matrixNodes[neighborName][sourceName] == -1.00){
            cost = distance((*sourceNode)->dimension, tempNeighbors->node->dimension, distance_function);
            matrixNodes[neighborName][sourceName] = cost;
        }
        else{
            cost = matrixNodes[neighborName][sourceName];
        }
        if (check(neighborName, (*sourceNode)->neighbors, sourceName, cost) == 0) {
            addNeighbor(&(*sourceNode)->neighbors, tempNeighbors->node, cost); //add the neighbor
            
            //
            Node* temp = (*graph)->nodes;
            while (temp != NULL && temp->nodeNameInt != neighborName){     
                temp = temp->next;
            }
            addNeighbor(&(temp->reversedNeighbors), *sourceNode, cost); //add the reverse

            int nameOfDeletedNeighbor = deleteLastNeighborNode(&((*sourceNode)->neighbors)); //delete neighbor
            if (nameOfDeletedNeighbor != -1) {
                deleteReverseNeighbor(&((*graph)->nodes), nameOfDeletedNeighbor, sourceName); //delete reverse
            }
    
            changes++;
        }
        tempNeighbors = tempNeighbors->next;
    }
}

/// @brief Here we make the K random nodes as the algorithm needs to run
/// @param graph 
/// @param K 
/// @param distance_function 
void KRandomNodes(Graph** graph, int K, String distance_function) {
    time_t t;
    srand((unsigned) time(&t));

    Node* currentNode = (*graph)->nodes;
    int numNodes = (*graph)->numNodes;

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

            double cost = distance(currentNode->dimension, neighborNode->dimension, distance_function);
            
            // matrixNodes[numNode][randomNumber] = cost;
            // matrixNodes[randomNumber][numNode] = cost;
            
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
int check(int neighborsNodeName, NodeNeighborsLinkedList* nodeNeighbors, int sourceNodeName, double cost) {
    if(neighborsNodeName == sourceNodeName){
        return 1;
    }

    NodeNeighborsLinkedList* tempNode = nodeNeighbors;
    NodeNeighborsLinkedList* lastNode = nodeNeighbors;
    while (tempNode != NULL) {
        if(neighborsNodeName == tempNode->node->nodeNameInt)
            return 1;

        if (tempNode->next != NULL) 
            lastNode = lastNode->next;

        tempNode = tempNode->next;
    }

    if (cost >= lastNode->cost) {
        return 1;
    }

    return 0;
}
