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
TreeNode*   buildRandomProjectionTree(Node* data, int dimension, int D, int numNodes) {
    if (numNodes <= D) {
        // Create a leaf node
        TreeNode* leaf = (TreeNode*)malloc(sizeof(TreeNode));
        leaf->projection = NULL;
        leaf->left = NULL;
        leaf->right = NULL;
        leaf->data = NULL;

        // leaf->data = data;
        while (data != NULL) {
            addData(&(leaf->data), data);
            data = data->next;
        }
        return leaf;
    }

    // Create a non-leaf node
    TreeNode* treeNode = (TreeNode*)malloc(sizeof(TreeNode));
    treeNode->data = NULL;
    treeNode->projection = generateRandomProjection(dimension);

    // Partition the data based on the random hyperplane
    Node* leftData = NULL;    
    int nodesLeft = 0;
    Node* rightData = NULL;
    int nodesRight = 0;

    // Implement data partitioning based on the hyperplane
    while (data != NULL) {
        double dotProduct = computeProjection(data, treeNode->projection);

        if (dotProduct >= 0) {
            //left tree node
            addData(&leftData, data);
            nodesLeft++;
        } 
        else {
            //right tree node
            addData(&rightData, data);
            nodesRight++;
        }

        data = data ->next;
    }
    
    treeNode->left = buildRandomProjectionTree(leftData, dimension, D, nodesLeft);
    treeNode->right = buildRandomProjectionTree(rightData, dimension, D, nodesRight);

    // free left data
    while (leftData != NULL) {
        Node* temp_leftData = leftData;
        leftData = leftData->next;
        free(temp_leftData);
    }
    // free right data
    while (rightData != NULL) {
        Node* temp_rightData = rightData;
        rightData = rightData->next;
        free(temp_rightData);
    }

    return treeNode;
}

// Function to search for nearest neighbors in the tree
Node* searchTree(TreeNode* root, Node* node) {    
    if(root->left == NULL && root->right == NULL){
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

    if(K > numNodes){
        fprintf(stderr, "Too many Neighbors. The Nodes are %d\n", numNodes);
        exit(EXIT_FAILURE);
    }
    
    for(int numNode = 0; numNode < numNodes; numNode++){

        int counter = 0;
        Node* list = searchTree(root, currentNode);
        
        int usedNumbers[K];

        while (list != NULL) {

            if(currentNode->nodeNameInt == list->nodeNameInt) {
                list = list->next;
                continue;
            } 
            
            if (counter == K) {
                break;
            }

            Node* neighborNode = (*graph)->nodes;

            for(int j = 0; j < list->nodeNameInt; j++){
                neighborNode = neighborNode->next;
            }

            double cost = distance(currentNode, neighborNode, distance_function);
            
            addNeighbor(&(currentNode->neighbors), neighborNode, cost);
            addNeighbor(&(neighborNode->reversedNeighbors), currentNode, cost);

            usedNumbers[counter] = neighborNode->nodeNameInt;

            counter++;
            list = list->next;
        }
        
        if(counter < K){
            int remainigNumbers = K - counter;

            remainingRandomNodes(graph, currentNode, usedNumbers, remainigNumbers, K, distance_function);
        }

        currentNode = currentNode->next;
    }
     
}

void remainingRandomNodes(Graph** graph, Node* currentNode, int* usedNumbers, int remainingNodes, int K, String distance_function) {

    int numNodes = (*graph)->numNodes;

    for (int i = K-remainingNodes ; i < K; i++) {

        int randomNumber;
        do {
            randomNumber = rand() % numNodes; 

        } while (isNumberUsed(usedNumbers, i, randomNumber, currentNode->nodeNameInt));   // Check if the number has been used before
        usedNumbers[i] = randomNumber;

        Node* neighborNode = (*graph)->nodes;

        for(int j = 0; j < randomNumber; j++){
            neighborNode = neighborNode->next;
        }

        double cost = distance(currentNode, neighborNode, distance_function);
        
        addNeighbor(&(currentNode->neighbors), neighborNode, cost);
        addNeighbor(&(neighborNode->reversedNeighbors), currentNode, cost);
    }
    currentNode = currentNode->next;
}

// Function to free the memory allocated for the tree
void freeTree(TreeNode *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);

        if (root->projection != NULL)
            free(root->projection);

        //free data at leaves
        if (root->left == NULL && root->right == NULL) {
            while (root->data != NULL) {
                Node* temp_Data = root->data;
                root->data = root->data->next;
                free(temp_Data);
            }

        }

        free(root);
    }
}


// void freeNodeProj(Node* node) {
//     while (node != NULL) {
//         Node* temp = node;
//         node = node->next;
        
//         // Free the memory associated with the dimension linked list
//         // freeDimensionProj(temp->dimension);

//         // Free any other memory associated with the node (e.g., cost, neighbors, etc.)
//         // Add additional free calls if needed
        
//         free(temp);
//     }
// }

// void freeDimensionProj(Dimension* dimension) {
//     while (dimension != NULL) {
//         Dimension* temp = dimension;
//         dimension = dimension->next;
//         free(temp);
//     }
// }
