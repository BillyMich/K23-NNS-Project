#ifndef KNN_IMPROVEMENTS_H
#define KNN_IMPROVEMENTS_H

#include "../include/knn.h"

void knn_improved_algorithm(Graph** graph, int K, String distance_function, double p);

void changeNeighbors(Graph** graph);

void localJoin(Node** node, String distance_function, int pK);

int incrementalSearch(NodeNeighborsLinkedList* neighbor1, NodeNeighborsLinkedList* neighbor2);

NodeNeighborsLinkedList* sampling(NodeNeighborsLinkedList* neighbors, int pK);

//earlyTermination

#endif