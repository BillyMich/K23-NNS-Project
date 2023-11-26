
#include "../include/Graph.h"
#include "../include/Node.h"
#include "../include/MathematicalFunctions.h"
#include "../include/Neighbors.h"
#include "../include/FindAllRightNeighborsAlgorithm.h"


void FindAllRightNeighbors(Graph * graph, String distance_function)
{
    Node *headNode = graph->nodes;
    Node *tempNode = graph->nodes;
    //Find better way to call thos 
    Node *tempNodeFor = graph->nodes;

    // int i = 0;
    while (tempNode !=NULL)
    {
        // printf("%d\n",i++);
        //Here we find the cost of the 2 nodes (how close is the neightbor)
        if (tempNode->nodeNameInt != tempNodeFor->nodeNameInt)
        {
            OrderNodesByNeighbor(tempNode,tempNodeFor, distance_function);
        }
    

        if (tempNodeFor->next !=NULL)
        {
            tempNodeFor=tempNodeFor->next;
        }else if (tempNodeFor->next ==NULL)
        {
            tempNodeFor = headNode;
            if (tempNode->next!=NULL)
            {
                tempNode = tempNode->next;
            }else break;    
        }   
    }

    //need to implement!;
    //writeNeightborsInAFile()
    
}


void OrderNodesByNeighbor(Node *dest , Node *src, String distance_function){
    addNeighbor(&dest->neighbors,src, distance(dest->dimension,src->dimension, distance_function));
    //Here or in the addNeigbor i would like to add a sorting method base on distance
}