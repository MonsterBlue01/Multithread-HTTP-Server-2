#include "utils.h"
#include <stdio.h>

int main() {
    init_logging(stderr);
    set_log_level(DEBUG);

    log_message(INFO, "This is an info message");
    log_message(ERROR, "This is an error message");
    log_message(DEBUG, "This is a debug message");

    int* array = safe_malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++) {
        array[i] = i;
    }

    int* larger_array = safe_realloc(array, 20 * sizeof(int));
    for (int i = 10; i < 20; i++) {
        larger_array[i] = i;
    }

    for (int i = 0; i < 20; i++) {
        printf("%d ", larger_array[i]);
    }
    printf("\n");

    safe_free((void**)&larger_array);
    if (larger_array == NULL) {
        printf("Memory freed successfully\n");
    }

    return 0;
}