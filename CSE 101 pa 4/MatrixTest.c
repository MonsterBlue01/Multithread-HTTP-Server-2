#include "List.h"
#include "Matrix.h"

int main() {
    Matrix M = (Matrix)malloc(sizeof(MatrixObj));
    // input = 3;
    M->size = 3;
    M->row = (List *)malloc(3 * sizeof(List));
    for (int i = 0; i < 3; i++) {
        M->row[i] = newList();
    }
    // if (M->row[0]->front == NULL) {
    //     printf("It's NULL\n");
    // }

    int a = 1;
    int b = 2;
    double c = 3.0;
    
    changeEntry(M, 1, 1, 1.0);
    changeEntry(M, 1, 2, 2.0);
    changeEntry(M, 1, 3, 3.0);
    // Entry new = (Entry)malloc(sizeof(EntryObj));
    // new->column = 3;
    // new->num = 3.0;
    // Node tmp = M->row[1]->front;
    // if (tmp == NULL) {
    //     append(M->row[1], new);
    // } else {
    //     if (3 < ((Entry)(M->row[1]->front->data))->column) {
    //         prepend(M->row[1], new);
    //     } else {
    //         moveFront(M->row[1]);
    //         while (index(M->row[1]) >= 0) {
    //             printf("%d\n", (((Entry)(M->row[1]->cursor->data))->column));
    //             moveNext(M->row[1]);
    //         }
    //     }
    // }

    printf("%f\n", (((Entry)(M->row[1]->front->data))->num));
    printf("%f\n", (((Entry)(M->row[1]->front->next->data))->num));
    printf("%f\n", (((Entry)(M->row[1]->front->next->next->data))->num));

    // if (M->row[1]->front != NULL) {
    //     printf("%f\n", ((Entry)(M->row[1]->front->next->data))->num);
    // }
}
