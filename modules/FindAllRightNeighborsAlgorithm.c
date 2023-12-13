
#include "../include/Graph.h"
#include "../include/Node.h"
#include "../include/MathematicalFunctions.h"
#include "../include/Neighbors.h"
#include "../include/FindAllRightNeighborsAlgorithm.h"


void FindAllRightNeighbors(Graph * graph, String distance_function)
{
    Node *headNode = graph->nodes;
    Node *tempNode = graph->nodes;
    Node *tempNodeFor = graph->nodes;

    while (tempNode !=NULL)
    {
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

    
}


void OrderNodesByNeighbor(Node *dest , Node *src, String distance_function){
    addNeighbor(&dest->neighbors,src, distance(dest, src, distance_function));
    //Here or in the addNeigbor i would like to add a sorting method base on distance
}