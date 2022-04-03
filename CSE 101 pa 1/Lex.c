#include <stdio.h>

int main(int argc, char *argv[]) {
    int i;
    if(argc != 3) {
        printf("Error: Fewer or more than two arguments were passed in.\n");
    } else {
        printf("Good. \n");
    }
    return 0;
}