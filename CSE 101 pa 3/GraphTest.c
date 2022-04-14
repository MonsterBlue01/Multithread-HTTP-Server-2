#include <stdio.h>

#include "Graph.h"
#include "List.h"

int main() {
    Graph G = newGraph(8);
    addArc(G, 1, 2);
    addArc(G, 1, 5);
    addArc(G, 2, 5);
    addArc(G, 2, 6);
    addArc(G, 3, 2);
    addArc(G, 3, 4);
    addArc(G, 3, 6);
    addArc(G, 3, 7);
    addArc(G, 3, 8);
    addArc(G, 6, 5);
    addArc(G, 6, 7);
    addArc(G, 8, 4);
    addArc(G, 8, 7);
    printGraph(stdout, G);
    // ----------------------------------
    int s = 1;
    for (int i = 1; i < G->order; i++) {
        G->parent[i] = NIL;
        G->color[i] = 0;
    }
    G->color[s] = 1;
    G->parent[s] = NIL;

    List L = newList();
    append(L, s);
    while (L->length != 0) {
        int x = back(L);
        printf("The origin List: ");
        printList(stdout, L);
        printf("\n"); 
        deleteBack(L);
        Node tmp;
        if (G->neighbor[x] == NULL) {
            tmp = NULL;
        } else {
            tmp = G->neighbor[x]->front;
        }
        int a = 0;
        int *time = &a;
        while (tmp != NULL) {
            if (G->color[tmp->data] == 0) {
                G->color[tmp->data] = 1;
                G->discover_time[tmp->data] = ++(*time);
                G->parent[tmp->data] = x;
                append(L, tmp->data);
            }
            tmp = tmp->next;
        }
        G->color[x] = 2;
        G->finish_time[x] = ++(*time);
        printf("The result List: ");
        printList(stdout, L);
        printf("\n");
    }
    printf("----------------------------------\n");
    for (int i = 1; i <= G->order; i++) {
        printf("The discover time of %d is %d.\n", i, G->discover_time[i]);
    }
    // ----------------------------------
    // int time = 0;
    // printf("\n");
    // addArc(G, 1, 2); 
    // addArc(G, 1, 3);
    // addArc(G, 2, 4);
    // addArc(G, 2, 5);
    // addArc(G, 3, 6);
    // addArc(G, 3, 7);
    // addArc(G, 4, 8);
    // addArc(G, 4, 9);
    // addArc(G, 5, 10);
    // addArc(G, 5, 11);
    // addArc(G, 6, 12);
    // addArc(G, 6, 13);
    // addArc(G, 7, 14);
    // addArc(G, 7, 15);
    // printGraph(stdout, G);
    // DFS(G, L);
    // printf("%d\n", G->finish_time[1]);
    // printf("%d\n", G->finish_time[2]);
    // printf("%d\n", G->finish_time[4]);
    // printf("%d\n", G->finish_time[8]);
    // printf("%d\n", G->finish_time[9]);
    // printf("%d\n", G->finish_time[5]);
    // printf("%d\n", G->finish_time[10]);
    // printf("%d\n", G->finish_time[11]);
    // printf("%d\n", G->finish_time[3]);
    // printf("%d\n", G->finish_time[6]);
    // printf("%d\n", G->finish_time[12]);
    // printf("%d\n", G->finish_time[13]);
    // printf("%d\n", G->finish_time[7]);
    // printf("%d\n", G->finish_time[14]);
    // printf("%d\n", G->finish_time[15]);
    //printf("The size: %d\n", G->size);
    //printf("The graph: %d\n", G->order);
    return 0;
}
