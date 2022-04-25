#include "List.h"
#include "Matrix.h"

#include <string.h>

int main(int argc, char *argv[]) {
    FILE *fp = NULL;
    fp = fopen("input1.sh", "r");
    char buff[16];
    
    int a = 0;
    int b = 0;
    float c = 0;

    int n = 0;
    int NNZ1 = 0;
    int NNZ2 = 0;

    int in = 0;
 
    while(!feof(fp)) { 
        fgets(buff, 16, fp);   
        sscanf(buff, "%d %d %f\n", &a, &b, &c);
        // if (buff[0] == '\n') {
        //     printf("Empty!\n");
        //     in++;
        // }
        printf("m: %d, %d, %f\n", a, b, c);
    }
    fclose(fp);
}