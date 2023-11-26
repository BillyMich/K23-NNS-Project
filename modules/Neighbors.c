#include "../include/Neighbors.h"

/// @brief Initialazation of a node
/// @param nodeNeighbor 
/// @param cost 
/// @return 
NodeNeighborsLinkedList* initNeighbor(Node* nodeNeighbor, double cost) {
    NodeNeighborsLinkedList* newNeighbor = (NodeNeighborsLinkedList*)malloc(sizeof(NodeNeighborsLinkedList));
    if (newNeighbor == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    newNeighbor->node = nodeNeighbor;
    newNeighbor->cost = cost;
    newNeighbor->flag = 1; // the flag is TRUE
    newNeighbor->next = NULL;

    return newNeighbor;
}

/// @brief This is an add neightbor that adds them in coreect order
/// @param head 
/// @param nodeNeighbor 
/// @param cost 
void addNeighbor(NodeNeighborsLinkedList** head, Node* nodeNeighbor, double cost) {
    NodeNeighborsLinkedList* newNeighbor = initNeighbor(nodeNeighbor, cost);
    if (*head == NULL || cost < (*head)->cost) {
        newNeighbor->next = *head;
        *head = newNeighbor;
    } else {
        NodeNeighborsLinkedList* current = *head;
        while (current->next != NULL && current->next->cost < cost) {
            current = current->next;
        }
        newNeighbor->next = current->next;
        current->next = newNeighbor;
    }
}

/// @brief Deleted last node 
/// @param head 
// void deleteLastNeighborNode(NodeNeighborsLinkedList** head) {
//     NodeNeighborsLinkedList* current = *head;
//     NodeNeighborsLinkedList* previous;

//     if (current == NULL) return;
//     //one neighbor
//     if (current->next ==NULL) {
//         *head = NULL;
//         //free(current);
//         return;
//     }
//     //more than one neighbor
//     while (current->next != NULL) {
//         if (current->next->next == NULL) {
//             previous = current;
//         }
//         current = current->next;        
//     }
//     //free(current->next);
//     current->next=NULL;
// }

// New delete for last node
int deleteLastNeighborNode(NodeNeighborsLinkedList** head) {
    if (*head == NULL) return -1;

    NodeNeighborsLinkedList* current = *head;
    NodeNeighborsLinkedList* previous = NULL;

    // Find the last node and its previous node
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }

    int name = current->node->nodeNameInt;
    
    if (previous == NULL) {
        // There is only one neighbor
        free(*head);
        *head = NULL;

    } else {
        // There is more than one neighbor
        free(previous->next);
        previous->next = NULL;
    }

    return name;
}

void deleteReverseNeighbor(Node** head, int nodeName, int nodeNameReverse) {
    Node* temp = *head;

    while (temp != NULL && temp->nodeNameInt != nodeName) {
        temp = temp->next;
    }

    NodeNeighborsLinkedList** reverseHead = &(temp->reversedNeighbors);
    NodeNeighborsLinkedList* reverseTemp = *reverseHead;
    NodeNeighborsLinkedList* previous = NULL;

    if ((*reverseHead) == NULL) {
        fprintf(stderr, "Delete Reverse Error-NULL Head\n");
        exit(EXIT_FAILURE);
    }

    //nodeNameReverse is in the head of the list
    if ((*reverseHead)->node->nodeNameInt == nodeNameReverse) {
        *reverseHead = (*reverseHead)->next;// Changed head
        free(reverseTemp);
        return;
    }
    
    while (reverseTemp != NULL && reverseTemp->node->nodeNameInt != nodeNameReverse) {
        previous = reverseTemp;
        reverseTemp = reverseTemp->next;
    }

    // If name was not present in linked list
    if (reverseTemp == NULL){
        fprintf(stderr, "Delete Reverse Error-NULL Temp\n");
        exit(EXIT_FAILURE);
    }
    free(previous->next);   
    
}


void freeNeighbors(NodeNeighborsLinkedList* neighbors) {
    
    while (neighbors != NULL) {
        NodeNeighborsLinkedList* next = neighbors->next;
        free(neighbors);
        neighbors = next;
    }
}
