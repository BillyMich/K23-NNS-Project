
#include "../include/Graph.h"
#include "../include/Node.h"
#include "../include/MathematicalFunctions.h"
#include "../include/Neighbors.h"
#include "../include/FindAllRightNeighborsAlgorithm.h"


void FindAllRightNeighbors(Graph * graph, String distance_function,int neighbors)
{
    Node *headNode = graph->nodes;
    Node *tempNode = graph->nodes;
    Node *tempNodeFor = graph->nodes;
    int flag = 0;
    while (tempNode !=NULL)
    {
        if (tempNode->nodeNameInt != tempNodeFor->nodeNameInt)
        {
            OrderNodesByNeighbor(tempNode,tempNodeFor, distance_function);
            flag++;
            if (flag>neighbors)
            {
            deleteLastNeighborNode(&tempNode->neighbors);
            }            
        }
    

        if (tempNodeFor->next !=NULL)
        {
            tempNodeFor=tempNodeFor->next;
        }else if (tempNodeFor->next ==NULL)
        {
            tempNodeFor = headNode;
            if (tempNode->next!=NULL)
            {
                flag = 0;
                tempNode = tempNode->next;
            }else
            break;    
        }   
    }

    
}


void OrderNodesByNeighbor(Node *dest , Node *src, String distance_function){
    addNeighbor(&dest->neighbors,src, distance(dest->dimension,src->dimension, distance_function));}    //Here or in the addNeigbor i would like to add a sorting method base on distance
}
