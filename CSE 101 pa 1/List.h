#pragma once

typedef struct List {
    struct List *next;
    struct List *prev;
    char* number;
} List;

List newList(void);
void freeList(List* pL);