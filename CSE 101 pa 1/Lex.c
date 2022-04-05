#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "List.h"

int main(int argc, char *argv[]) {
    char buffer[1024];
    /*if(argc != 3) {
        fprintf(stderr, "Error: Fewer or more than two arguments were passed in.\n");
        exit(1);
    } else {
        printf("Good. \n");
    }*/

    FILE *fp;
    fp = fopen("input.txt", "r");
    int flag = 0, file_row = 0;
    
    if (fp == NULL) { 
        fprintf(stderr, "Error: Attempting to access a file that does not exist.\n"); 
        exit(1); 
    }
    
    while(!feof(fp)) {
        flag = fgetc(fp);
        if(flag == '\n') {
            file_row++;
        }
    }
    file_row++;
    fclose(fp);

    FILE *fp1;
    fp1 = fopen("input.txt", "r");
    char* array[file_row];
    int index = 0;

    while (fgets(buffer, sizeof(buffer), fp1) != NULL) {
        array[index] = (char *)malloc(100 * sizeof(char));
        strcpy(array[index++], buffer);
    }

    fclose(fp1);

    List l = newList();

    for (int i = 0; i < 3/*file_row - 1*/; i++) {
        printf("%s", array[i]);
        if (l->length == 0) {
            append(l, i);
            continue;
        }

        if (l->length == 1) {
            if (strcmp(array[1], array[0]) > 0) {
                append(l, i);
                continue;
            } else {
                prepend(l, i);
                continue;
            }
        }

        if (l->length >= 2) {
            moveFront(l);
            while (l->index >= 0) {
                printf("Example: %d\n", l->cursor->data);
                moveNext(l);
            }
            printf("Example: %d\n", l->back->data);
        }
    }

    printf("%d\n", l->front->data);
    printf("%d\n", l->front->next->data);
    //printf("%d\n", l->front->next->next->data);
    //printf("%d\n", l->front->next->next->next->data);
    //printf("%d\n", l->front->next->next->next->next->data);

    freeList(&l);
    return 0;
}

//Note: I almost done this project, but I still need to finish the last part - SORTING!!! But I think it's not so hard. I am so tired
//now, so I think I am going to do that later. Buenas noches.