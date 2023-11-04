#include "../include/knn.h"
#include <time.h>
#include <string.h>

// Check if the 
int check( int NeighborsNodeName, NodeNeighborsLinkedList* nodeNeighbors){

    NodeNeighborsLinkedList* tempNode = nodeNeighbors;
    while (tempNode != NULL) {
        if(NeighborsNodeName == tempNode->node->nodeNameInt)
            return 1;
        tempNode = tempNode->next;
    }
    return 0;
}


void checkNeighborOfNeighbor(Node** sourceNode, Node** neighbor, String distance_function){
    
    NodeNeighborsLinkedList* tempNeighbors = (*neighbor)->neighbors;

    while (tempNeighbors != NULL) {
        
        if (check(tempNeighbors->node->nodeNameInt, (*sourceNode)->neighbors) == 0) {
            double cost = 0.0;

            if(strcmp(distance_function, "euclidean") == 0){
                cost = euclidean_distance((*neighbor)->dimension, tempNeighbors->node->dimension);
            }
            else if(strcmp(distance_function, "manhattan") == 0){
                cost = manhattan_distance((*neighbor)->dimension, tempNeighbors->node->dimension);
            }

            addNeighbor(&(*sourceNode)->neighbors,tempNeighbors->node,cost);
            deleteLastNeighborNode((*sourceNode)->neighbors);
        }

        tempNeighbors = tempNeighbors->next;
    }
    
}

//TODOOOOOO
void knn_algorithm(Graph** graph, int K, String distance_function){
    
    KRandomNodes(graph, K, distance_function);
    Node * head = (*graph)->nodes;
    Node * tempNode = head;

    while (tempNode !=NULL)
    {
        NodeNeighborsLinkedList* tempNodeNeighborList = tempNode->neighbors;
        while (tempNodeNeighborList !=NULL)
        {
            checkNeighborOfNeighbor(&tempNode, &tempNodeNeighborList->node, distance_function);
            tempNodeNeighborList = tempNodeNeighborList->next;
        }
        
        tempNode= tempNode->next;
    }
    
    
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
            // printf("%d\n", randomNumber);

            Node* neighborNode = (*graph)->nodes;

            for(int j = 0; j < randomNumber; j++){
                neighborNode = neighborNode->next;
            }

            double distance = 0.0;

            if(strcmp(distance_function, "euclidean") == 0){
                distance = euclidean_distance((currentNode->dimension), (neighborNode->dimension));
                // printf("distance eu: %f\n", distance);
            }
            else if(strcmp(distance_function, "manhattan") == 0){
                distance = manhattan_distance(currentNode->dimension, neighborNode->dimension);
                // printf("distance man: %f\n", distance);
            }

            addNeighbor(&(currentNode->neighbors), neighborNode, distance);
            addNeighbor(&(neighborNode->reversedNeighbors), currentNode, distance);
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