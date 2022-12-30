#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

// Create a nodes
Node *createNode(int value) {
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
}

int main() {
    printf("Hello World!\n");
}
