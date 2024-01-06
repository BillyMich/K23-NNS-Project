#include "../include/Graph.h"


Graph* initGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    if (graph == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    graph->nodes = NULL;
    graph->numNodes = 0;
    return graph;
}

// Function to free the entire graph
void freeGraph(Graph* graph) {
    if (graph == NULL) return;
    
    Node* current = graph->nodes;
    while (current != NULL) {
        Node* next = current->next;
        freeNode(current);
        current = next;
    }
    free(graph);
}

/// @brief This function creates a graph from given
/// inputs
/// @param filename 
/// @param dimensions 
/// @return 
Graph* createGraphFromBinaryFile(String filename, int dimensions) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Create an empty graph
    Graph* graph = initGraph();
    if (graph == NULL) {
        fclose(file);
        perror("Error creating graph");
        return NULL;
    }

    double coordinate;
    Node** headNode = &graph->nodes; 
    int flag = 0; // Flag for feof  

    Dimension* headDimension = NULL;

    // Read and process data from the binary file
    while (!feof(file)) {
        
        headDimension = NULL;

        for (int i = 0; i < dimensions; i++){
            fread(&coordinate, sizeof(double), 1, file); // Read one double at a time
            if(feof(file)){
                flag = 1;
                break;
            }
            addDimension(&headDimension, i, coordinate);
        }

        if(flag == 0) {
            addNode(headNode, headDimension);
            graph->numNodes++;
        }
    }

    freeDimensions(headDimension);

    fclose(file);
    return graph;
}

/// @brief  Function to find the accuration result of the KNS algorithm
/// @param graph 
/// @param graphRightResults 
/// @return 
double findAccurationResultSuperAccurate(Graph* graph , Graph* graphRightResults){

    Node * tempNodeKNS = graph->nodes;
    Node * tempNodeRight = graphRightResults->nodes;
    double count = 0 ;
    double correct = 0;

    while (tempNodeKNS != NULL && tempNodeRight!= NULL  )
    {    
        NodeNeighborsLinkedList * tempNodeListKNS = tempNodeKNS->neighbors; 
        NodeNeighborsLinkedList * tempNodeListRight = tempNodeRight->neighbors;

        while (tempNodeListKNS != NULL && tempNodeListRight != NULL )
        {
            count++;
            if (tempNodeListKNS->node->nodeNameInt == tempNodeListRight->node->nodeNameInt) correct++;
            tempNodeListKNS = tempNodeListKNS->next;
            tempNodeListRight = tempNodeListRight->next;
        }
        
        tempNodeKNS = tempNodeKNS->next;
        tempNodeRight = tempNodeRight->next;
    }
    
    return  (correct / count )* 100;
}


/// @brief  Function to find the accuration result of the KNS algorithm
/// @param graph 
/// @param graphRightResults 
/// @return 
double findAccurationResult(Graph* graph , Graph* graphRightResults, int neighbors){

    Node * tempNodeKNS = graph->nodes;
    Node * tempNodeRight = graphRightResults->nodes;
    double count = 0 ;
    double correct = 0;
    int checked = 0;

    while (tempNodeKNS != NULL)
    {
        
        NodeNeighborsLinkedList * tempNodeListKNS = tempNodeKNS->neighbors; 
        NodeNeighborsLinkedList * tempNodeListRight = tempNodeRight->neighbors;

        while (tempNodeListKNS !=NULL)
        {
            count++;

            for (int  i = 0; i < neighbors; i++)
            {
                if (tempNodeListKNS->node->nodeNameInt == tempNodeListRight->node->nodeNameInt)
                {   
                    correct++;
                    break;
                }
                tempNodeListRight = tempNodeListRight->next;            
            }
            tempNodeListRight = tempNodeRight->neighbors;;
            tempNodeListKNS = tempNodeListKNS->next;
        }

        tempNodeRight = tempNodeRight->next;
        tempNodeKNS = tempNodeKNS->next;
        printf("%d",++checked);
    }
        return  (correct / count )* 100;
}

// Function to write the graph data to a file
void writeGraphToFile(Graph* graph, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
    printf("Error opening file: %s\n", filename);
    perror("Error");
    return;
    }

    Node* currentNode = graph->nodes;
    while (currentNode != NULL) {
        fprintf(file, "Node: %d\n", currentNode->nodeNameInt);

        NodeNeighborsLinkedList* currentNeighbor = currentNode->neighbors;
        while (currentNeighbor != NULL) {
            fprintf(file, "Neighbor: %d\n", currentNeighbor->node->nodeNameInt);
            currentNeighbor = currentNeighbor->next;
        }

        fprintf(file, "\n");
        currentNode = currentNode->next;
    }

    fclose(file);
}