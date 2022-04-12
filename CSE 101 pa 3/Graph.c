#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

#define UNDEF -1
#define NIL 0

// Constructors-Destructors

Graph newGraph(int n) {
    Graph new = malloc(sizeof(GraphObj));

    new->color = malloc((n + 1) * sizeof(int));
    new->discover_time = malloc((n + 1) * sizeof(int));
    new->neighbor = malloc((n + 1) * sizeof(List));
    new->parent = malloc((n + 1) * sizeof(int));
    new->order = n;
    new->size = 0;
    new->finish_time = malloc((n + 1) * sizeof(int));

    return new;
}

void freeGraph(Graph* pG);

// Access functions 

int getOrder(Graph G) {
    return G->order;
}

int getSize(Graph G) {
    return G->order;
}

int getParent(Graph G, int u) {
    return G->parent[u];
}

int getDiscover(Graph G, int u) {
    return G->discover_time[u];
}

int getFinish(Graph G, int u) {
    return G->finish_time[u];
}

// Manipulation procedures
void addArc(Graph G, int u, int v); /* Pre: 1<=u<=n, 1<=v<=n */
void addEdge(Graph G, int u, int v); /* Pre: 1<=u<=n, 1<=v<=n */
void DFS(Graph G, List S); /* Pre: length(S)==getOrder(G) */
// Other Functions
Graph transpose(Graph G);
Graph copyGraph(Graph G);
void printGraph(FILE* out , Graph G);
