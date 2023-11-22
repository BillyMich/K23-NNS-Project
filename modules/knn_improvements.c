#include "../include/knn_improvments.h"
#include <time.h>
#include <string.h>

int changes;

/// @brief This is the base of the knn algorithm
/// @param graph 
/// @param K 
/// @param distance_function 
void knn_improved_algorithm(Graph** graph, int K, String distance_function){

    KRandomNodes(graph, K, distance_function);
    
    Node * tempNode = (*graph)->nodes;    
    
    do {
        changes = 0;
        while (tempNode !=NULL) {
            localJoin(tempNode, distance_function);
            tempNode = tempNode->next;
        }
        tempNode = (*graph)->nodes;
        //changes neighbors
        
        changeNeighbors(graph);

        //delete list with costs
        freeCost(tempNode->cost);
        tempNode->cost = NULL;

            //next node
            // tempNode = tempNode->next;
        // }

        
        tempNode = (*graph)->nodes;
    } while (changes>0);
    
}

void changeNeighbors(Graph** graph) {

    Node* tempNode = (*graph)->nodes;

    while (tempNode !=NULL) {
        Cost* tempCost = tempNode->cost;
        while (tempCost != NULL) {
            tempCost->node1;
            tempCost->node2;
            tempCost->cost;

            //find the two nodes 
            //add at each other as neighbor 
            //update reverse neighbors


            tempCost = tempCost->next;
        }
        // next node
        tempNode = tempNode->next;
    }

}

void localJoin(Node** node, String distance_function) { 
    //TODO: for neighbors+reverse find distances in pairs
    NodeNeighborsLinkedList* temp = (*node)->neighbors;

    while(temp != NULL) {
        NodeNeighborsLinkedList* tempNeig = (*node)->neighbors;
        while(tempNeig != NULL) {
            int nodeName1 = temp->node->nodeNameInt;
            int nodeName2 = tempNeig->node->nodeNameInt;

            if ( nodeName1 != nodeName2 /*&& incrementalSearch() == 0 */) {
                double cost = distance(temp->node->dimension, tempNeig->node->dimension, distance_function);
                addCost(&temp->cost, nodeName1, nodeName2, cost);
            }
            tempNeig = tempNeig->next;
        }

        NodeNeighborsLinkedList* tempRev = (*node)->reversedNeighbors;
        while (tempRev != NULL) {
            int nodeName3 = temp->node->nodeNameInt;
            int nodeName4 = tempRev->node->nodeNameInt;

            if (nodeName3 != nodeName4 /*&& incrementalSearch() == 0 */) {
                double cost = distance(temp->node->dimension, tempRev->node->dimension, distance_function);
                addCost(&temp->cost, nodeName3, nodeName4, cost);
            }
            tempRev = tempRev->next;
        }
    }
    temp = temp->next;
}

//incrementalSearch

//sampling
//earlyTermination



