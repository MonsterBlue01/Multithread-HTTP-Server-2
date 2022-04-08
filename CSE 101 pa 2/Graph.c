#include <stdlib.h>
#include <stdio.h>

#include "Graph.h"
#include "List.h"

/*** Constructors-Destructors ***/
Graph newGraph(int n) {
    Graph new = malloc(sizeof(GraphObj));

    new->color = NULL;
    new->distance = NULL;
    new->neighbor = malloc(n * sizeof(List));
    new->parent = NULL;
    new->order = n;
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

int getParent(Graph G, int u) {
    return G->parent[u];
}

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

void BFS(Graph G, int s) {
    for (int i = 1; i < G->order; i++) {
        G->distance[i] = INF;
        G->parent[i] = NIL;
    }
    (void)s;
}

/*** Other operations ***/
void printGraph(FILE* out, Graph G) {
    for (int i = 1; i < G->order; i++) {
        if (G->neighbor[i] != NULL) {
            fprintf(out, "%d: ", i);
            printList(out, G->neighbor[i]);
            fprintf(out, "\n");
        }
    }
}