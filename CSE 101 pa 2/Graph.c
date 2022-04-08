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
    G->order++;
}

void addArc(Graph G, int u, int v) {
    if (G->neighbor[u] == NULL) {
        G->neighbor[u] = newList();
    }

    append(G->neighbor[u], v);
    G->order++;
}

void BFS(Graph G, int s) {
    for x in V(G)-{s}
        color[x] = white
        d[x] = inf
        p[x] = nil 
   color[s] = gray       // discover the source s
   d[s] = 0
   p[s] = nil 
   Q = { }               // construct a new empty queue
   Enqueue(Q,s)
   while Q 鈮� { }
        x = Dequeue(Q) 
        for y in adj[x]
             if color[y] == white         // y is undiscovered
                  color[y] = gray         // discover y
                  d[y] = d[x]+1
                  p[y] = x
                  Enqueue(Q,y)
        color[x] = black                  // finish x
}