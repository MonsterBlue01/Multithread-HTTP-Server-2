#include<stdio.h>
#include<stdlib.h>

#include "List.h"
#include "Graph.h"

int main() {
    Graph G = newGraph(3);
    addArc(G, 1, 2);
    printGraph(stdout, G);
    printf("\n");
    printf("The size: %d\n", G->size);
    //addArc(G, 2, 1);
    //printf("The size: %d\n", G->size);
    addArc(G, 1, 3);
    printGraph(stdout, G);
    printf("The size: %d\n", G->size);
    //addArc(G, 3, 1);
    //printf("The size: %d\n", G->size);

    /*Graph G = newGraph(8);
    addEdge(G, 1, 2);
    addEdge(G, 1, 3);
    addEdge(G, 2, 3);
    addEdge(G, 1, 5);
    addEdge(G, 5, 7);
    addEdge(G, 6, 7);
    addEdge(G, 4, 6);
    addEdge(G, 7, 8);
    BFS(G, 1);
    printf("The source: %d\n", G->source);
    printGraph(stdout, G);

    List L = newList();
    getPath(L, G, 4);

    printList(stdout, L);
    printf("\n");*/

    //printf("G->distance: %d\n", G->distance[1]);
    //printf("G->distance: %d\n", G->distance[2]);
    //printf("G->distance: %d\n", G->distance[3]);
    //printf("G->distance: %d\n", G->distance[4]);
    //printf("G->distance: %d\n", G->distance[5]);
    //printf("G->distance: %d\n", G->distance[6]);
    //printf("G->distance: %d\n", G->distance[7]);
    //printf("G->distance: %d\n", G->distance[8]);

    /*FILE *fp = NULL;
    fp = fopen("output.sh", "w+");
    
    int i, s, max, min, d, n=35;
    List  C = newList(); // central vertices 
    List  P = newList(); // peripheral vertices 
    List  E = newList(); // eccentricities 
    Graph G = NULL;

    Graph G = newGraph(n);
    for (i = 1; i < 3; i++){
        if(i % 7 != 0 ) addEdge(G, i, i+1);
        if(i <= 28) addEdge(G, i, i+7);
    }

    addEdge(G, 9, 31);
    addEdge(G, 17, 13);
    addEdge(G, 14, 33);

    /*for (int i = 1; i < 35; i++) {
        if (G->neighbor[i] != NULL) {
            fprintf(fp, "%d: ", i);
            printList(fp, G->neighbor[i]);
            fprintf(fp, "\n");
        }
    }*/

    //printf("%d\n", G->order);
    /*printGraph(stdout, G);
    BFS(G, 1);*/
    //printf("G->distance[1]: %d\n", G->distance[1]);
    //printf("G->parent[1]: %d\n", G->parent[1]);
    //printf("G->color[1]: %d\n", G->color[1]);
    
    /*printf("Distance of 1 from 1: %d\n", G->distance[1]);
    printf("Distance of 13 from 1: %d\n", G->distance[13]);

    printf("The parent of 1: %d\n", G->parent[1]);
    printf("The parent of 8: %d\n", G->parent[8]);
    printf("The parent of 31: %d\n", G->parent[31]);

    printf("The color of 1: %d\n", G->color[1]);
    printf("The color of 8: %d\n", G->color[8]);

    fclose(fp);*/
}