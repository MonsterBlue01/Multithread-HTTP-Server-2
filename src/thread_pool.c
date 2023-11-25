#include "thread_pool.h"
#include "utils.h"

int thread_pool_init(ThreadPool* pool, int num_threads) {
    if (num_threads <= 0) {
        num_threads = 5;
    }

    pool->thread_count = num_threads;
    pool->threads = (pthread_t*)safe_malloc(sizeof(pthread_t) * num_threads);
    pool->task_queue = NULL;
    pool->head = pool->tail = pool->count = 0;
    pool->shutdown = pool->started = 0;

    if (pthread_mutex_init(&(pool->lock), NULL) != 0 ||
        pthread_cond_init(&(pool->notify), NULL) != 0) {
        if (pool->threads) safe_free((void**)&(pool->threads));
        return -1;
    }

    // 创建线程
    for (int i = 0; i < pool->thread_count; i++) {
        if (pthread_create(&(pool->threads[i]), NULL, thread_pool_thread, (void*)pool) != 0) {
            thread_pool_destroy(pool, 0);
            return -1;
        }
        pool->started++;
    }

    return 0;
}

int thread_pool_add(ThreadPool* pool, void (*function)(void*), void* argument) {
    int err = 0;

    if (pool == NULL || function == NULL) {
        return -1;
    }

    if (pthread_mutex_lock(&(pool->lock)) != 0) {
        return -1;
    }

    do {
        if (pool->shutdown) {
            err = -1;
            break;
        }

        Task* task = (Task*)safe_malloc(sizeof(Task));
        task->function = function;
        task->argument = argument;
        task->next = NULL;

        if (pool->task_queue == NULL) {
            pool->task_queue = task;
        } else {
            Task* tmp = pool->task_queue;
            while (tmp->next) {
                tmp = tmp->next;
            }
            tmp->next = task;
        }

        pool->count += 1;

        if (pthread_cond_signal(&(pool->notify)) != 0) {
            err = -1;
            break;
        }
    } while (0);

    if (pthread_mutex_unlock(&pool->lock) != 0) {
        err = -1;
    }

    return err;
}

int thread_pool_destroy(ThreadPool* pool, int gracefull) {
    if (pool == NULL) {
        return -1;
    }

    if (pthread_mutex_lock(&(pool->lock)) != 0) {
        return -1;
    }

    do {
        pool->shutdown = (gracefull) ? THREAD_POOL_SHUTDOWN : 1;

        if ((pthread_cond_broadcast(&(pool->notify)) != 0) ||
            (pthread_mutex_unlock(&(pool->lock)) != 0)) {
            return -1;
        }

        for (int i = 0; i < pool->thread_count; i++) {
            if (pthread_join(pool->threads[i], NULL) != 0) {
                return -1;
            }
        }
    } while (0);

    pthread_mutex_destroy(&(pool->lock));
    pthread_cond_destroy(&(pool->notify));
    safe_free((void**)&(pool->threads));

    return 0;
}

void *thread_pool_thread(void* thread_pool) {
    ThreadPool* pool = (ThreadPool*)thread_pool;
    Task* task;

    while (1) {
        pthread_mutex_lock(&(pool->lock));

        while ((pool->count == 0) && (!pool->shutdown)) {
            pthread_cond_wait(&(pool->notify), &(pool->lock));
        }

        if ((pool->shutdown == THREAD_POOL_SHUTDOWN) ||
            ((pool->shutdown == 1) && (pool->count == 0))) {
            break;
        }

        task = pool->task_queue;
        if (task) {
            pool->task_queue = task->next;
            pool->count -= 1;
        }

        pthread_mutex_unlock(&(pool->lock));

        (*(task->function))(task->argument);
        safe_free((void**)&task);
    }

    pool->started--;

    pthread_mutex_unlock(&(pool->lock));
    pthread_exit(NULL);
    return (NULL);
}
