#include <stdio.h>

#include "Graph.h"
#include "List.h"

int main() {
    Graph A = newGraph(100);
    List L = newList();
    if (getSize(A) != 0) {
        printf("%d\n", getSize(A));
    }
    addArc(A, 54, 1);
    addArc(A, 54, 2);
    addArc(A, 54, 2);
    addArc(A, 54, 3);
    addArc(A, 1, 54);
    addArc(A, 1, 54);
    addArc(A, 1, 55);
    addArc(A, 1, 55);
    if (getSize(A) != 5) {
        printf("2\n");
    }
    for (int i = 1; i <= 100; i++) {
        append(L, i);
    }

    DFS(A, L);
    // if (getSize(A) != 5) {
    //     printf("3\n");
    // }
    // printf("a\n");
    // addArc(A, 55, 1);
    // if (getSize(A) != 6)
    //   return 4;
    // return 0;
    // prepend(L, 1);
    // prepend(L, 2);
    // prepend(L, 3);
    // prepend(L, 4);
    // prepend(L, 5);
    // prepend(L, 6);
    // prepend(L, 7);
    // prepend(L, 8);
    // addArc(G, 1, 2);
    // addArc(G, 2, 5);
    // addArc(G, 2, 3);
    // addArc(G, 2, 6);
    // addArc(G, 3, 4);
    // addArc(G, 3, 7);
    // addArc(G, 4, 3);
    // addArc(G, 4, 8);
    // addArc(G, 5, 1);
    // addArc(G, 5, 6);
    // addArc(G, 6, 7);
    // addArc(G, 7, 6);
    // addArc(G, 7, 8);
    // addArc(G, 8, 8);
    // Graph Gt = transpose(G);
    // printList(stdout, L);
    // printf("\n");
    // DFS(G, L);
    // printList(stdout, L);
    // printf("\n");
    // DFS(Gt, L);
    // printList(stdout, L);
    // printf("\n");
    // printGraph(stdout, Gt);
    // printGraph(stdout, G);
    // printf("\n");
    // DFS(G, L);
    // for (int i = 1; i <= G->order; i++) {
    //     printf("The d: %d\n", G->discover_time[i]);
    // }
    // printList(stdout, L);
    // printf("\n");
    // // ----------------------------------
    // Graph Gt = newGraph(8);
    // List Lt = newList();
    // addArc(Gt, 5, 1);
    // addArc(Gt, 1, 2);
    // addArc(Gt, 2, 5);
    // addArc(Gt, 2, 3);
    // addArc(Gt, 4, 3);
    // addArc(Gt, 3, 7);
    // addArc(Gt, 6, 7);
    // addArc(Gt, 2, 6);
    // addArc(Gt, 5, 6);
    // addArc(Gt, 7, 6);
    // addArc(Gt, 3, 4);
    // addArc(Gt, 4, 8);
    // addArc(Gt, 7, 8);
    // addArc(Gt, 8, 8);
    // printGraph(stdout, Gt);
    // printf("\n");
    // DFS(Gt, Lt);
    // for (int i = 1; i <= Gt->order; i++) {
    //     printf("The d: %d\n", Gt->discover_time[i]);
    // }
    // printList(stdout, Lt);
    // printf("\n");

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
