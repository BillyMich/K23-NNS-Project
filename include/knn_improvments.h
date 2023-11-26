#ifndef KNN_IMPROVEMENTS_H
#define KNN_IMPROVEMENTS_H

#include "../include/knn.h"

void knn_improved_algorithm(Graph** graph, int K, String distance_function);

void changeNeighbors(Graph** graph);

void localJoin(Node** node, String distance_function);

int incrementalSearch(NodeNeighborsLinkedList* neighbor, int node1Name, int node2Name);

//sampling
//earlyTermination

#endif