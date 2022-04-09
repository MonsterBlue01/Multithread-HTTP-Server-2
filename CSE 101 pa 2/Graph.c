#include <stdlib.h>
#include <stdio.h>

#include "Graph.h"
#include "List.h"

/*** Constructors-Destructors ***/
Graph newGraph(int n) {
    Graph new = malloc(sizeof(GraphObj));

    new->color = malloc((n + 1) * sizeof(int));
    new->distance = malloc((n + 1) * sizeof(int));
    new->neighbor = malloc((n + 1) * sizeof(List));
    new->parent = malloc((n + 1) * sizeof(int));
    new->order = n;
    new->size = 0;
    new->source = 0;

    return new;
}

void freeGraph(Graph* pG) {
    free(*pG);
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

int getDist(Graph G, int u) {
    return G->distance[u];
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

    moveFront(G->neighbor[v]);
    while (index(G->neighbor[v]) >= 0) {
        printf("data: %d\n", G->neighbor[v]->cursor->data);
        printf("end\n");
        moveNext(G->neighbor[v]);
    }
    if (G->neighbor[v]->front == NULL) {
        append(G->neighbor[v], u);
    } else if (u < G->neighbor[v]->front->data) {
        prepend(G->neighbor[v], u);
    } else {
        append(G->neighbor[v], u);
    }

    moveFront(G->neighbor[u]);
    while (G->neighbor[u]->index > 0) {
        printf("data: %d\n", G->neighbor[u]->cursor->data);
        moveNext(G->neighbor[u]);
    }
    if (G->neighbor[u]->front == NULL) {
        append(G->neighbor[u], v);
    } else if (v < G->neighbor[u]->front->data) {
        prepend(G->neighbor[u], v);
    } else {
        append(G->neighbor[u], v);
    }
}

void addArc(Graph G, int u, int v) {
    if (G->neighbor[u] == NULL) {
        G->neighbor[u] = newList();
    }

    if (G->neighbor[u]->front == NULL) {
        append(G->neighbor[u], v);
        printf("It's NULL!\n");
    } else {
        moveFront(G->neighbor[u]);
        if (v < G->neighbor[u]->cursor->data) {
            prepend(G->neighbor[u], v);
        } else {
            while (G->neighbor[u]->cursor->data < v) {
                printf("Got it\n");
                if (G->neighbor[u]->cursor == G->neighbor[u]->back) {
                    append(G->neighbor[u], v);
                    break;
                } else {
                    moveNext(G->neighbor[u]);
                }
            }
            insertAfter(G->neighbor[u], v);
        }
    }
    printList(stdout, G->neighbor[u]);
    printf("\n");
}

void BFS(Graph G, int s) {
    for (int i = 1; i < G->order; i++) {
        G->distance[i] = INF;
        G->parent[i] = NIL;
        G->color[i] = 0;
    }
    G->color[s] = 1;
    G->distance[s] = 0;
    G->parent[s] = NIL;

    List L = newList();
    append(L, s);
    while (L->length != 0) {
        int x = front(L);
        //printf("The origin List: ");
        //printList(stdout, L);
        //printf("\n"); 
        deleteFront(L);
        Node tmp = G->neighbor[x]->front;
        while (tmp != NULL) {
            if (G->color[tmp->data] == 0) {
                G->color[tmp->data] = 1;
                G->distance[tmp->data] = G->distance[x] + 1;
                G->parent[tmp->data] = x;
                append(L, tmp->data);
            }
            tmp = tmp->next;
        }
        G->color[x] = 2;
        //printf("The result List: ");
        //printList(stdout, L);
        //printf("\n");
    }
}

/*** Other operations ***/
void printGraph(FILE* out, Graph G) {
    for (int i = 1; i <= G->order; i++) {
        if (G->neighbor[i] != NULL) {
            fprintf(out, "%d: ", i);
            printList(out, G->neighbor[i]);
            fprintf(out, "\n");
        }
    }
}