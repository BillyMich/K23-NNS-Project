
typedef void* Pointer;

typedef struct Node;
typedef struct NodeNeighborsLinkedList;

typedef struct Node {
    char* name;
    
    NodeNeighborsLinkedList* destinations;
} * Node;

typedef struct NodeNeighborsLinkedList {
   Node* dest;
    double cost;
    double time_cost;
    graphLinkedList* next;
} * NodeNeighborsLinkedList;


//We need to think a way to chouse 2D or 3D
//depending on the given graph 

typedef struct Destinations2D {
    decimanl x;
    decimanl y;
}*   Destinations2D

typedef struct Destinations3D {
    decimanl x;
    decimanl y;
    decimanl z;
}*   Destinations3D
