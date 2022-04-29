// -----------------------------
// Name: Dongjing Wang
// CruzID: 1823945
// Assignment: pa4
// -----------------------------

#include <stdio.h>
#include <stdlib.h>

#include "List.h"

int main() {
    int one = -1;
    int two = -2;
    List new = newList();
    append(new, &one);
    append(new, &two);
    printf("The length: %d\n", length(new));
    Node tmp = new->front;
    printf("The number: %d\n", (*((int*)tmp->next->data)));
}
