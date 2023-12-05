#include <pthread.h>
#include <stdlib.h>

typedef struct queue {
    void **elements;
    int head;
    int tail;
    int maxSize;
    pthread_mutex_t lock;
} queue_t;

queue_t *queue_new(int size) {
    queue_t *q = malloc(sizeof(queue_t));
    if (q == NULL) {
        return NULL; // 内存分配失败
    }
    q->elements = malloc(sizeof(void *) * size);
    if (q->elements == NULL) {
        free(q); // 清理之前分配的内存
        return NULL;
    }
    q->head = 0;
    q->tail = 0;
    q->maxSize = size;
    pthread_mutex_init(&q->lock, NULL); // 初始化互斥锁
    return q;
}

void queue_delete(queue_t **q) {
    if (q != NULL && *q != NULL) {
        free((*q)->elements);
        pthread_mutex_destroy(&(*q)->lock); // 销毁互斥锁
        free(*q);
        *q = NULL;
    }
}

void queue_push(queue_t *q, void *elem) {
    pthread_mutex_lock(&q->lock);
    if ((q->tail + 1) % q->maxSize == q->head) {
        // 队列已满
        return;
    }
    q->elements[q->tail] = elem;
    q->tail = (q->tail + 1) % q->maxSize;
    pthread_mutex_unlock(&q->lock);
}

void queue_pop(queue_t *q, void **elem) {
    pthread_mutex_lock(&q->lock);
    if (q->head == q->tail) {
        // 队列为空
        *elem = NULL;
        return;
    }
    *elem = q->elements[q->head];
    q->head = (q->head + 1) % q->maxSize;
    pthread_mutex_unlock(&q->lock);
}

