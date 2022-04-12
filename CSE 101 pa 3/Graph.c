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

void addArc(Graph G, int u, int v) {
    if ((u < 1) && (u > G->order)) {
        printf("Graph Error: calling addArc() with invalid parameters.\n");
        exit(1);
    }

    int acted = 0;

    if (G->neighbor[u] == NULL) {
        G->neighbor[u] = newList();
    }

    if (G->neighbor[u]->front == NULL) {
        append(G->neighbor[u], v);
    } else {
        moveFront(G->neighbor[u]);
        if (v < G->neighbor[u]->cursor->data) {
            prepend(G->neighbor[u], v);
        } else {
            while (G->neighbor[u]->cursor->data < v) {
                if (G->neighbor[u]->cursor == G->neighbor[u]->back) {
                    append(G->neighbor[u], v);
                    acted = 1;
                    break;
                } else {
                    moveNext(G->neighbor[u]);
                }
            }
            if (acted == 0) {
                insertBefore(G->neighbor[u], v);
            }
        }
    }
    G->size++;
}

void addEdge(Graph G, int u, int v); /* Pre: 1<=u<=n, 1<=v<=n */
void DFS(Graph G, List S); /* Pre: length(S)==getOrder(G) */
// Other Functions
Graph transpose(Graph G);
Graph copyGraph(Graph G);
void printGraph(FILE* out , Graph G);
