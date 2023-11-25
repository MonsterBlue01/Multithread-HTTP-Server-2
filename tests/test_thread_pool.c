#include "thread_pool.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void test_task_function(void* arg) {
    int* task_num = (int*)arg;
    printf("Executing task number %d\n", *task_num);
    sleep(1);
}

void test_thread_pool() {
    ThreadPool pool;

    if (thread_pool_init(&pool, 4) != 0) {
        printf("Failed to initialize thread pool.\n");
        return;
    }

    for (int i = 0; i < 10; i++) {
        int* task_num = (int*)malloc(sizeof(int));
        *task_num = i;
        if (thread_pool_add(&pool, test_task_function, task_num) != 0) {
            printf("Failed to add task to thread pool.\n");
            free(task_num);
        }
    }

    sleep(5);

    if (thread_pool_destroy(&pool, 1) != 0) {
        printf("Failed to destroy thread pool.\n");
    }
}

int main() {
    test_thread_pool();
    return 0;
}
