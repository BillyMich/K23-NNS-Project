#include "../include/knn_improvments.h"
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

static int changes;

#define NUM_THREADS 10
#define JOB_QUEUE_SIZE 30

typedef struct {
    Node* node;
    String distance_function;
    int pK;
} JobInfo;


JobInfo jobQueue[JOB_QUEUE_SIZE];
int jobCount = 0;
pthread_mutex_t queueMutex;
pthread_mutex_t changeInMemory;

pthread_cond_t jobAvailable;


typedef enum {
    IDLE,
    WORKING 
} ThreadState;

typedef struct {
    int threadId;
    ThreadState state;
} ThreadInfo;


void *workerFunction(void *threadarg) {
    ThreadInfo *myInfo = (ThreadInfo *)threadarg;
    
    while (1) {
        // Wait for a job
        pthread_mutex_lock(&queueMutex);
        while (jobCount <= 0) {
            myInfo->state = IDLE;
            pthread_cond_wait(&jobAvailable, &queueMutex);
        }

        myInfo->state = WORKING;
        JobInfo job = jobQueue[--jobCount];
        // Report job completion and switch back to idle
        pthread_mutex_unlock(&queueMutex);
        printf("Thread %d: Working on node %d\n", myInfo->threadId, job.node->nodeNameInt);
        localJoin(&job.node, job.distance_function,job.pK);  
        changeNeighbors(job.node);
        myInfo->state = IDLE;
    }
    pthread_exit(NULL);
}



