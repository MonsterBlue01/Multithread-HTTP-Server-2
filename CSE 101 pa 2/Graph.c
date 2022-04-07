#include <stdlib.h>
#include <stdio.h>

#include "Graph.h"

/*** Constructors-Destructors ***/
Graph newGraph(int n) {
    Graph new = malloc(sizeof(GraphObj));

    new->color = NULL;
    new->distance = NULL;
    new->neighbor = NULL;
    new->order = 0;
    new->size = 0;
    new->used = NULL;

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
    return G->used;
}

int main() {
    printf("a\n");
}