#include "../include/knn.h"
#include <time.h>
#include <string.h>

//TODOOOOOO
void knn_algorithm(Graph** graph, int K, String distance_function){
    
    KRandomNodes(graph, K, distance_function);

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
                distance = euclidean_distance(&(currentNode->dimension), &(neighborNode->dimension));
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