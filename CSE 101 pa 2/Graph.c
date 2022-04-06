#include <stdlib.h>
#include <stdio.h>

#include "Graph.h"

/*** Constructors-Destructors ***/
Graph newGraph(int n) {
    Graph new = malloc(sizeof(GraphObj));

    new->color = NULL;
    new->distance = NULL;
    new->neighbor = NULL;
    new->NoE = 0;
    new->NoV = 0;
    new->used = NULL;

    return new;
}

int main() {
    printf("a\n");
}