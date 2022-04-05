#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "List.h"

int main(int argc, char *argv[]) {
    char buffer[1024];
    if(argc != 3) {
        fprintf(stderr, "Error: Fewer or more than two arguments were passed in.\n");
        exit(1);
    }

    FILE *fp;
    fp = fopen(argv[1], "r");
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
    fp1 = fopen(argv[2], "r");
    char* array[file_row];
    int in = 0;

    while (fgets(buffer, sizeof(buffer), fp1) != NULL) {
        array[in] = (char *)malloc(100 * sizeof(char));
        strcpy(array[in++], buffer);
    }

    fclose(fp1);

    List l = newList();

    for (int i = 0; i < file_row - 1; i++) {
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
            if (strcmp(array[i], array[l->cursor->data]) < 0) {
                prepend(l, i);
                continue;
            }
            while (index(l) >= 0) {
                if (l->cursor == l->back) {
                    append(l, i);
                    break;
                }
                if ((strcmp(array[i], array[l->cursor->data]) > 0) && (strcmp(array[i], array[l->cursor->next->data]) < 0)) {
                    insertAfter(l, i);
                    break;
                }
                moveNext(l);
            }
        }
    }

    FILE *fp2 = NULL;
    fp2 = fopen("output.txt", "w+");

    Node new = l->front;
    while (new != l->back) {
        fprintf(fp2, "%s", array[new->data]);
        new = new->next;
        if (new == l->back) {
            fprintf(fp2, "%s", array[new->data]);
        }
    }

    fclose(fp2);

    freeList(&l);
    return 0;
}

//Note: I almost done this project, but I still need to finish the last part - SORTING!!! But I think it's not so hard. I am so tired
//now, so I think I am going to do that later. Buenas noches.