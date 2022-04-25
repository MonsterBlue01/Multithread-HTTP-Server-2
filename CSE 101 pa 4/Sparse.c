#include "List.h"
#include "Matrix.h"

#include <string.h>

int main(int argc, char *argv[]) {
    FILE *fp = NULL;
    FILE *fp1 = NULL;
    fp = fopen("input4.sh", "r");
    fp1 = fopen("output4.sh", "w+");
    char buff[256];
    
    int a = 0;
    int b = 0;
    double c = 0;

    int pa = 0;
    int pb = 0;
    double pc = 0;

    int n = 0;
    int NNZ1 = 0;
    int NNZ2 = 0;

    Matrix A;
    Matrix B;

    int in = 0;
 
    while(!feof(fp)) { 
        fgets(buff, 256, fp);   
        sscanf(buff, "%d %d %lf\n", &a, &b, &c);
        if (buff[0] == '\n') {
            in++;
        }

        if (in == 0) {
            n = a;
            NNZ1 = b;
            NNZ2 = c;

            A = newMatrix(n);
            B = newMatrix(n);
        }

        if (in == 1) {
            if ((a != pa) || (b != pb) || (c != pc)) {
                changeEntry(A, a, b, c);
            }
        }

        if (in == 2) {
            if ((a != pa) || (b != pb) || (c != pc)) {
                changeEntry(B, a, b, c);
            }
        }
        
        pa = a;
        pb = b;
        pc = c;

    }
    fprintf(fp1, "A has %d non-zero entries:\n", NNZ1);
    printMatrix(fp1, A);
    fprintf(fp1, "\n");
    fprintf(fp1, "B has %d non-zero entries:\n", NNZ2);
    printMatrix(fp1, B);
    fprintf(fp1, "\n");
    fprintf(fp1, "(1.5)*A =\n");
    Matrix C = scalarMult(1.5, A);                      //Tips: Double check the A*A and A*B
    printMatrix(fp1, C);
    fprintf(fp1, "\n");
    fprintf(fp1, "A+B =\n");
    makeZero(C);
    C = sum(A, B);
    printMatrix(fp1, C);
    fprintf(fp1, "\n");
    fprintf(fp1, "A+A =\n");
    makeZero(C);
    C = sum(A, A);
    printMatrix(fp1, C);
    fprintf(fp1, "\n");
    fprintf(fp1, "B-A =\n");
    makeZero(C);
    C = diff(B, A);
    printMatrix(fp1, C);
    fprintf(fp1, "\n");
    fprintf(fp1, "A-A =\n");
    fprintf(fp1, "\n");
    fprintf(fp1, "Transpose(A) =\n");
    makeZero(C);
    C = transpose(A);
    printMatrix(fp1, C);
    fprintf(fp1, "\n");
    fprintf(fp1, "A*B =\n");
    makeZero(C);
    C = product(A, B);
    printMatrix(fp1, C);
    fprintf(fp1, "\n");
    fprintf(fp1, "B*B =\n");
    makeZero(C);
    C = product(B, B);
    printMatrix(fp1, C);
    fprintf(fp1, "\n");

    fclose(fp);
    fclose(fp1);
}