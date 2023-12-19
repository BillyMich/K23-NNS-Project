#include <math.h>
#include "../include/projection_trees.h"

// Function to generate a random projection vector
int* generateRandomProjection(int dimension) {
    int* projection = (int*)malloc(dimension * sizeof(int));
    for (int i = 0; i < dimension; i++) {
        projection[i] = rand() % 2 == 0 ? 1 : -1; // Randomly set to +1 or -1
    }
    return projection;
}

// Function to compute the dot product of a data point and a projection vector
double computeProjection(Node* node, int *projection) {
    double result = 0;
    int count = 0;
    Dimension* tempDimension = node->dimension;
    while (tempDimension != NULL) {
        result += tempDimension->value * projection[count];

        tempDimension = tempDimension->next;
        count++;
    }
    return result;
    //maybe an array with all the computed projections
}

void addData(Node** headData, Node* data) {
    Node* newData = (Node*)malloc(sizeof(Node));

    newData->nodeNameInt = data->nodeNameInt;
    newData->norm = data->norm;
    newData->dimension = data->dimension;

    newData->cost = NULL;
    newData->neighbors = NULL;
    newData->reversedNeighbors = NULL;
    newData->next = NULL;

    if (*headData == NULL) {
        *headData = newData;
    }
    else { 
        Node* temp = *headData;
        while (temp->next!=NULL) {
            temp = temp->next;
        }
        temp->next = newData;
    }
}

// Function to build a random projection tree
TreeNode* buildRandomProjectionTree(Node* data, int dimension, int D, int K) {
    if (D <= K) {
        // Create a leaf node
        TreeNode* leaf = (TreeNode*)malloc(sizeof(TreeNode));
        leaf->data = data;
        leaf->left = NULL;
        leaf->right = NULL;

        while (data != NULL){
            printf("- %d\n", data->nodeNameInt);
            data = data->next;
        }
        printf("------------------\n");
        return leaf;
    }

    // Create a non-leaf node
    TreeNode* treeNode = (TreeNode*)malloc(sizeof(TreeNode));
    treeNode->projection = generateRandomProjection(dimension);
    treeNode->threshold = (double)rand() / RAND_MAX; // Random threshold between 0 and 1 ή always threshold = 0??

    // Partition the data based on the random hyperplane
    Node* leftData = NULL;    
    int DLeft = 0;
    Node* rightData = NULL;
    int DRight = 0;

    // Implement data partitioning based on the hyperplane
    while (data != NULL) {
        double dotProduct = computeProjection(data, treeNode->projection);

        if (dotProduct >= 0) {
            //left tree node
            // printf("the node %d goes left\n", data->nodeNameInt);
            addData(&leftData, data);
            DLeft++;
        } 
        else {
            //right tree node
            // printf("the node %d goes right\n", data->nodeNameInt);
            addData(&rightData, data);
            DRight++;
        }

        data = data ->next;
    }

    treeNode->left = buildRandomProjectionTree(leftData, dimension, DLeft, K);
    treeNode->right = buildRandomProjectionTree(rightData, dimension, DRight, K);

    return treeNode;
}

// Function to search for nearest neighbors in the tree
Node* searchTree(TreeNode* root, Node* node) {
    // TODO: Implement the search for nearest neighbors in the tree
    
    if(root->left == NULL && root->right == NULL){
        // Node* data = root->data;
        // printf("in search\n");
        // while (data != NULL){
        //     printf("- %d\n", data->nodeNameInt);
        //     data = data->next;
        // }
        // printf("---------------------\n");
        return root->data;
    }
    
    double dotProduct = computeProjection(node, root->projection);
    Node* nodesList = NULL;

    if (dotProduct >= 0) {
        //left tree node
        nodesList = searchTree(root->left, node);
    } 
    else {
        //right tree node
        nodesList = searchTree(root->right, node);
    }
    return nodesList;
}

void randomNeighbors(Graph** graph, TreeNode* root, int K, String distance_function) {
    Node* currentNode = (*graph)->nodes;
    int numNodes = (*graph)->numNodes;
    // printf("The Nodes are %d\n", numNodes);

    if(K > numNodes){
        fprintf(stderr, "Too many Neighbors. The Nodes are %d\n", numNodes);
        exit(EXIT_FAILURE);
    }
    
    for(int numNode = 0; numNode < numNodes; numNode++){
        // printf("------- Node %d ------\n", numNode);

        int counter = 0;
        Node* list = searchTree(root, currentNode);
        
        while (list != NULL) {
            // printf("Node = %d \n", list->nodeNameInt);

            if(currentNode->nodeNameInt == list->nodeNameInt) {
                list = list->next;
                continue;
            } 
            
            if (counter == K) {
                // list = list->next;
                break;
            }

            Node* neighborNode = (*graph)->nodes;

            for(int j = 0; j < list->nodeNameInt; j++){
                neighborNode = neighborNode->next;
            }

            double cost = distance(currentNode, neighborNode, distance_function);
            
            addNeighbor(&(currentNode->neighbors), neighborNode, cost);
            addNeighbor(&(neighborNode->reversedNeighbors), currentNode, cost);

            counter++;
            list = list->next;
        }
        if(counter < K){
            //
        }

        currentNode = currentNode->next;
    }
    
    
}

// Function to free the memory allocated for the tree
void freeTree(TreeNode *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root->projection);
        free(root);

        ///TODO also free nodes!!!
    }
}

// int main() {
//     // TODO: Load your dataset and initialize data points

//     int dimension = 10; // Replace with the actual dimensionality of your data
//     int treeDepth = 5;   // Adjust the tree depth based on your requirements

//     // Build the random projection tree
//     TreeNode *root = buildRandomProjectionTree(/* Your data */, dimension, treeDepth);

//     // TODO: Query for nearest neighbors using the searchNeighbors function

//     // Free the allocated memory for the tree
//     freeTree(root);

//     return 0;
// }