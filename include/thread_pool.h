#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <pthread.h>

typedef enum {
    THREAD_POOL_STOPPED,
    THREAD_POOL_RUNNING,
    THREAD_POOL_SHUTDOWN
} ThreadPoolStatus;

typedef struct task {
    void (*function)(void*);
    void* argument;
    struct task* next;
} Task;

typedef struct thread_pool {
    pthread_mutex_t lock;
    pthread_cond_t notify;
    pthread_t* threads;
    Task* task_queue;
    int thread_count;
    int queue_size;
    int head;
    int tail;
    int count;
    int shutdown;
    int started;
} ThreadPool;

int thread_pool_init(ThreadPool* pool, int num_threads);
int thread_pool_add(ThreadPool* pool, void (*function)(void*), void* argument);
int thread_pool_destroy(ThreadPool* pool, int gracefull);
void *thread_pool_thread(void* thread_pool);

#endif