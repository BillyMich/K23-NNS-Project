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
    printf("after KRandomNodes\n");
    
    Node * tempNode = (*graph)->nodes;    
    
    do {
        changes = 0;
        while (tempNode !=NULL) {
            localJoin(&tempNode, distance_function);
            tempNode = tempNode->next;
        }
        
        //changes neighbors
        changeNeighbors(graph);
        //delete list with costs
        tempNode = (*graph)->nodes;

        while (tempNode !=NULL) {
            freeCost(tempNode->cost);
            tempNode->cost = NULL;
            tempNode = tempNode->next;
        }
        tempNode = (*graph)->nodes;

        printf("---- changes: %d\n", changes);
    } while (changes>0);
    
}

void changeNeighbors(Graph** graph) {

    Node* tempNode = (*graph)->nodes;

    while (tempNode !=NULL) {
        Cost* tempCost = tempNode->cost;
        while (tempCost != NULL) {

            Node* tempNode1 = (*graph)->nodes;
            Node* tempNode2 = (*graph)->nodes;

            //find the two nodes 
            while (tempNode1 != NULL && tempNode1->nodeNameInt != tempCost->node1) {
                tempNode1 = tempNode1->next;
            }
            while (tempNode2 != NULL && tempNode2->nodeNameInt != tempCost->node2) {
                tempNode2 = tempNode2->next;
            }

            // in tempNode2 we add tempNode1 as neighbor
            if (check(tempNode1->nodeNameInt, tempNode2->neighbors, tempNode2->nodeNameInt, tempCost->cost) == 0) {
                addNeighbor(&(tempNode2->neighbors), tempNode1, tempCost->cost); //add the neighbor
                addNeighbor(&(tempNode1->reversedNeighbors), tempNode2, tempCost->cost); //add the reverse

                //update reverse neighbors
                int nameOfDeletedNeighbor = deleteLastNeighborNode(&(tempNode2->neighbors)); //delete neighbor
                if (nameOfDeletedNeighbor != -1) {
                    deleteReverseNeighbor(&((*graph)->nodes), nameOfDeletedNeighbor, tempNode2->nodeNameInt); //delete reverse
                }
        
                changes++;
            }
            // in tempNode1 we add tempNode2 as neighbor
            if (check(tempNode2->nodeNameInt, tempNode1->neighbors, tempNode1->nodeNameInt, tempCost->cost) == 0) {
                addNeighbor(&(tempNode1->neighbors), tempNode2, tempCost->cost); //add the neighbor
                addNeighbor(&(tempNode2->reversedNeighbors), tempNode1, tempCost->cost); //add the reverse
                
                //update reverse neighbors
                int nameOfDeletedNeighbor = deleteLastNeighborNode(&(tempNode1->neighbors)); //delete neighbor
                if (nameOfDeletedNeighbor != -1) {
                    deleteReverseNeighbor(&((*graph)->nodes), nameOfDeletedNeighbor, tempNode1->nodeNameInt); //delete reverse
                }
        
                changes++;
            }

            tempCost = tempCost->next;
        }
        // next node
        tempNode = tempNode->next;
    }

}

void localJoin(Node** node, String distance_function) { 
    //TODO: for neighbors+reverse find distances in pairs
    NodeNeighborsLinkedList* temp = (*node)->neighbors;
    // printf("1\n");
    while(temp != NULL) {
        NodeNeighborsLinkedList* tempNeig = (*node)->neighbors;
        while(tempNeig != NULL) {
            int nodeName1 = temp->node->nodeNameInt;
            int nodeName2 = tempNeig->node->nodeNameInt;

            if ( nodeName1 != nodeName2 /*&& incrementalSearch() == 0 */) {
                double cost = distance(temp->node->dimension, tempNeig->node->dimension, distance_function);
                addCost(&((*node)->cost), nodeName1, nodeName2, cost);
            }
            tempNeig = tempNeig->next;
        }
        // printf("2\n");
        NodeNeighborsLinkedList* tempRev = (*node)->reversedNeighbors;
        while (tempRev != NULL) {
            int nodeName3 = temp->node->nodeNameInt;
            int nodeName4 = tempRev->node->nodeNameInt;

            if (nodeName3 != nodeName4 /*&& incrementalSearch() == 0 */) {
                double cost = distance(temp->node->dimension, tempRev->node->dimension, distance_function);
                addCost(&((*node)->cost), nodeName3, nodeName4, cost);
            }
            tempRev = tempRev->next;
        }
        // printf("3\n");
        temp = temp->next;
    } 
    // printf("4\n");
}

//incrementalSearch

//sampling
//earlyTermination



