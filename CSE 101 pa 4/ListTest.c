#include <stdio.h>
#include <stdlib.h>

#include "List.h"

int main() {
    int* temp = (int *)malloc(5 * sizeof(int));
    temp[0] = 1;
    temp[2] = 3;
    temp[4] = 5;
    List new = newList();
    append(new, temp);
    printf("The length: %d\n", length(new));
}