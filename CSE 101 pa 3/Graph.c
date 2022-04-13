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

void addEdge(Graph G, int u, int v) {
    if ((u < 1) && (u > G->order)) {
        printf("Graph Error: calling addEdge() with invalid parameters.\n");
        exit(1);
    }

    int actedu = 0;
    int actedv = 0;

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
                    actedu = 1;
                    break;
                } else {
                    moveNext(G->neighbor[u]);
                }
            }
            if (actedu == 0) {
                insertBefore(G->neighbor[u], v);
            }
        }
    }

    if (G->neighbor[v] == NULL) {
        G->neighbor[v] = newList();
    }

    if (G->neighbor[v]->front == NULL) {
        append(G->neighbor[v], u);
    } else {
        moveFront(G->neighbor[v]);
        if (u < G->neighbor[v]->cursor->data) {
            prepend(G->neighbor[v], u);
        } else {
            while (G->neighbor[v]->cursor->data < u) {
                if (G->neighbor[v]->cursor == G->neighbor[v]->back) {
                    append(G->neighbor[v], u);
                    actedv = 1;
                    break;
                } else {
                    moveNext(G->neighbor[v]);
                }
            }
            if (actedv == 0) {
                insertBefore(G->neighbor[v], u);
            }
        }
    }
    G->size++;
}

void DFS(Graph G, List S) {
    for (int i = 1; i <= G->order; i++) {
        G->color[i] = 0;
        G->parent[i] = NIL;
    }
    int time = 0;
    for (int i = 1; i <= G->order; i++) {
        if (G->color[i] == 0) {
            visit(i, time, G);
        }
    }
}

void visit(Graph G, int x) {
    G->color[x] = 1;
    Node N;
    if (G->neighbor[x] == NULL) {
        N = NULL;
    } else {
        N = G->neighbor[x]->front;
    }
    while (N != NULL) {
        printf("The data: %d\n", N->data);
        N = N->next;
    }
}

// Other Functions

Graph transpose(Graph G);
Graph copyGraph(Graph G);

void printGraph(FILE* out, Graph G) {
    for (int i = 1; i <= G->order; i++) {
        if (G->neighbor[i] != NULL) {
            fprintf(out, "%d: ", i);
            printList(out, G->neighbor[i]);
            if (i < G->order) {
                fprintf(out, "\n");
            }
        } else {
            fprintf(out, "%d: ", i);
            fprintf(out, "\n");
        }
    }
}
