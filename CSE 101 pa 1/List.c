#include <stdio.h>

#include "List.h"

List newList(void) {
    List *new = (List *)malloc(200 * sizeof(List));
    new->next = NULL;
    new->number = "Nothing";
    new->prev = NULL;
    return *new;
}

void freeList(List* pL);

int main() {
    printf("a\n");
}
