#include "include/Graph.h"

Node createNode(const String name) {
    Node node = (Node)malloc(sizeof(Node));
    if(node == NULL)
        return NULL;
    node->name = (String)malloc(strlen(name) + 1);
    if (node->name == NULL) {
        free(node); // Clean up previously allocated memory
        return NULL; // Memory allocation failed
    }
    strcpy(node->name, name);

    node->destinations = NULL;
    return node;
}

void freeNode(Node node) {
    if (node == NULL)
        return;
    free(node->name);
    NodeNeighborsLinkedList current = node->destinations;
    while (current != NULL) {
        NodeNeighborsLinkedList next = current->next;
        free(current);
        current = next;
    }
    free(node);
}

NodeNeighborsLinkedList addDestination(Node node, Node dest, double cost, double time_cost) {
    NodeNeighborsLinkedList newDestination = (NodeNeighborsLinkedList)malloc(sizeof(NodeNeighborsLinkedList));
    if (newDestination == NULL)
        return NULL;
    newDestination->dest = dest;
    newDestination->cost = cost;
    newDestination->time_cost = time_cost;
    newDestination->next = node->destinations;
    node->destinations = newDestination;
    return newDestination;
}

void freeDestination(NodeNeighborsLinkedList destination) {
    if (destination == NULL)
        return;
    freeNode(destination->dest);
    free(destination);
}

Graph createGraph() {
    Graph graph = (Graph)malloc(sizeof(Graph));
    if (graph == NULL)
        return NULL;
    
    graph->nodes = NULL;
    graph->numNodes = 0;
    return graph;
}

// Function to free the entire graph
void freeGraph(Graph graph) {
    if (graph == NULL)
        return;
    for (int i = 0; i < graph->numNodes; i++) {
        freeNode(graph->nodes + i);
    }

    free(graph->nodes);
    free(graph);
}

Graph createGraphFromBinaryFile(const String filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Create an empty graph
    Graph* graph = createGraph();
    if (graph == NULL) {
        fclose(file);
        perror("Error creating graph");
        return NULL;
    }

    // Read and process data from the binary file
    while (!feof(file)) {
        char nodeName[256];
        int numNeighbors;
        double cost, timeCost;

        // Read node name
        if (fread(nodeName, sizeof(nodeName), 1, file) != 1) {
            if (feof(file)) {
                break;
            }
            perror("Error reading node name");
            freeGraph(graph);
            fclose(file);
            return NULL;
        }

        // Create the node
        Node node = createNode(nodeName);
        if (node == NULL) {
            perror("Error creating node");
            freeGraph(graph);
            fclose(file);
            return NULL;
        }

        // Read and add neighbors
        for (int i = 0; i < numNeighbors; i++) {
            if (fread(nodeName, sizeof(nodeName), 1, file) != 1) {
                perror("Error reading neighbor name");
                freeGraph(graph);
                fclose(file);
                return NULL;
            }

        }

        // Add the node to the graph
    }

    fclose(file);
    return graph;
}