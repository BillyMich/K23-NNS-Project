#ifndef KNN_IMPROVEMENTS_H
#define KNN_IMPROVEMENTS_H

#include "knn.h"
#include "projection_trees.h"


typedef struct DataJob {
    Node* node;
    struct DataJob* next;
} DataJob;

typedef struct Job {
    DataJob* dataJob;
    struct Job* next;
} Job;

typedef struct {
    Job* job;
    String distance_function;
    int pK;
    int type;
} JobInfo;

void knn_improved_algorithm(Graph** graph, TreeNode* treeRoot, int K, String distance_function, double p,double earlyTerminationParameter,int numberProssec);

void changeNeighbors(Node* node);

void localJoin(Node** node, String distance_function, int pK);

int incrementalSearch(NodeNeighborsLinkedList* neighbor1, NodeNeighborsLinkedList* neighbor2);

NodeNeighborsLinkedList* sampling(NodeNeighborsLinkedList* neighbors, int pK);

void addDataJob(DataJob** head, Node* Node);

void addJob(Job** head, DataJob* dataJob);

void freeJOB(Job* cost);

void freeAddDataJob(DataJob* cost);


//earlyTermination

#endif