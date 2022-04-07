#include <stdlib.h>
#include <stdio.h>

#include "Graph.h"
#include "List.h"

/*** Constructors-Destructors ***/
Graph newGraph(int n) {
    Graph new = malloc(sizeof(GraphObj));

    new->color = NULL;
    new->distance = NULL;
    new->neighbor = malloc(sizeof(List));
    new->parent = NULL;
    new->order = 0;
    new->size = 0;
    new->source = 0;

    return new;
}

/*** Access functions ***/
int getOrder(Graph G) {
    return G->order;
}

int getSize(Graph G) {
    return G->size;
}

int getSource(Graph G) {
    return G->source;
}

int getParent(Graph G, int u);

/*** Manipulation procedures ***/
void makeNull(Graph G);

void addEdge(Graph G, int u, int v) {
    if (G->neighbor[u] == NULL) {
        G->neighbor[u] = newList();
    }

    if (G->neighbor[v] == NULL) {
        G->neighbor[v] = newList();
    }

    append(G->neighbor[u], v);
    append(G->neighbor[v], u);
}

void addArc(Graph G, int u, int v) {
    if (G->neighbor[u] == NULL) {
        G->neighbor[u] = newList();
    }

    append(G->neighbor[u], v);
}

void addArc(Graph G, int u, int v);
void BFS(Graph G, int s);