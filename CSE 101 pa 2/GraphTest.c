#include <stdio.h>

#include "List.h"
#include "Graph.h"

int main() {
    Graph new = newGraph(3);
    /*if (new->neighbor[1] == NULL) {
        new->neighbor[1] = newList();
    }

    if (new->neighbor[2] == NULL) {
        new->neighbor[2] = newList();
    }

    append(new->neighbor[1], 2);
    append(new->neighbor[2], 1);*/
    addEdge(new, 1, 2);
    printf("%d\n", new->neighbor[1]->front->data);
}