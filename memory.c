#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char command[256];
    char filename[256];
    FILE *file;

    while(1) {
        printf("Enter command: ");
        if (scanf("%s", command) != 1) break;

        if (strcmp(command, "get") == 0) {
            printf("Enter filename: ");
            scanf("%s", filename);
            file = fopen(filename, "r");
            if (file == NULL) {
                printf("File not found: %s\n", filename);
                continue;
            }

            char ch;
            while ((ch = fgetc(file)) != EOF) {
                putchar(ch);
            }
            fclose(file);
        } else if (strcmp(command,"set") == 0) {
            printf("Enter filename: ");
            scanf("%s", filename);
            file = fopen(filename, "w");
            if (file == NULL) {
                printf("Error opening file: %s\n", filename);
                continue;
            }

            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            printf("Enter content (end with CTRL+D): ");
            char buffer[1024];
            while (fgets(buffer, 1024, stdin) != NULL) {
                fprintf(file, "%s", buffer);
            }
            fclose(file);
            printf("OK\n");

            clearerr(stdin);
        } else {
            printf("Unknown command: %s\n", command);
        }
    }

    return 0;
}
