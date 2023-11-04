#ifndef KNN_H
#define KNN_H

#include "Graph.h"
#include "MathematicalFunctions.h"




// Function to check if a number has been used before
int isNumberUsed(int usedNumbers[], int count, int number, int numNode);

// Function to make K random neighbors (and reversed neighbors) for the Nodes
void KRandomNodes(Graph** graph, int K, String distance_function);

//TODO: ALGORITHM
void knn_algorithm(Graph** graph, int K, String distance_function);


void checkNeighborOfNeighbor(Node** sourceNode, Node** neighbor, String distance_function);


int check( int NeighborsNodeName, NodeNeighborsLinkedList* nodeNeighbors);



#endif
