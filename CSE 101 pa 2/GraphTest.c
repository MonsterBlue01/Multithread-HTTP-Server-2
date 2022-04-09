#include<stdio.h>
#include<stdlib.h>

#include "List.h"
#include "Graph.h"

int main() {
    Graph G = newGraph(200);
    addArc(G, 100, 200);
    addArc(G, 100, 50);
    addArc(G, 100, 75);
    addArc(G, 100, 25);
    addArc(G, 100, 60);
    addArc(G, 100, 300);
    printGraph(stdout, G);
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