#include <stdio.h>
#include <stdlib.h>

#include "List.h"
#include "Graph.h"

int main(int argc, char **argv) {
    // if (argc != 3) {
    //     fprintf(stderr, "Main function Error: Fewer or more than two arguments were passed in.\n");
    //     exit(1);
    // }
    FILE *fp = NULL;
    FILE *fp1 = NULL;
    fp = fopen("input1.sh", "r");
    fp1 = fopen("output1.sh", "w+");
    if ((fp == NULL) || (fp1 == NULL)) {
        fprintf(stderr, "File Error: invalid files input!\n");
        exit(1);
    }
    int a, b;
    int num;
    int snum = 0;
    int in = 0;

    fscanf(fp, "%d", &num);
    Graph G = newGraph(num);
    List L = newList();

    for (int i = 1; i <= G->order; i++) {
        printf("data: %d\n", i);
        prepend(L, i);
    }
    
    while (fscanf(fp, "%d", &a) != EOF) {
        fscanf(fp, "%d", &b);
        addArc(G, a, b);
    }
    Graph Gt = transpose(G);
    DFS(G, L);
    DFS(Gt, L);
    
    fprintf(fp1, "Adjacency list representation of G:\n");
    printGraph(fp1, G);
    fprintf(fp1, "\n");

    for (int i = 1; i <= Gt->order; i++) {
        if (Gt->parent[i] == 0) {
            snum++;
        }
    }
    int array[snum];
    printf("The number: %d\n", snum);

    // for (int i = 1; i <= G->order; i++) {
    //     if (Gt->parent[i] == 0) {
    //         array[in++] = i;
    //     }
    // }

    // fprintf(fp1, "\nG contains %d strongly connected components:", snum);
    // int m = 0;
    // int n = 0;

    // while (m != snum) {
    //     while (true) {
    //         moveBack(L);
    //         while (L->cursor->data != array[m]) {
    //             movePrev(L);
    //         }
    //         fprintf(fp1, "\nComponent %d: ", ++n);
    //         while (index(L) >= 0) {
    //             fprintf(fp1, "%d ", L->cursor->data);
    //             movePrev(L);
    //             if (m != 0) {
    //                 if (L->cursor->data == array[m - 1]) {
    //                     break;
    //                 }
    //             }
    //         }
    //         break;
    //     }
    //     m++;
    // }
    fclose(fp);
    fclose(fp1);
}