#ifndef PROJECTIONTREES_H
#define PROJECTIONTREES_H

#include <stdio.h>
#include <stdlib.h>
#include "common_types.h"
#include "Node.h"

// Define a data structure for a node in the tree
typedef struct TreeNode {
    int *projection; // Random projection vector
    double threshold; // Threshold for the hyperplane
    struct TreeNode *left;
    struct TreeNode *right;
    Node *data; // Only for leaf nodes
} TreeNode;


int* generateRandomProjection(int dimension);

double computeProjection(Node *point, int *projection);

void addData(Node** headData, Node* data);

TreeNode* buildRandomProjectionTree(Node* data, int dimension, int D, int K);

void searchNeighbors(TreeNode *root, Node *query, int dimension, int k);

void freeTree(TreeNode *root);

#endif 