/// @brief Main Function of KNN algorithm with improvements
/// @param graph 
/// @param K 
/// @param distance_function 
void knn_improved_algorithm(Graph** graph, int K, String distance_function, double p, double earlyTerminationParameter){

    // Using the existing function to "make" the random Nodes
    KRandomNodes(graph, K, distance_function);
    Node * tempNode = (*graph)->nodes;
    
    int pK = p*K;
    double changerPersent;
    printf("The pK (neighbor) nodes for Sampling is %d\n", pK);

    pthread_t threads[NUM_THREADS];
    ThreadInfo threadInfo[NUM_THREADS];
    pthread_mutex_init(&queueMutex, NULL);
    pthread_mutex_init(&changeInMemory, NULL);
    pthread_cond_init(&jobAvailable, NULL);

      for(int i = 0; i < NUM_THREADS; i++) {
        threadInfo[i].threadId = i;
        threadInfo[i].state = IDLE;
        int rc = pthread_create(&threads[i], NULL, workerFunction, (void *)&threadInfo[i]);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    do {
        changes = 0;

        while (tempNode != NULL) {
           while (jobCount == JOB_QUEUE_SIZE)
            {
            }
            
            pthread_mutex_lock(&queueMutex);
            if (jobCount < JOB_QUEUE_SIZE) {
                jobQueue[jobCount++] = (JobInfo){tempNode,distance_function,pK}; // Assign values to your Job struct
                pthread_cond_signal(&jobAvailable);
            }
            pthread_mutex_unlock(&queueMutex);
            tempNode = tempNode->next;
        }
        
        while (jobCount != 0) {
            // Wait for all jobs to complete
        }    

        // Changes neighbors
        // Delete list with costs
        tempNode = (*graph)->nodes;

        while (tempNode !=NULL) {
            freeCost(tempNode->cost);
            tempNode->cost = NULL;
            tempNode = tempNode->next;
        }

        tempNode = (*graph)->nodes;
        changerPersent =  (double) changes / ((double)(*graph)->numNodes * K) ;
        
        // We can delete those print if you want
        printf("Changes: %d\n", changes);
        printf("Changes-early-termination: %f\n", changerPersent);

    } while (changerPersent>earlyTerminationParameter);

    pthread_mutex_destroy(&queueMutex);
    pthread_cond_destroy(&jobAvailable);
    
}

void changeNeighbors(Node* tempNode) {

        Cost* tempCost = tempNode->cost;
        pthread_mutex_lock(&changeInMemory);

        while (tempCost != NULL) {

            Node* tempNode1 =  tempCost->node1;
            Node* tempNode2 = tempCost->node2;
            // In tempNode2 we add tempNode1 as neighbor
            if (check(tempNode1->nodeNameInt, tempNode2->neighbors, tempNode2->nodeNameInt, tempCost->cost) == 0) {
                addNeighbor(&(tempNode2->neighbors), tempNode1, tempCost->cost);            //add the neighbor
                addNeighbor(&(tempNode1->reversedNeighbors), tempNode2, tempCost->cost);    //add the reverse

                // Update reverse neighbors
                Node*  nameOfDeletedNeighbor = deleteLastNeighborNode(&(tempNode2->neighbors));                  //delete neighbor
                if (nameOfDeletedNeighbor != NULL) {
                    deleteReverseNeighbor(nameOfDeletedNeighbor, tempNode2->nodeNameInt); //delete reverse
                }
                changes++;
            }
            // In tempNode1 we add tempNode2 as neighbor
            if (check(tempNode2->nodeNameInt, tempNode1->neighbors, tempNode1->nodeNameInt, tempCost->cost) == 0) {
                addNeighbor(&(tempNode1->neighbors), tempNode2, tempCost->cost);            //add the neighbor
                addNeighbor(&(tempNode2->reversedNeighbors), tempNode1, tempCost->cost);    //add the reverse
                
                // Update reverse neighbors
                Node* nameOfDeletedNeighbor = deleteLastNeighborNode(&(tempNode1->neighbors));                  //delete neighbor
                if (nameOfDeletedNeighbor != NULL) {
                    deleteReverseNeighbor(nameOfDeletedNeighbor, tempNode1->nodeNameInt); //delete reverse
                }
                changes++;
            }
            tempCost = tempCost->next;
        }
        pthread_mutex_unlock(&changeInMemory);
}


// ----- functions for improvements -----

void localJoin(Node** node, String distance_function, int pK) { 
    // without sampling method, we use the neighbours of the Node 
    // NodeNeighborsLinkedList* temp = (*node)->neighbors;
    
    if (node == NULL || *node == NULL)
        return;

    // With the Sampling method, we create a new list of the pK neighbors (that have the flag True)
    NodeNeighborsLinkedList* head = sampling((*node)->neighbors, pK);
    NodeNeighborsLinkedList* temp = head;

    while(temp != NULL) {
        NodeNeighborsLinkedList* tempNeig = (*node)->neighbors;
        while(tempNeig != NULL) {
            int nodeName1 = temp->node->nodeNameInt;
            int nodeName2 = tempNeig->node->nodeNameInt;

            if ( nodeName1 != nodeName2 && incrementalSearch(tempNeig, temp) == 1 ) {
                double cost = distance(temp->node->dimension, tempNeig->node->dimension, distance_function);
                addCost(&((*node)->cost), temp->node, tempNeig->node, cost);

                // Update the flags
                tempNeig->flag = 0;
                temp->flag = 0;
            }
            tempNeig = tempNeig->next;
        }
        NodeNeighborsLinkedList* tempRev = (*node)->reversedNeighbors;
        while (tempRev != NULL) {
            int nodeName3 = temp->node->nodeNameInt;
            int nodeName4 = tempRev->node->nodeNameInt;

            if (nodeName3 != nodeName4 && incrementalSearch(tempRev, temp) == 1) {
                double cost = distance(temp->node->dimension, tempRev->node->dimension, distance_function);
                addCost(&((*node)->cost), temp->node, tempRev->node, cost);

                // Update the flags
                tempRev->flag = 0;
                temp->flag = 0;
            }
            tempRev = tempRev->next;
        }
        temp = temp->next;
    } 
    // free the list of the Neighbours with true flags -- used only in Sampling
    freeNeighbors(head);
}

// Incremental Search 
// Comparing the Flags of the Nodes
int incrementalSearch(NodeNeighborsLinkedList* neighbor1, NodeNeighborsLinkedList* neighbor2) {

    if (neighbor1 == NULL || neighbor2 == NULL)
        return 0; // One or both nodes not found

    if (neighbor1->flag == 0 && neighbor2->flag == 0){
        return 0; // At least one flag is false, local join not allowed
    }
    return 1; // Both flags are true, local join allowed

}


// Sampling Method
// Checking the flags of the Nodes and returns a list of those nodes
NodeNeighborsLinkedList* sampling(NodeNeighborsLinkedList* neighbors, int pK) {
    NodeNeighborsLinkedList* tempNeighbor = neighbors;
    NodeNeighborsLinkedList* samplingNeighborsHead = NULL;

    while (tempNeighbor != NULL && pK > 0) {
        if (tempNeighbor->flag == 1) {
            addNeighbor(&samplingNeighborsHead, tempNeighbor->node, tempNeighbor->cost); //free after use
            pK--;
        }
        tempNeighbor = tempNeighbor->next;
    }
    return samplingNeighborsHead;     
}
