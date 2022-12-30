#include <stdio.h>

#include "graph.h"

Node* createNode(int num) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = num;
    node->next = NULL;
    node->dest = NULL;
}

int main() {
    printf("Hello World!\n");
}