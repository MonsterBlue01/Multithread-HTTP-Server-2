#pragma once

typedef struct ListObj* List;

List newList(void);

int length(List L);
int index(List L);

void append(List L, int x);