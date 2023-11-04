#ifndef KNN_H
#define KNN_H

#include "Graph.h"
#include "MathematicalFunctions.h"


//TODO: ALGORITHM
void knn_algorithm(Graph** graph, int K, String distance_function);

// Function to make K random neighbors (and reversed neighbors) for the Nodes
void KRandomNodes(Graph** graph, int K, String distance_function);

//
void checkNeighbor(Node** sourceNode, NodeNeighborsLinkedList* neighbor,String distance_function);

// Function to check if a number has been used before
int isNumberUsed(int usedNumbers[], int count, int number, int numNode);

//
int check(int neighborsNodeName, NodeNeighborsLinkedList* nodeNeighbors, int sourceNodeName);

#endif
