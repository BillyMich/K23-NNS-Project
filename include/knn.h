#ifndef KNN_H
#define KNN_H

#include "Graph.h"
#include "MathematicalFunctions.h"

/// @brief  ALGORITHM
/// @param graph 
/// @param K 
/// @param distance_function 
void knn_algorithm(Graph** graph, int K, String distance_function);

/// @brief Function to make K random neighbors (and reversed neighbors) for the Nodes
/// @param graph 
/// @param K 
/// @param distance_function 
void KRandomNodes(Graph** graph, int K, String distance_function);

/// @brief  check the neighbours of the neighbor of the Node-sourceNode
/// @param sourceNode 
/// @param neighbor 
/// @param distance_function 
/// @return 
//void checkNeighborofNeighbors(Graph** graph, Node** sourceNode, NodeNeighborsLinkedList* neighbor, String distance_function );

/// @brief  Function to check if a number has been used before
/// @param usedNumbers 
/// @param count 
/// @param number 
/// @param numNode 
/// @return 
int isNumberUsed(int usedNumbers[], int count, int number, int numNode);

/// @brief check if the node is already existing in the list of neighbors of the sourceNode
/// @param neighborsNodeName 
/// @param nodeNeighbors 
/// @param sourceNodeName 
/// @return 
int check(int neighborsNodeName, NodeNeighborsLinkedList* nodeNeighbors, Node* sourceNodeName, double cost);

#endif
