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
    
    changeEntry(M, 1, 2, 2.0);
    changeEntry(M, 1, 3, 3.0);

    if (M->row[1]->front != NULL) {
        printf("%f\n", ((Entry)(M->row[1]->front->next->data))->num);
    }
}
