#ifndef KNN_IMPROVEMENTS_H
#define KNN_IMPROVEMENTS_H

#include "knn.h"
#include "projection_trees.h"

void knn_improved_algorithm(Graph** graph, TreeNode* treeRoot, int K, String distance_function, double p,double earlyTerminationParameter);

void changeNeighbors(Graph** graph);

void localJoin(Node** node, String distance_function, int pK);

int incrementalSearch(NodeNeighborsLinkedList* neighbor1, NodeNeighborsLinkedList* neighbor2);

NodeNeighborsLinkedList* sampling(NodeNeighborsLinkedList* neighbors, int pK);

//earlyTermination

#endif