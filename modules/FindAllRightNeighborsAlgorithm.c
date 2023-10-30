
#include "../include/Graph.h"
#include "../include/Node.h"
#include "../include/MathematicalFunctions.h"
#include "../include/Neighbors.h"
#include "../include/FindAllRightNeighborsAlgorithm.h"



void FindAllRightNeighbors(Graph * graph)
{
    Node *headNode = graph->nodes;
    Node *tempNode = graph->nodes;
    //Find better way to call thos 
    Node *tempNodeFor = graph->nodes;

    int i = 0;
    while (tempNode !=NULL)
    {
        printf("%d\n",i++);
        //Here we find the cost of the 2 nodes (how close is the neightbor)
        OrderNodesByNeighbor(tempNode,tempNodeFor);

        //Here is a simple way to skip and break


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


void OrderNodesByNeighbor(Node *dest , Node *src){
    addNeighbor(&dest->neighbors,src,euclidean_distance(&dest->dimension,&src->dimension),0.0);
    //Here or in the addNeigbor i would like to add a sorting method base on distance
}