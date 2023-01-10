#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "graph.h"

void initializeGraph(Graph **g, char* filename) {
    *g = (Graph*)malloc(sizeof(Graph));
    int x, y;
    (*g)->numEdges = 0, (*g)->numVertices = 0;
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }
    while (fscanf(fp, "%d%d", &x, &y) == 2) {
        printf("%d %d\n", x, y);
        (*g)->numVertices = fmax(fmax(x, y), (*g)->numVertices);
        if (x != y) {
            (*g)->numEdges++;
        }
    }
    fclose(fp);
}

void initializeAdjacencyMatrix(Graph *g, char* filename) {
    g->adjacencyMatrix = (int**)malloc(g->numVertices * sizeof(int*));
    for (int i = 0; i < g->numVertices; i++) {
        g->adjacencyMatrix[i] = (int*)malloc(g->numVertices * sizeof(int));
    }
    for (int i = 0; i < g->numVertices; i++) {
        for (int j = 0; j < g->numVertices; j++) {
            g->adjacencyMatrix[i][j] = 0;
        }
    }
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }
    int x, y;
    while (fscanf(fp, "%d%d", &x, &y) == 2) {
        printf("%d %d\n", x, y);
        if (x != y) {
            g->adjacencyMatrix[x-1][y-1] = 1;
            if (x != y) {
                g->adjacencyMatrix[y-1][x-1] = 1;
            }
        }
    }
    fclose(fp);
}

void deleteGraph(Graph *g) {
    for (int i = 0; i < g->numVertices; i++) {
        free(g->adjacencyMatrix[i]);
    }
    free(g->adjacencyMatrix);
    free(g);
}

void printMatrix(Graph *g) {
    for (int i = 0; i < g->numVertices; i++) {
        for (int j = 0; j < g->numVertices; j++) {
            if (i != j) {
                printf("%d ", g->adjacencyMatrix[i][j]);
            } else {
                printf("x ");
            }
        }
        printf("\n");
    }
}

LLNode* createNode(int value) {
    LLNode* node = (LLNode*)malloc(sizeof(LLNode));
    node->value = value;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void appendNode(LLNode* head, int value) {
    LLNode* node = createNode(value);
    LLNode* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = node;
    node->prev = current;
}

LLNode* deleteNode(LLNode* head) {
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    LLNode* current = head;
    while (current->prev != NULL) {
        current = current->prev;
    }
    LLNode* res = current->next;
    res->prev = NULL;
    free(current);
    return res;
}

void cleanList(LLNode* head) {
    LLNode* current = head;
    while (current->prev != NULL) {
        current = current->prev;
    }
    while (current != NULL) {
        LLNode* next = current->next;
        free(current);
        current = next;
    }
}

void printList(LLNode* head) {
    LLNode* current = head;
    while (current->prev != NULL) {
        current = current->prev;
    }
    while (current != NULL) {
        printf("%d", current->value);
        current = current->next;
        if (current != NULL) {
            printf("->");
        }
    }
    printf("\n");
}

int main() {
    Graph *g = NULL;
    initializeGraph(&g, "node.txt");
    printf("Number of vertices: %d\n", g->numVertices);
    printf("Number of edges: %d\n", g->numEdges);
    initializeAdjacencyMatrix(g, "node.txt");
    LLNode* head = createNode(1);
    printList(head);
    appendNode(head, 2);
    appendNode(head, 3);
    head = deleteNode(head);
    printList(head);
    cleanList(head);
    printMatrix(g);
    deleteGraph(g);
    return 0;
}
