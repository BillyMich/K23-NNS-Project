#include "../include/knn.h"
#include "../include/knn_improvments.h"
#include <time.h>
#include <string.h>

// double** matrixDistances;
int changes;


/// @brief This is the base of the knn algorithm
/// @param graph 
/// @param K 
/// @param distance_function 
void knn_improved_algorithm(Graph** graph, int K, String distance_function){

    KRandomNodes(graph, K, distance_function);

    // matrixDistances = (double**)malloc((*graph)->numNodes*sizeof(double*));
    // for(int i = 0; i < (*graph)->numNodes; i++){
    //     matrixDistances[i] = (double*)malloc((*graph)->numNodes*sizeof(double));
    //     for(int j = 0; j < (*graph)->numNodes; j++){
    //         matrixDistances[i][j] = -1.00;
    //     }
    // }
    
    Node * tempNode = (*graph)->nodes;    
    
    do {
        changes = 0;
        while (tempNode !=NULL) {

            NodeNeighborsLinkedList* tempNodeNeighborList = tempNode->reversedNeighbors;
            while (tempNodeNeighborList != NULL) {
            // localJoin   
            }
            tempNode = tempNode->next;
            
        }
        //changes neighbors
        //while()

        //delete list with costs
        // freeCost
        tempNode = (*graph)->nodes;
    } while (changes>0);

    // for (int i = 0; i < (*graph)->numNodes; i++)
    //     free(matrixNodes[i]);
    // free(matrixNodes);
    
}

void localJoin(Node** node, String distance_function) { 
    //TODO: for neighbors+reverse find distances in pairs
    NodeNeighborsLinkedList* temp = (*node)->neighbors;

    while(temp != NULL) {
        NodeNeighborsLinkedList* tempNeig = (*node)->neighbors;
        while(tempNeig != NULL) {
            int nodeName1 = temp->node->nodeNameInt;
            int nodeName2 = tempNeig->node->nodeNameInt;

            if ( nodeName1 != nodeName2 /*&& incrementalSearch == 0 */) {
                double cost = distance(temp->node->dimension, tempNeig->node->dimension, distance_function);
                addCost(&temp->cost, nodeName1, nodeName2, cost);
            }
            tempNeig = tempNeig->next;
        }

        NodeNeighborsLinkedList* tempRev = (*node)->reversedNeighbors;
        while (tempRev != NULL) {
            int nodeName3 = temp->node->nodeNameInt;
            int nodeName4 = tempRev->node->nodeNameInt;

            if (nodeName3 != nodeName4) {
                double cost = distance(temp->node->dimension, tempRev->node->dimension, distance_function);
            }
            tempRev = tempRev->next;
        }
    }
    temp = temp->next;
}

//incrementalSearch

//sampling
//earlyTermination



