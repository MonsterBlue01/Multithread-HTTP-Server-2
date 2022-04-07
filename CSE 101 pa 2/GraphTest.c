#include <stdio.h>

#include "List.h"
#include "Graph.h"

int main() {
    Graph new = newGraph(3);
    if (G->neighbor[1] == NULL) {
        G->neighbor[1] = newList();
    }

    if (G->neighbor[2] == NULL) {
        G->neighbor[2] = newList();
    }

    append(G->neighbor[1], 2);
    append(G->neighbor[2], 1);
    printf("%d\n", new->neighbor[1]->front->data);
}