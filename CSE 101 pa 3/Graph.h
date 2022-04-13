#include "List.h"

typedef struct GraphObj* Graph;

typedef struct GraphObj{
    List* neighbor;
    int* color;                         //0: white, 1: gray, 2: black
    int* parent;
    int* discover_time;
    int* finish_time;
    int order;
    int size;
} GraphObj;

// Constructors-Destructors

Graph newGraph(int n);
void freeGraph(Graph* pG);

// Access functions 
int getOrder(Graph G);
int getSize(Graph G);
int getParent(Graph G, int u); /* Pre: 1<=u<=n=getOrder(G) */
int getDiscover(Graph G, int u); /* Pre: 1<=u<=n=getOrder(G) */
int getFinish(Graph G, int u); /* Pre: 1<=u<=n=getOrder(G) */
// Manipulation procedures
void addArc(Graph G, int u, int v); /* Pre: 1<=u<=n, 1<=v<=n */
void addEdge(Graph G, int u, int v); /* Pre: 1<=u<=n, 1<=v<=n */
void DFS(Graph G, List S); /* Pre: length(S)==getOrder(G) */
void visit(Graph G, int x, int time);
// Other Functions
Graph transpose(Graph G);
Graph copyGraph(Graph G);
void printGraph(FILE* out , Graph G);
