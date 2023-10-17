
typedef void* Pointer;
typedef struct graph* Graph;
typedef struct graphLinkedList;

typedef struct graph {
    char* name;
    GraphLinkedList* destinations;
} * Graph;

typedef struct graphLinkedList {
    Graph* dest;
    double cost;
    // recall type var;
    graphLinkedList* next;
} * GraphLinkedList;


