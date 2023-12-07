#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

queue_t *queue_new(int size) {
    queue_t *q = malloc(sizeof(queue_t));
    if (q == NULL) {
        return NULL; //Memory allocation failed
    }
    q->elements = malloc(sizeof(void *) * size);
    if (q->elements == NULL) {
        free(q); // Clean up previously allocated memory
        return NULL;
    }
    q->head = 0;
    q->tail = 0;
    q->maxSize = size;
    pthread_mutex_init(&q->lock, NULL); //Initialize mutex lock
    return q;
}

void queue_delete(queue_t **q) {
    if (q != NULL && *q != NULL) {
        free((*q)->elements);
        pthread_mutex_destroy(&(*q)->lock); // Destroy mutex lock
        free(*q);
        *q = NULL;
    }
}

void queue_push(queue_t *q, void *elem) {
    pthread_mutex_lock(&q->lock);
    if ((q->tail + 1) % q->maxSize == q->head) {
        // Queue is full
        // printf("Queue is full, cannot push new element.\n");
        pthread_mutex_unlock(&q->lock);
        return;
    }
    printf("Pushing element into queue at position %d\n", q->tail);
    q->elements[q->tail] = elem;
    q->tail = (q->tail + 1) % q->maxSize;
    pthread_mutex_unlock(&q->lock);
}

void queue_pop(queue_t *q, void **elem) {
    pthread_mutex_lock(&q->lock);
    if (q->head == q->tail) {
        // Queue is empty
        // printf("Queue is empty, cannot pop element.\n");
        *elem = NULL;
        pthread_mutex_unlock(&q->lock);
        return;
    }
    *elem = q->elements[q->head];
    printf("Popping element from queue at position %d\n", q->head);
    q->head = (q->head + 1) % q->maxSize;
    pthread_mutex_unlock(&q->lock);
}
